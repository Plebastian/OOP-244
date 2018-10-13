// Final Project Milestone 2
// Version 1.0
// Date	
// Author	Sebastian Pavle Djurovic
//
//
// Revision History
// -----------------------------------------------------------
// Name     Error          Date    2017/12/3             Reason
#ifndef __SICT_ERRORMESSAGE_H
#define __SICT_ERRORMESSAGE_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iostream>
//#include <stdlib.h>
namespace sict {
	class ErrorMessage {
	private:
		char *m_ErrorMessage;
	public:
		//sets error message
		explicit ErrorMessage(const char* errorMessage = nullptr);
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		virtual ~ErrorMessage();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};
	std::ostream & operator<<(std::ostream& ostr, const ErrorMessage& D);
}
#endif // !ERRORMESSAGE_H

