// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: SavingsAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the SavingsAccount class
///////////////////////////////////////////////////

#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;
sict::SavingsAccount::SavingsAccount(double balance, double intrate): Account(balance)
{
	//sets interest rate to 0 if the given double is less then 0
	if (intrate > 0.0) {
		setBalance(balance);
		m_interest = intrate;
	}
	else {
		setBalance(balance);
		m_interest = 0.0;
	}
}

void sict::SavingsAccount::monthEnd()
{
	//calculates interestrate and credits intrest
	credit((balance() * m_interest));
}

void sict::SavingsAccount::display(std::ostream & os) const
{
	os << "Account type: Savings" << endl
		<< "Balance: $" << setprecision(2) << fixed << balance() << endl
		<< "Interest Rate (%): " << setprecision(2) << m_interest * 100 << endl;
}
