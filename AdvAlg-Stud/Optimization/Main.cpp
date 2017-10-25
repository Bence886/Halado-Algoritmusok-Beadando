// WorkAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "locale.h"

#include "SmallestBoundaryPolygon.h"
#include "Main.h"
#include "SmallestBoundaryPolygonSolver.h"
#include "TravellingSalesmanSolver.h"

void SmallestBoundaryPolygon_HillClimbingStochastic() {
	SmallestBoundaryPolygonSolver problem;
	problem.loadPointsFromFile("Input\\Points.txt");
	problem.CilmbHill(3, 300);
}

void TravellingSalesman_Genetic()
{
	TravellingSalesmanSolver problem(100, 64);
	problem.loadTownsFromFile("Input\\Towns.txt");
	problem.Travel(100);
}

int main()
{
	//SmallestBoundaryPolygon_HillClimbingStochastic();
	TravellingSalesman_Genetic();

	std::cout << "Done!" << std::endl;
	std::getchar();
    return 0;
}

