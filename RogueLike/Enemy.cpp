#include "Enemy.h"
#include <string>
#include <random>
#include <ctime>

Enemy::Enemy(std::string name, char tile, int level, int attack, int defense, int health, int xp) 
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = xp;

}

//sets position of Enemy
void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

//Get the position of Enemy using reference variable
void Enemy::getPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

int Enemy::attack()
{
	static std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack)
{
	attack -= _defense;
	if (attack > 0) {
		_health -= attack;
		//check if he died
		if (_health <= 0) {
			return _experienceValue;
		}
	}
	
	return 0;
}