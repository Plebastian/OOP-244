#include <iostream>
#include "Hero.h"
#include "SuperHero.h"
using namespace std;
using namespace sict;
SuperHero::SuperHero() : Hero()
{
	m_superPowerAttack = 0;
	m_superPowerDefend = 0;
}


SuperHero::SuperHero(const char* name, int health, int attack,
	int superPowerAttack, int superPowerDefend
) : Hero(name, health, attack)
{
	m_superPowerAttack = superPowerAttack;
	m_superPowerDefend = superPowerDefend;

}



int SuperHero::attackStrength() const
{
	return Hero::attackStrength() + m_superPowerAttack;
}

int sict::SuperHero::defence() const
{
	return m_superPowerDefend;
}

const SuperHero & sict::operator*(const SuperHero & first, const SuperHero & second)
{


	// Display the names of the people fighting

	std::cout << "Super Fight! " << first << " vs " << second << " : Winner is ";
	unsigned int round = 0;

	SuperHero A = first;
	SuperHero B = second;
	const SuperHero *Winner = nullptr;

	// loop while both are still alive
	while (A.isAlive() && B.isAlive() && round < max_round)
	{
		round++;
		A -= (B.attackStrength() - A.defence());
		B -= (A.attackStrength() - B.defence());
	}


	if (A.isAlive())
	{
		Winner = &first;
	}
	else
	{
		Winner = &second;
	}

	std::cout << *Winner << " in " << round << " rounds." << std::endl;
	// TODO: insert return statement here
	return *Winner;

}

