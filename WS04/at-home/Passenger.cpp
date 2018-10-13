// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
// TODO: add your headers here
#include "Passenger.h"
#include <iostream> 
#include <cstring> 

// TODO: continue your namespace here
using namespace std;
namespace sict {
		// TODO: implement the default constructor here
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_year = 0;
		m_month = 0;
		m_day = 0;
		}
	
		// TODO: implement the constructor with 2 parameters here
		Passenger::Passenger(const char * name, const char * destination)
		{			
			if ( name != nullptr && destination != nullptr && name[0] != '\0' && destination[0] != '\0') {
				strcpy(m_name, name);
				strcpy(m_destination, destination);
				m_year = 2017;
				m_month = 7;
				m_day = 1; 
			}
			else {
				m_name[0] = '\0';
				m_destination[0] = '\0';
				m_year = 0;
				m_month = 0;
				m_day = 0;
			}
		}
		Passenger::Passenger(const char * name, const char * destination, int year, int month, int day)
		{
			/*if (name != nullptr && destination != nullptr && name[0] != '\0' && destination[0] != '\0' && year > 2015 && year < 2022 && month > 1 && month < 13 && day < 0 && day > 32) {
							strcpy(m_name, name);
							strcpy(m_destination, destination);
							m_year = year;
							m_month = month;
							m_day = day;
			}
			else {
				m_name[0] = '\0';
				m_destination[0] = '\0';
				m_year = 0;
				m_month = 0;
				m_day = 0;
			}*/
			if (name == '\0' || strcmp(name, "") == 0 || destination == '\0' || strcmp(destination, "") == 0 || month > 12 || month < 1 || day >31 || day < 1 || year > 2020 || year < 2017) {
				strcpy(m_name, "");
				strcpy(m_destination, "");
				m_day = 0;
				m_month = 0;
				m_year = 0;
			}
			else 
			if (name != nullptr && destination != nullptr){
				strcpy(m_name, name);
				strcpy(m_destination, destination);
				m_day = day;
				m_month = month;
				m_year = year;
			}

		}
		const char * Passenger::name() const
		{
			if (!isEmpty()) {
				return m_name;
			}
		}
		// TODO: implement isEmpty query here
		bool Passenger::isEmpty() const {
			if (m_destination[0] == '\0' && m_name[0] == '\0' && m_year == 0 && m_month == 0 && m_day == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		// TODO: implement display query here
		void Passenger::display() const {
			if (isEmpty()) {
				cout << "No passenger!" << endl;
			}
			else {
				cout << m_name << " - " << m_destination << " on " << m_year << "/";
					if (m_month < 10) { 
						cout << '0' << m_month;
					}
					else {
						cout << m_month;
					}

					cout << "/" << m_day << endl;
			}
		}

		bool Passenger::canTravelWith(const Passenger &p) const
		{
			if (//strcmp(m_name, p.m_name) == 0 &&
				strcmp(m_destination, p.m_destination) == 0 &&
				m_day == p.m_day &&
				m_month == p.m_month &&
				m_year == p.m_year) {
				return true;
			}
			else {
				return false;
			}

		}
	
}