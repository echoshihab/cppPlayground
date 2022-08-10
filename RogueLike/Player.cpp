#include "Player.h"
#include <random>
#include <ctime>

//Constructor, initialize position to zero

Player::Player() 
{
	_x = 0;
	_y = 0;
}

//initialize the player with properties
void Player::init(int level, int health, int attack, int defense, int experience) 
{
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
	
}

//sets position of player
void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

void Player::addExperience(int experience) 
{
	_experience += experience;

	//Level up!
	while (_experience > 50) {
		printf("Leveled up!\n");
		_experience -= 50;
		_attack += 10;
		_defense += 10;
		_health += 10;
		_level++;
		system("PAUSE");
	}

}

//Get the position of player using reference variable
void Player::getPosition(int& x, int& y)
{
	x = _x;
	y = _y;
}

int Player::attack()
{
	static std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}


int Player::takeDamage(int attack)
{
	attack -= _defense;
	if (attack > 0) {
		_health -= attack;
		//check if he died
		if (_health <= 0) {
			return 1;
		}
	}

	return 0;
}