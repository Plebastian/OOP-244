// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
// TODO: add your headers here
#include "Passenger.h"
#include <iostream> 
#include <cstring> 
//jkjkjkjkjkjkjkj


// TODO: continue your namespace here
using namespace std;
namespace sict {
		// TODO: implement the default constructor here
	Passenger::Passenger() {
		m_name[0] = '\0';
		m_destination[0] = '\0';
		}
	
		// TODO: implement the constructor with 2 parameters here
		Passenger::Passenger(const char * name, const char * destination)
		{			
			if ( name != nullptr && destination != nullptr && name[0] != '\0' && destination[0] != '\0') {
				strcpy(m_name, name);
				strcpy(m_destination, destination);
			}
			else {
				m_name[0] = '\0';
				m_destination[0] = '\0';
			}
		}
		// TODO: implement isEmpty query here
		bool Passenger::isEmpty() const {
			if (m_destination[0] == '\0' && m_name[0] == '\0') {
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
				cout << m_name << " - " << m_destination << endl;
			}
		}
	
}