// WorkAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "locale.h"

#include "SmallestBoundaryPolygon.h"
#include "Main.h"
#include "SmallestBoundaryPolygonSolver.h"
#include "TravellingSalesmanSolver.h"
#include "PathFinderSolver.h"

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

void path_finder_generic()
{
	PathFinderSolver path_finder(100, 10);
	path_finder.loadMapFromFile("Input\\Map.txt");
	path_finder.find_path(50);
}

int main()
{
	//SmallestBoundaryPolygon_HillClimbingStochastic();
	//TravellingSalesman_Genetic();

	path_finder_generic();

	std::cout << "Done!" << std::endl;
	std::getchar();
    return 0;
}

