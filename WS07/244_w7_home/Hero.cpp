#include "Hero.h"
#include <iostream>
#include <string.h>
#include <fstream>

sict::Hero::Hero(const char *n, int h, int s)
{ 
	if (n != '\0' || n != nullptr || h > 0 || s >= 0) {	//check
		//assign variables
		strcpy(m_name, n);
		m_health = h;
		m_strength = s;
	}
	else {
		*this = Hero();
	}
}

sict::Hero::Hero()
{
	m_name[0] = '\0';
	m_health = 0;
	m_strength = 0;
}

sict::Hero::~Hero()
{

}

bool sict::Hero::isEmpty() const
{
	if (m_name != '\0' || m_health > 0 || m_strength > 0) {
		return false;
	}
	else {
		return true;
	}
}

void sict::Hero::operator-=(int attack) {
	if (attack > 0) {
		m_health -= attack;
		if (m_health < 0)
			m_health = 0;
	}
}

bool sict::Hero::isAlive() const
{
	if (this->m_health > 0) {
		//is alive
		return true;
	}
	else
	//is dead
	return false;
}

int sict::Hero::attackStrength() const
{
	if (!isEmpty()) {
		return m_strength;
	}
	return 0;
}


namespace sict{
std::ostream & operator<<(std::ostream & os, const Hero & hero)
{
	if (hero.isEmpty()) {
		os << "No hero" << std::endl;
	}
	else {

		os << hero.m_name;
	}
	// TODO: insert return statement here
	return os;
}
}

const sict::Hero & sict::operator*(const Hero & first, const Hero & second)
{
	std::cout << "Ancient Battle! " << first << " vs " << second << " : Winner is ";
	unsigned int round = 0;
	const Hero *Winner = nullptr;
	Hero A = first;
	Hero B = second;
	while (A.isAlive() && B.isAlive() && round < 100) {
		round++;
		A -= B.attackStrength();
		B -= A.attackStrength();
	}
	/*bool draw;
	if (A.isAlive() && B.isAlive()) {
		draw = true;
	}
	else {
		draw = false;
	}
*/
	 if (A.isAlive()){
		Winner = &first;
	}
	else if (B.isAlive()) {
		Winner = &second;
	}
	std::cout << *Winner << " in " << round << " rounds." << std::endl;
	// TODO: insert return statement here
	return *Winner;
}
