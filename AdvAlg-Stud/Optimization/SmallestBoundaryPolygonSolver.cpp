#include <vector>

#include "stdafx.h"
#include "SmallestBoundaryPolygonSolver.h"
#include "../Utils/Random.h"


std::vector<Point*> climbers;

SmallestBoundaryPolygonSolver::SmallestBoundaryPolygonSolver()
{
}

SmallestBoundaryPolygonSolver::~SmallestBoundaryPolygonSolver()
{
}

void SmallestBoundaryPolygonSolver::PlaceClimbers(int num)
{
	for (Point var : points)
	{
		log.Add_Point(var);
	}

	float x = 0, y = 0;
	for (Point var : points)
	{
		x += var.x;
		y += var.y;
	}

	int size = points.size();
	Point mid{ x / size , y / size };
	cout << "Middle point: x:" << mid.x << " y:" << mid.y << endl;
	x = 0;
	for (Point var : points)
	{
		y = std::sqrt((mid.x - var.x)*(mid.x - var.x) + (mid.y - var.y)*(mid.y - var.y));
		if (y > x)
		{
			x = y;
		}
	}
	x += 100;
	cout << "Rad: " << x << endl;
	float &rad = x;

	for (int i = 0; i < num; i++)
	{
		float newX = mid.x + rad * std::sin((360 / num * i)*(PI / 180));
		float newY = mid.y + rad * std::cos((360 / num * i)*(PI / 180));
		Point* pnt = new Point();
		pnt->x = newX;
		pnt->y = newY;

		climbers.push_back(pnt);
		log.Add_C_point(*pnt);
		cout << "Point: " << i << " X: " << pnt->x << " Y: " << pnt->y << endl;
	}
}

void SmallestBoundaryPolygonSolver::CilmbHill(int num, int iter)
{
	PlaceClimbers(num);
	int i = 0;
	std::vector<Point> newPoints;
	while (i++ < iter)
	{
		float length = lengthOfBoundary(ToPointVector(climbers));
		int j = 0;
		for (Point* var : climbers)
		{
			Point* oldPoint = var;
			*var = *NewPoint(*var, 10);
			if (length < lengthOfBoundary(ToPointVector(climbers)))
			{
				var = oldPoint;
			}
			log.Add_Solution(i, j++, *var, length);
		}
	}
	std::cout << std::endl;
}

Point* SmallestBoundaryPolygonSolver::NewPoint(Point var, int range)
{
	Point* returnPoint = new Point();
	returnPoint->x = var.x + randomUniform(-range, range);
	returnPoint->y = var.y + randomUniform(-range, range);
	return returnPoint;
}

std::vector<Point> SmallestBoundaryPolygonSolver::ToPointVector(std::vector<Point*> points)
{
	std::vector<Point> a;
	for (Point* var : points)
	{
		a.push_back(*var);
	}
	return a;
}
