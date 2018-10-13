// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"
#include <iomanip>
#include <iostream>
using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double b, double tf, double mf)//:Account(b)
	{
		setBalance(b);
		if (tf < 0) tf = 0.0;
		if (mf < 0) mf = 0.0;
		m_tranFee = tf;
		m_monthFee = mf;
		//debit(m_tranFee);
	}

	

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double c)
	{
		if (c > 0) {
			bool temp = Account::credit(c);
			if (temp) {
				temp = Account::debit(0.5);
				//std::cout << " 1 " << balance() << endl; 
				return temp;
			}
		}
			return false;
	}




	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double d) {
		if (d > 0) {
			bool temp = Account::debit(d);
			if (temp) {
				temp = Account::debit(m_tranFee);
				//std::cout << " 1 " << balance() << endl;  
				return temp;
			}
		}
		return false;
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		Account::debit(m_tranFee);
		Account::debit(m_monthFee);
	}

	


	// display inserts account information into ostream os
	//
void ChequingAccount::display(std::ostream & os) const
	{
	os << "Account type: Chequing" << endl;
	os << "Balance: $" << setprecision(2) << fixed << balance() << endl
		<< "Per Transaction Fee: " << setprecision(2) << m_tranFee << endl
		<< "Monthly Fee: " << setprecision(2) << m_monthFee << endl;
	}



	

}