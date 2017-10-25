#pragma once
#include <vector>
#include "../Utils/Animlog.h"

class Town
{
public:
	Town(int id) :id(id)
	{}
	Town();
	float x;
	float y;
	int id;
};

class TravellingSalesmanProblem
{
protected:
	std::vector<Town> towns;
	float objective(std::vector<Town> solution);
public:
	TravellingSalesmanProblem();
	void loadTownsFromFile(std::string fileName);
	void saveTownsToFile(std::string fileName, std::vector<Town> townVector);
	void printOutTowns(std::vector<Town> townVector);
};
