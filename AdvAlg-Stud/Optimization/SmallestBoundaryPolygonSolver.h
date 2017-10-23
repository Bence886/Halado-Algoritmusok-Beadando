#pragma once

#include <string>
#include <iostream>
#include "BenceLog.h"

#include "SmallestBoundaryPolygon.h"

class SmallestBoundaryPolygonSolver :public SmallestBoundaryPolygonProblem
{
public:
	SmallestBoundaryPolygonSolver();
	~SmallestBoundaryPolygonSolver();
	BenceLog log;

	void PlaceClimbers(int num);
	void CilmbHill(int num, int iter);
private:
	void NewPoint(float*, float*, int);
	bool pointsInBoundary(int j);
	std::vector<Point> ToPointVector(std::vector<Point*> points);
};