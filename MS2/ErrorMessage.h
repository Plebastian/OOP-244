// Final Project Milestone 2
// Version 1.0
// Date	
// Author	Sebastian Pavle Djurovic
//
//
// Revision History
// -----------------------------------------------------------
// Name     Error          Date    2017/12/3             Reason
#ifndef ERRORMESSAGE_H
#define ERRORMESSAGE_H
#include <fstream>
namespace sict {
	class ErrorMessage {
	private:
		char *m_ErrorMessage;
	public:
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

