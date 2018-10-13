// TODO: insert header files
#include <iostream>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		num = 0;
		denom = -1;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d) // n: numerator, d: denominator
	{
		if (n >= 0 && d > 0) {
			num = n;
			denom = d;
			reduce();
		}
		else
			denom = -1;              // set to safe empty state
	}
	// TODO: implement the max query
	int Fraction::max() const
	{
		return (num >= denom) ? num : denom;
	}

	
	// TODO: implement the min query
	int Fraction::min() const
		{
			return (num >= denom) ? denom : num;
		}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}



	// TODO: implement the reduce modifier
	void Fraction::reduce()                                         // simplify the Fraction number  
	{
		int tmp = gcd();
		num /= tmp;
		denom /= tmp;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty() == true) {
			cout << "no fraction stored";
		}
		if (denom == 1) {
			cout << num;
		}
		if (denom > 1) {
			cout << num << "/" << denom;
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		if (denom == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	// TODO: implement the + operator
	Fraction  Fraction::operator+(const Fraction rhs) const {
		Fraction lhs; 
		//int num;
		//int denom;
		if (!rhs.isEmpty() && !isEmpty()) {
			lhs.num = (rhs.num * denom) + (num * rhs.denom);
			lhs.denom = rhs.denom * denom;

			//Fraction result(num, denom);
			
		}
		return lhs;
	};
}
