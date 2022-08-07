#pragma once
#include <string>

class Enemy
{
public:
	Enemy(std::string name, char tile, int level, int attack, int defense, int health, int xp);

	//setters
	void setPosition(int x, int y);

	//getters
	void getPosition(int& x, int& y);

private:
	std::string _name;
	char _tile;

	int _level;
	int _attack;
	int _defense;
	int _health;
	int _experienceValue;

	//position
	int _x;
	int _y;

	
};

