#include <vector>

#include "stdafx.h"
#include "SmallestBoundaryPolygonSolver.h"
#include "../Utils/Random.h"


std::vector<Point*> climbers;

SmallestBoundaryPolygonSolver::SmallestBoundaryPolygonSolver(int num, std::string logfilename) : log(logfilename)
{
}

SmallestBoundaryPolygonSolver::~SmallestBoundaryPolygonSolver()
{
}

void SmallestBoundaryPolygonSolver::PlaceClimbers(int num)
{
	float x = 0, y = 0;
	for(Point var : points)
	{
		x += var.x;
		y += var.y;
	}

	int size = points.size();
	Point mid{ x / size , y / size };

	x = 0;
	for(Point var : points)
	{
		y = std::sqrt((mid.x - var.x)*(mid.x - var.x) + (mid.y - var.y)*(mid.y - var.y));
		if (y > x)
		{
			x = y;
		}
	}
	x += 100;

	for (int i = 0; i < num; i++)
	{
		float newX = mid.x + x * std::cos(360 / num * i);
		float newY = mid.y + y * std::sin(360 / num * i);
		Point pnt{ newX, newY };

		climbers.push_back(&pnt);
	}

	printOutPoints(ToPointVector(climbers));
}

void SmallestBoundaryPolygonSolver::CilmbHill(int num, int iter)
{
	PlaceClimbers(num);
	int i = 0;
	std::vector<Point> newPoints;
	while (i++ < iter)
	{
		float length = lengthOfBoundary(ToPointVector(climbers));
		for (Point* var : climbers)
		{
			Point* oldPoint = var;
			var = &NewPoint(*var, 10);

		}
	}
	std::cout << std::endl;
	printOutPoints(ToPointVector(climbers));
}

Point SmallestBoundaryPolygonSolver::NewPoint(Point var, int range)
{
	var.x += randomNormal(-range, range);
	var.y += randomNormal(-range, range);
	return var;
}

std::vector<Point> SmallestBoundaryPolygonSolver::ToPointVector(std::vector<Point*> points)
{
	std::vector<Point> a;
	for (Point* var: points)
	{
		a.push_back(*var);
	}
	return a;
}
