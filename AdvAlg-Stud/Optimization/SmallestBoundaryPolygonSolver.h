#pragma once

#include <string>
#include <iostream>

#include "SmallestBoundaryPolygon.h"

class SmallestBoundaryPolygonSolver :public SmallestBoundaryPolygonProblem
{
public:
	SmallestBoundaryPolygonSolver(int num, std::string log);
	~SmallestBoundaryPolygonSolver();

	Animlog log;

	void PlaceClimbers(int num);
	void CilmbHill(int num, int iter);
private:
	Point NewPoint(Point var, int range);
	std::vector<Point> ToPointVector(std::vector<Point*> points);
};