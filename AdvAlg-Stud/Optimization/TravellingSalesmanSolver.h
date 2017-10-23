#pragma once

#include "TravellingSalesman.h"

class TravellingSalesmanSolver :public TravellingSalesmanProblem
{
public:
	std::vector< std::vector<Town> > agents;

	TravellingSalesmanSolver(int population, int iter);
	~TravellingSalesmanSolver();
	void Travel(int iter);
	void CalcFitnesses(float* fitnesses);
	float Fitness(std::vector<Town> agent);
	void Mate(int from, std::vector< std::vector<Town> > *newAgents);
	void InitPopulation();
	Town GetRandomTown(std::vector<Town> agent);
	bool ContainsTown(Town newTown, std::vector<Town> agent);
	Town RandomTown();
private:
};