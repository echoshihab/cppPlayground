#pragma once
class Enemy
{
public:
	Enemy(std::string name, char tile, int level, int attack, int defense, int health, int xp);

private:
	std::string _name;
	char _tile;

	int _level;
	int _attack;
	int _defense;
	int _health;
	int _experienceValue;

	
};

