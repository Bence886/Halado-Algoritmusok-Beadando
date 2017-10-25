#include "stdafx.h"
#include "BenceLog.h"



void BenceLog::Add_C_point(Point p)
{
	c_points << p.x << '\t' << p.y << endl;
}

void BenceLog::Add_Point(Point p)
{
	Points << p.x << '\t' << p.y << endl;
}

void BenceLog::Add_Solution(int iter, int id, Point p, float length)
{
	Solution << iter << '\t' << id << '\t' << p.x << '\t' << p.y << '\t' << length << endl;
}

void BenceLog::Add_C_point(Town p)
{
	c_points << p.x << '\t' << p.y << endl;
}

void BenceLog::Add_Point(Town p)
{
	Points << p.x << '\t' << p.y << endl;
}

void BenceLog::AddIteration(int distance, int iteration)
{
	Solution << "#" << distance << "#" << iteration << endl;
}

void BenceLog::Add_Solution(Town p)
{
	Solution << p.id << '\t' << p.x << '\t' << p.y << '\t' << endl;
}
