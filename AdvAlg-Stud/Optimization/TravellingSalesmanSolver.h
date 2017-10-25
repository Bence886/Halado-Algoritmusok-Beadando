#pragma once

#include "TravellingSalesman.h"
#include "BenceLog.h"

class TravellingSalesmanSolver :public TravellingSalesmanProblem
{
public:
	std::vector< std::vector<Town> > agents;

	BenceLog log;

	TravellingSalesmanSolver(int population, int iter);
	~TravellingSalesmanSolver();
	void Travel(int iter);
	void CalcFitnesses(float* fitnesses);
	float Fitness(std::vector<Town> agent);
	void Mate(int from, std::vector< std::vector<Town> > *newAgents);
	void SelectTopN(int from, std::vector< std::vector<Town> > *newAgents, float * fitnesses);
	void Cross(std::vector<Town> a, std::vector<Town> b, std::vector<Town> *out, std::vector<Town> *out2);
	void InitPopulation();
	void Mutate(std::vector<Town> *a);
	Town GetRandomTown(std::vector<Town> agent);
	bool ContainsTown(Town newTown, std::vector<Town> agent);
	Town RandomTown();
private:
};