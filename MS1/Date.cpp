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
#include "Date.h"
#include <iomanip>
#include <iostream>

namespace sict {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

  void Date::errCode(int errorCode)
  {
	  m_error = errorCode;
  }

  Date::Date()
  {
	  //set to safe empty state
	  m_day = 0;
	  m_mon = 0;
	  m_year = 0;
	  //set error code to safe
	  m_error = NO_ERROR;

  }

  Date::Date(int y, int m, int d)
  {
	  *this = Date();
	  if (y < min_year || y > max_year) {
		  m_error = YEAR_ERROR;
	  }
	  else if(m < 1 || m > 12) {
		  m_error = MON_ERROR;
	  }
	  else if (d < 1 ||d > mdays(m, y)) {
		  m_error = DAY_ERROR;
	  }
	  else {
		  m_error = NO_ERROR;
		  m_year = y;
		  m_mon = m;
		  m_day = d;
		  m_datecompare = m_year * 372 + m_mon * 13 + m_day;
	  }
  }

  bool Date::operator==(const Date & rhs) const
  {
	 return this->m_datecompare == rhs.m_datecompare;
  }

  bool Date::operator!=(const Date & rhs) const
  {
	  return this->m_datecompare != rhs.m_datecompare;;
  }

  bool Date::operator<(const Date & rhs) const
  {
	  return this->m_datecompare < rhs.m_datecompare;
  }

  bool Date::operator>(const Date & rhs) const
  {
	  return this->m_datecompare > rhs.m_datecompare;
  }

  bool Date::operator<=(const Date & rhs) const
  {
	  return this->m_datecompare <= rhs.m_datecompare;
  }

  bool Date::operator>=(const Date & rhs) const
  {
	  return this->m_datecompare >= rhs.m_datecompare;
  }

  int Date::errCode() const
  {
	  //return the error state
	  return m_error;
  }

  bool Date::bad() const
  {
	  if (m_error == NO_ERROR) {
		  return false;
	  }
	  else
		  return true;
	  
  }
  std::istream & Date::read(std::istream & istr)
  {
	  int y = 0;
	  int m = 0;
	  int d = 0;
	  char c1;
	  char c2;
	  istr >> y >> c1 >> m >> c2 >> d;
	  if (istr.fail()) {//|| c1 != '-' || c1 != '/' || c2 != '-' || c2 != '/') {
		  m_error = CIN_FAILED;
	  }
	  else {
		  *this = Date(y, m, d);
		  m_datecompare = m_year * 372 + m_mon * 13 + m_day;
	  }
	  //std::cout << std::setfill('0') << std::setw(4) << m_year << "/" << std::setfill('0') << std::setw(2) << m_mon << "/" << std::setfill('0') << std::setw(2) << m_day << "::" << m_error << std::endl;
	  // TODO: insert return statement here
	  return istr;
  }
  std::ostream & Date::write(std::ostream & ostr) const
  {
	  // TODO: insert return statement here
	  // 0000/00/00
	  
	  //return ostr << std::setfill('0') << std::setw(4) << 
	  return ostr << m_year << "/" << std::setfill('0') << std::setw(2) << m_mon << "/" << std::setfill('0') << std::setw(2) << m_day;
  }
  std::istream & operator>>(std::istream& istr, Date& D)
  {
	  return  D.read(istr);
  }

  std::ostream & operator<<(std::ostream& ostr, const Date& D)
  {

	  return  D.write(ostr);
  }



}
