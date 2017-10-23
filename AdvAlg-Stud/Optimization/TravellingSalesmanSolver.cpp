#include "stdafx.h"

#include <iostream>

#include "TravellingSalesmanSolver.h"
#include "../Utils/Random.h"

TravellingSalesmanSolver::TravellingSalesmanSolver(int population, int towns) : agents(population, std::vector<Town>(towns))
{
}

TravellingSalesmanSolver::~TravellingSalesmanSolver()
{
}

void TravellingSalesmanSolver::Travel(int iter)
{
	float * fitnesses = new float[agents.size()];
	InitPopulation();
	for (int i = 0; i < iter; i++)
	{
		CalcFitnesses(fitnesses);
		std::vector< std::vector<Town> > newAgents(agents.size(), std::vector<Town>(towns.size()));
		Mate(10, &newAgents);
		agents = newAgents;
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
