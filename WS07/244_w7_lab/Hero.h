#pragma once
#include <fstream>
#ifndef HERO_H
#define HERO_H
namespace sict{
	int const max_round = 100;
	class Hero {
	private:
		char m_name[40];
		int m_health;
		int m_strength;
	public:
		Hero(const char*, int, int );
		Hero();
		~Hero();
		bool isEmpty() const;
		void operator -= (int attack);
		bool isAlive() const; //checks if hero has enough health
		int attackStrength() const; // returns the attack strength of the current object, or object is set to safe empty state
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
		
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif // !HERO_H
