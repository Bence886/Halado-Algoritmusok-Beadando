#pragma once

#include <string>
#include <iostream>

#include "SmallestBoundaryPolygon.h"

class SmallestBoundaryPolygonSolver :public SmallestBoundaryPolygonProblem
{
public:
	SmallestBoundaryPolygonSolver(int num, std::string log);
	~SmallestBoundaryPolygonSolver();

	void PlaceClimbers(int num);
};