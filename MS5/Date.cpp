// Final Project Milestone 5
// Version 1.0
// Date	
// Author	Sebastian Djurovic
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
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
	  m_day = 0;
	  m_mon = 0;
	  m_year = 0;
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
	 return m_datecompare == rhs.m_datecompare;
  }

  bool Date::operator!=(const Date & rhs) const
  {
	  return m_datecompare != rhs.m_datecompare;;
  }

  bool Date::operator<(const Date & rhs) const
  {
	  return m_datecompare < rhs.m_datecompare;
  }

  bool Date::operator>(const Date & rhs) const
  {
	  return m_datecompare > rhs.m_datecompare;
  }

  bool Date::operator<=(const Date & rhs) const
  {
	  return m_datecompare <= rhs.m_datecompare;
  }

  bool Date::operator>=(const Date & rhs) const
  {
	  return m_datecompare >= rhs.m_datecompare;
  }

  int Date::errCode() const
  {
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
	  if (istr.fail()) {
		  m_error = CIN_FAILED;
	  }
	  else {
		  *this = Date(y, m, d);
		  m_datecompare = m_year * 372 + m_mon * 13 + m_day;
	  }
	  return istr;
  }
  std::ostream & Date::write(std::ostream & ostr) const
  {
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
