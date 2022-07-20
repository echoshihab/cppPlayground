#pragma once
class Player
{
public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	//setters
	void setPosition(int x, int y);

	//getters
	void getPosition(int& x, int& y);

private:
	//Properties
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _experience;

	//position
	int _x;
	int _y;
	
};

