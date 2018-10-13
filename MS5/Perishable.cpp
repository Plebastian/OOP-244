// Final Project Milestone 5
// Version 1.0
// Perishable	
// Author	Sebastian Djurovic
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#include "Perishable.h"
//#include "Date.h"
using namespace std;

sict::Perishable::Perishable() : NonPerishable('P')
{ 
	//pass type to NonPerishable constructor
	//m_expiry.Date::Date();
}
std::fstream & sict::Perishable::store(std::fstream & file, bool newLine) const
{
	NonPerishable::store(file, false);
	file << "," << m_expiry;
	if (newLine) {
		file << endl;
	}
	return file;
}

std::fstream & sict::Perishable::load(std::fstream & file)
{
	NonPerishable::load(file);
	file.ignore(1);
	file >> m_expiry;
	return file;
}

std::ostream & sict::Perishable::write(std::ostream & os, bool linear) const
{
	//NonPerishable::setType('P');
	NonPerishable::write(os, linear);
	if (!m_expiry.bad()) {
		if (linear) {
			os << m_expiry;
		}
		else {
			os << endl << "Expiry date: " << expiry();
		}
	}
	return os;
}

std::istream & sict::Perishable::read(std::istream & is)
{
	setType('P');
	Date temp;
	NonPerishable::read(is);
	if (!is.fail()) {
		if (NonPerishable::isClear()) {
			cout << "Expiry date (YYYY/MM/DD): ";

			temp.Date::read(is);

			if(temp.bad()){
				if (temp.errCode() == CIN_FAILED) {
					message("Invalid Date Entry ");
					is.setstate(ios::failbit);
				}
				if (temp.errCode() == YEAR_ERROR) {
					message("Invalid Year in Date Entry");
					is.setstate(ios::failbit);
				}
				if (temp.errCode() == MON_ERROR) {
					message("Invalid Month in Date Entry");
					is.setstate(ios::failbit);
				}
				if (temp.errCode() == DAY_ERROR) {
					message("Invalid Day in Date Entry");
					is.setstate(ios::failbit);
				}
			}
		}
	}
	m_expiry = temp;
	return is;

}

const sict::Date & sict::Perishable::expiry() const
{
	return m_expiry;
}

sict::Product * sict::CreatePerishable()
{
	Product* d = new Perishable();
	return d;
}
