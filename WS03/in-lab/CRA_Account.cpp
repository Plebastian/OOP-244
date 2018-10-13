/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Version 2.0
// 09/27/2017
// Sebastian Djurovic
// Description
// This workshop demonstrates classes in C++ and 
// how member variables are defined privately, but 
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
///////////////////////////////////////////////////////////
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;
namespace sict{
		//checks if sin is a valid SIN. If valid stores family name, given name, sin.
		void CRA_Account::set(const char* familyName, const char* givenName, int sin){
			if (isEmpty()){
				strcpy (m_family_name, familyName);
				strcpy (m_given_name, givenName);
				m_sin = sin;
				}
			else {
				m_sin = 0;
				m_given_name[0] = '\0';
				m_family_name[0] = '\0';
			}
		} 
		// returns true if object does not hold valid sin and false if sin valid
		bool CRA_Account::isEmpty() const{
			if (m_sin < max_sin && m_sin > min_sin){
				return false;
			}
			else 
				return true;
		}
		//if object is not empty, the function inserts into standard output stream, else prints "Account object is empty!"
		void CRA_Account::display() const{
			if (isEmpty() == false) {
				cout << "Family Name: " << m_family_name << endl;
				cout << "Given Name : " << m_given_name << endl;
				cout << "CRA Account: " << m_sin << endl;
			}
			else 
				cout << "Account object is empty!" << endl;
		}

};
