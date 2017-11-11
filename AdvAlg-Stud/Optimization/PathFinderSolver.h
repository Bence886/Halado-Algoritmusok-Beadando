#pragma once
#include "PathFinding.h"

class PathFinderSolver : public PathFindingProgrammingProblem
{
public:
	PathFinderSolver(int population, int code_length);
	~PathFinderSolver();
	void find_path(int iters);

	std::vector<std::vector<int>> m_my_machine_code;

private:
	void generate_init_population();
	void sort();
	void mate(int from);
	bool contains(std::vector<int> heads, int gene);
	void mutate();
};