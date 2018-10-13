// TODO: header file guard
#ifndef SICT_Fraction_H__
#define SICT_Fraction_H__

// TODO: create namespace
using namespace std;

namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int num;
		int denom;
		// TODO: declare private member functions
		int gcd() const;
		int min() const;
		int max() const;
		void reduce();
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int n, int d);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction rhs) const;

	};
}

#endif //!SICT_Fraction_H__