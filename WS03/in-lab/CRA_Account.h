/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
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
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H
namespace sict{

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	class CRA_Account {
	private:
		char m_family_name[max_name_length + 1];
		char m_given_name[max_name_length + 1];
		int m_sin; //SIN valid if it is a 9-digit number between these predefined limits
	public:
		//checks if sin is a valid SIN. If valid stores family name, given name, sin.
		void set(const char* familyName, const char* givenName, int sin); 
		// returns true if object does not hold valid sin and false if sin valid
		bool isEmpty() const;
		//if object is not empty, the function inserts into standard output stream, else prints "Account object is empty!"
		void display() const;
	};
};
#endif //SICT_CRA_ACCOUNT_H