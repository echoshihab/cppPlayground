#include "Level.h"
#include <fstream>

Level::Level()
{

}

void Level::load(std::string fileName) 
{
	std::ifstream file;
	file.open(fileName);
	if (file.fail()) {
	std:perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}
	std::string line;

	while (std::getline(file, line)) {
		_levelData.push_back(line);
	}

	file.close();
}

void Level::print()
{
	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}