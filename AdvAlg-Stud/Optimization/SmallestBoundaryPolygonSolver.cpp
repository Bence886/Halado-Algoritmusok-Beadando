#include <vector>

#include "stdafx.h"
#include "SmallestBoundaryPolygonSolver.h"


std::vector<Point> climbers;

SmallestBoundaryPolygonSolver::SmallestBoundaryPolygonSolver(int num, std::string log)
{
}

SmallestBoundaryPolygonSolver::~SmallestBoundaryPolygonSolver()
{
}

void SmallestBoundaryPolygonSolver::PlaceClimbers(int num)
{
	float x = 0, y = 0;
	for each (Point var in points)
	{
		x += var.x;
		y += var.y;
	}

	int size = points.size();
	Point mid{ x / size , y / size };

	x = 0;
	for each (Point var in points)
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
		float newY = mid.y + y * std::cos(360 / num * i);
		Point pnt{ newX, newY };

		climbers.push_back(pnt);
	}

	printOutPoints(climbers);
}
