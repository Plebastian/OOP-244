// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Allocator.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file allocates an Account object in dynamic memory
///////////////////////////////////////////////////
#include "Account.h"
#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	


	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* type, double balance) {
		if (type[0] == 'S') {
			SavingsAccount* Savings = new SavingsAccount(balance);
			return Savings;
		}
		else {
			return nullptr;
		}
	};






}
