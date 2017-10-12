// WorkAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

#include "SmallestBoundaryPolygon.h"
#include "Main.h"
#include "SmallestBoundaryPolygonSolver.h"

void SmallestBoundaryPolygon_HillClimbingStochastic() {
	SmallestBoundaryPolygonSolver problem(10, "Log\\SmallestBoundaryPolygon_HillClimbingStochastic.log");
	problem.loadPointsFromFile("Input\\Points.txt");
	std::cout << "Init Climbers" << std::endl;
	problem.CilmbHill(10, 100);
	//HillClimbingStochastic hcs(problem, 5.0f, 0.0001f, 1000);
	//hcs.optimize();
}

int main()
{
	SmallestBoundaryPolygon_HillClimbingStochastic();

	std::getchar();
    return 0;
}

