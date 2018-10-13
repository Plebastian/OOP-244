// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the Account class
///////////////////////////////////////////////////

#include "Account.h"
//constructor receives either a double holding a initial balance or nothing
sict::Account::Account(double balance) {
	if (balance <= 0.0) {
		m_balance = 0.0;
	}
	else {
		m_balance = balance;
	}
}
//adds amount from balance
bool sict::Account::credit(double credit) {
	if (credit > 0) {
		m_balance += credit;
		return true;
	}
	return false;
}
//subtracts amount from balance
bool sict::Account::debit(double debit) {
	if (debit > 0) {
		m_balance -= debit;
		return true;
	}
	return false;
}
void sict::Account::setBalance(double b)
{
	m_balance = b;
}
//return balance of the account
double sict::Account::balance() const
{
	return m_balance;
}

void sict::Account::display(std::ostream &) const 
{
	return;
}
