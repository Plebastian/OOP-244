// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_DATE_H
#define SICT_DATE_H
#define NO_ERROR 0 //No error - the date is valid
#define CIN_FAILED 1 //istream failed on information entry
#define YEAR_ERROR 2 //Year value is invalid
#define MON_ERROR 3 //Month value is invalid
#define DAY_ERROR 4 //Day value is invalid
#include <fstream>
namespace sict {
	int const min_year = 2000;
	int const max_year = 2030;
  class Date {
	  int m_day;
	  int m_mon;
	  int m_year;
	  int m_error;
	  int m_datecompare;
     int mdays(int, int)const;
	 void errCode(int errorCode);
  public:
	  Date();
	  Date(int y, int m, int d);
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  //Queries and modifier
	  int errCode() const;
	  bool bad() const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr) const;
  };
  std::istream & operator>>(std::istream& istr, Date& D);
  std::ostream & operator<<(std::ostream& ostr, const Date& D);




}
#endif