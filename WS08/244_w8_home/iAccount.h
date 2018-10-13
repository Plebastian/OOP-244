// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: iAccount.h
// Version: 2.0
// Date: 2017/13/11
// Author: Sebastian Djurovic
// Description:
// This file defines the Account class
///////////////////////////////////////////////////

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__
#include <fstream>
namespace sict{
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		
	};
	iAccount* CreateAccount(const char*, double);
}

#endif 
