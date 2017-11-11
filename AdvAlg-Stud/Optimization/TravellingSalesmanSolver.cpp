#include "stdafx.h"

#include <iostream>

#include "TravellingSalesmanSolver.h"
#include "../Utils/Random.h"

#define TEN 10

TravellingSalesmanSolver::TravellingSalesmanSolver(int population, int towns) : agents(population, std::vector<Town>(towns))
{}

TravellingSalesmanSolver::~TravellingSalesmanSolver()
{}

void TravellingSalesmanSolver::Travel(int iter)
{

	for (int i = 0; i < towns.size(); i++)
	{
		log.Add_C_point(towns[i]);
	}

	float * fitnesses = new float[agents.size()];
	InitPopulation();
	for (int i = 0; i < iter; i++)
	{
		log.AddIteration(Fitness(agents[0]), i);
		for (int k = 0; k < towns.size(); k++)
		{
			log.Add_Solution(agents[0][k]);
		}

		CalcFitnesses(fitnesses);
		std::vector< std::vector<Town> > newAgents(agents.size(), std::vector<Town>(towns.size()));
		SelectTopN(TEN, &newAgents, fitnesses);
		Mate(TEN, &newAgents);
		for (int k = 0; k < agents.size() - TEN; k++)
		{
			Mutate(&newAgents[randomUniform(TEN, agents.size() - 1)]);
		}
		agents = newAgents;
		std::cout << "iteration: " << i << std::endl;
	}

	delete(fitnesses);
}

void TravellingSalesmanSolver::CalcFitnesses(float * fitnesses)
{
	for (int i = 0; i < agents.size(); i++)
	{
		fitnesses[i] = Fitness(agents[i]);
		//std::cout << fitnesses[i] << std::endl;
	}
}

float TravellingSalesmanSolver::Fitness(std::vector<Town> agent)
{
	float f = 0.0f;

	for (int i = 0; i < agent.size() - 1; i++)
	{
		f += std::sqrt((agent[i].x - agent[i + 1].x)*(agent[i].x - agent[i + 1].x) + (agent[i].y - agent[i + 1].y)*(agent[i].y - agent[i + 1].y));
	}

	return f;
}

void TravellingSalesmanSolver::Mate(int from, std::vector< std::vector<Town> > *newAgents)
{
	for (int i = from; i < agents.size(); i += 2)
	{
		Cross((*newAgents)[randomUniform(0, from - 2)], (*newAgents)[randomUniform(0, from - 2)], &(*newAgents)[i]);
	}
}

void TravellingSalesmanSolver::SelectTopN(int from, std::vector<std::vector<Town>>* newAgents, float* fitnesses)
{
	int * topfitness = new int[from];
	for (int i = 0; i < from; i++)
	{
		int j = 0;
		topfitness[i] = 0;
		while (j < (*newAgents).size() - 1)
		{
			if (fitnesses[topfitness[i]] > fitnesses[j] && fitnesses[j] != -1)
			{
				topfitness[i] = j;
			}
			j++;
		}
		//std::cout << i << " " << topfitness[i] << " " << fitnesses[topfitness[i]] << std::endl;
		fitnesses[topfitness[i]] = -1;
	}

	for (int i = 0; i < from; i++)
	{
		(*newAgents)[i] = agents[topfitness[i]];
	}
	delete(topfitness);
}

void TravellingSalesmanSolver::Cross(std::vector<Town> a, std::vector<Town> b, std::vector<Town> *out)
{
	int size = towns.size();
	int random = randomUniform(0, size - TEN);
	int random2 = randomUniform(0, TEN);
	int j = 0;
	for (int i = random; i < (random + random2); i++)
	{
		(*out)[j++] = a[i];
	}
	for (int i = 0; i < size; i++)
	{
		if (!ContainsTown(b[i], *out))
		{
			(*out)[j++] = b[i];
		}
	}
}

void TravellingSalesmanSolver::InitPopulation()
{
	int townSize = towns.size();
	int poplationSize = agents.size();
	for (int i = 0; i < poplationSize; i++)
	{
		for (int j = 0; j < townSize; j++)
		{
			agents[i][j] = GetRandomTown(agents[i]);
			//std::cout << i << " " << j << " X:" << agents[i][j].x << " Y: " << agents[i][j].y << std::endl;
		}
	}
}

void TravellingSalesmanSolver::Mutate(std::vector<Town> *a)
{
	for (int i = 0; i < (*a).size(); i++)
	{
		for (int j = 0; j < (*a).size() - 1; j++)
		{
			int r1 = randomUniform(j, (*a).size() - 2);
			int r2 = randomUniform(j, (*a).size() - 2);
			Town temp = (*a)[r1];
			(*a)[r1] = (*a)[r2];
			(*a)[r2] = temp;
		}
	}
}

Town TravellingSalesmanSolver::GetRandomTown(std::vector<Town> agent)
{
	Town newTown = RandomTown();
	while (ContainsTown(newTown, agent))
	{
		newTown = RandomTown();
	}
	return newTown;
}

bool TravellingSalesmanSolver::ContainsTown(Town newTown, std::vector<Town> agent)
{
	for (int i = 0; i < agent.size(); i++)
	{
		if (agent[i].x == newTown.x && agent[i].y == newTown.y)
		{
			return true;
		}
	}
	return false;
}

Town TravellingSalesmanSolver::RandomTown()
{
	return towns[randomUniform(0, towns.size() - 1)];
}
