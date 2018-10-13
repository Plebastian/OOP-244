#pragma once
#ifndef SICT_SUPPERHERO_H__
#define SICT_SUPPERHERO_H__
#include <fstream>
namespace sict {
	class SuperHero : public Hero {
		int m_superPowerAttack;
		int m_superPowerDefend;

	public:

		// constructors  
		SuperHero();
		SuperHero(const char* name,
			int health,
			int attack,
			// the following 2 parameters are special for SuperHeros
			int superPowerAttack,
			int superPowerDefend);

		int attackStrength() const;
		int defence() const;

	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_SUPERHERO_H__