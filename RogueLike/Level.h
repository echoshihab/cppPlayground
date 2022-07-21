#pragma once
#include <vector>
#include <string>

class Level
{
public: 
	Level();
	void load(std::string fileName);
	void print();
private:
	std::vector<std::string> _levelData;
};

