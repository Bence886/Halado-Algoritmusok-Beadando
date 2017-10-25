#include <vector>

#include "stdafx.h"
#include "SmallestBoundaryPolygonSolver.h"
#include "../Utils/Random.h"


std::vector<Point> climbers;

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
	x += 500;
	cout << "Rad: " << x << endl;
	float &rad = x;

	for (int i = 0; i < num; i++)
	{
		float newX = mid.x + rad * std::sin((360 / num * i)*(PI / 180));
		float newY = mid.y + rad * std::cos((360 / num * i)*(PI / 180));
		Point* pnt = new Point();
		pnt->x = newX;
		pnt->y = newY;

		climbers.push_back(*pnt);
		log.Add_C_point(*pnt);
		cout << "Point: " << i << " X: " << pnt->x << " Y: " << pnt->y << endl;
	}
}

void SmallestBoundaryPolygonSolver::CilmbHill(int num, int iter)
{
	PlaceClimbers(num);
	int i = 0;
	float oldX, oldY, length;
	while (i++ < iter)
	{
		for (int j = 0; j < climbers.size(); j++)
		{
			length = lengthOfBoundary(climbers);
			oldX = climbers[j].x;
			oldY = climbers[j].y;
			NewPoint(&climbers[j].x, &climbers[j].y, 30);
			if (length < lengthOfBoundary(climbers) || outerDistanceToBoundary(climbers) > 0)
			{
				climbers[j].x = oldX;
				climbers[j].y = oldY;
			}
			log.Add_Solution(i, j, climbers[j], length);
		}
	}
	std::cout << std::endl;
}

bool SmallestBoundaryPolygonSolver::pointsInBoundary(int j)
{
	for (int i = 0; i < points.size(); i++)
	{
		if (distanceFromLine(climbers[j], climbers[(j + 1) % climbers.size()], points[i]) < 0)
		{
			return false;
		}
	}
	return true;
}

void SmallestBoundaryPolygonSolver::NewPoint(float *x, float *y, int range)
{
	*x += randomUniform(-range, range);
	*y += randomUniform(-range, range);
}
