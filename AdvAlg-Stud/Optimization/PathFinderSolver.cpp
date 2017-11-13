#include "stdafx.h"
#include "PathFinderSolver.h"
#include "../Utils/Random.h"

PathFinderSolver::PathFinderSolver(int population, int code_length) : m_my_machine_code(population, std::vector<int>(code_length))
{
}

PathFinderSolver::~PathFinderSolver()
{
}

void PathFinderSolver::find_path(int iters)
{
	generate_init_population();
	for (int k = 0; k < iters; k++)
	{
		sort();
		mate(10, 50);
		mutate();
		std::cout << k << " " << objective(m_my_machine_code[0]) << std::endl;
	}
	logExecution(m_my_machine_code[0], "logFile.txt");
}

void PathFinderSolver::generate_init_population()
{
	for (int i = 0; i < m_my_machine_code.size(); i++)
	{
		for (int j = 0; j < m_my_machine_code[i].size(); j++)
		{
			m_my_machine_code[i][j] = randomUniform(1, max_instruction_code-1);
		}
	}
}

void PathFinderSolver::sort()
{
	std::vector<int> temp(m_my_machine_code.size());
	for (int i = 0; i < m_my_machine_code.size(); i++)
	{
		for (int j = i; j < m_my_machine_code.size(); j++)
		{
			if (objective(m_my_machine_code[i]) > objective(m_my_machine_code[j]))
			{
				temp = m_my_machine_code[i];
				m_my_machine_code[i] = m_my_machine_code[j];
				m_my_machine_code[j] = temp;
			}
		}
	}
}

void PathFinderSolver::mate(int from, int maxNum)
{
	int random1;
	int random2;
	for (int i = from; i < m_my_machine_code.size() / 2; i++)
	{
		random1 = randomUniform(0, m_my_machine_code.size() - maxNum);
		random2 = randomUniform(0, maxNum);
		for (int j = random1; j < m_my_machine_code[i].size(); j++)
		{
			m_my_machine_code[i][j] = m_my_machine_code[random2][j];
		}
		random2 = randomUniform(0, maxNum);
		int k = 0;
		for (int j = 0; j < m_my_machine_code[i].size(); j++)
		{
			if (!contains(m_my_machine_code[i], m_my_machine_code[random2][j]))
			{
				m_my_machine_code[i][k++] = m_my_machine_code[random2][j];
			}
		}
	}
}

bool PathFinderSolver::contains(std::vector<int> heads, int gene)
{
	for (int i = 0; i < heads.size(); i++)
	{
		if (heads[i] == gene)
		{
			return true;
		}
	}
	return false;
}

void PathFinderSolver::mutate()
{
	for (int i = 50; i < m_my_machine_code.size(); i++)
	{
		int random1;
		for (int j = 0; j < 5; j++)
		{
			random1 = randomUniform(0, m_my_machine_code[i].size()-1);
			m_my_machine_code[i][random1] = randomUniform(0, max_instruction_code - 1);
		}
	}
}
