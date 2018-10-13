// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: Account.h
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file defines the Account class
///////////////////////////////////////////////////

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
	const double INTRATE = 0.05;
	const double tranFee = 0.50;
	const double monthlyFee = 2.00;
	class Account : public iAccount {
		double m_balance;
	protected:
		
	public:
		bool credit(double);
		bool debit(double);
		void setBalance(double);
		double balance() const;
		void display(std::ostream&) const;
		Account(double = 0.0);
		
	};
}
#endif
