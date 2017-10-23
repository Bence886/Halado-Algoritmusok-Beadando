#include "stdafx.h"

#include <iostream>

#include "TravellingSalesmanSolver.h"
#include "../Utils/Random.h"

#define TEN 10

TravellingSalesmanSolver::TravellingSalesmanSolver(int population, int towns) : agents(population, std::vector<Town>(towns))
{
}

TravellingSalesmanSolver::~TravellingSalesmanSolver()
{
}

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
		CalcFitnesses(fitnesses);
		std::vector< std::vector<Town> > newAgents(agents.size(), std::vector<Town>(towns.size()));
		SelectTopN(TEN, &newAgents, fitnesses);
		Mate(TEN, &newAgents);
		agents = newAgents;
		for (int j = 0; j < towns.size(); j++)
		{
			log.Add_Solution(i, j, agents[0][j], fitnesses[0]);
		}
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
	float f=0.0f;

	for (int  i = 0; i < agent.size()-1; i++)
	{
		f += std::sqrt((agent[i].x - agent[i+1].x)*(agent[i].x - agent[i + 1].x)+(agent[i].y - agent[i + 1].y)*(agent[i].y - agent[i + 1].y));
	}

	return f;
}

void TravellingSalesmanSolver::Mate(int from,std::vector< std::vector<Town> > *newAgents)
{
	for (int i = from; i < agents.size(); i++)
	{
		Cross(&(*newAgents)[randomUniform(0, from-2)], &(*newAgents)[randomUniform(0, from - 2)]);
	}
}

void TravellingSalesmanSolver::SelectTopN(int from, std::vector<std::vector<Town>>* newAgents, float* fitnesses)
{
	int * topfitness = new int[from];
	for (int i = 0; i < from; i++)
	{
		int j = 0;
		topfitness[i] = 0;
		while (j < (*newAgents).size()-1)
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

void TravellingSalesmanSolver::Cross(std::vector<Town> *a, std::vector<Town>* b)
{
	int size = towns.size();
	int random = randomUniform(0, size-TEN);
	int random2 = randomUniform(0, TEN);
	for (int i = random; i < (random+random2); i++)
	{
		Town temp = (*a)[i];
		(*a)[i] = (*b)[i];
		(*b)[i] = temp;
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
	return towns[randomUniform(0, towns.size()-1)];
}
