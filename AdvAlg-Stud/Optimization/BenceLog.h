#pragma once

#include "stdafx.h"
#include "SmallestBoundaryPolygon.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BenceLog {
public:
	ofstream c_points;
	ofstream Points;
	ofstream Solution;
	
	BenceLog() :
		c_points("c_points.txt"),
		Points("Points.txt"),
		Solution("Solution.txt")
	{};
	~BenceLog()
	{
		c_points.close();
		Points.close();
		Solution.close();
	}

	void Add_C_point(Point p);
	void Add_Point(Point p);
	void Add_Solution(int iter, int id, Point p, float length);
};