//#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;
namespace sict {
	Contact::Contact()
	{
		//set to safe empty state
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;

	}
	Contact::Contact(char name[], long long phoneNumbers[], int noOfPhoneNumbers)
	{
		//set to safe empty state
		m_name[0] = '\0';
		m_phoneNumbers = nullptr;
		m_noOfPhoneNumbers = 0;
		//allocate new array of phone numbers
		if (name != nullptr && name != '\0') {
			strncpy(m_name, name, 19);
			m_name[19] = '\0';
		}
		else {
			m_name[0] = 0;
		}
		if (phoneNumbers != nullptr && phoneNumbers[0] != '\0') {
			m_phoneNumbers = new long long[noOfPhoneNumbers];

			m_noOfPhoneNumbers = noOfPhoneNumbers;
		}
		int i = 0;
		for (i; i < noOfPhoneNumbers; i++) {
			//Designed to validate 11&12 digit numbers as well numbers validation
			if (phoneNumbers[i] > 10000000000 && phoneNumbers[i] < 999999999999) {
				//validation
				long long countryCode = (phoneNumbers[i] / 10000000000);

				long long areaCode = ((phoneNumbers[i] % 10000000000) / 10000000);

				long long phoneNumber = phoneNumbers[i] % 10000000;


				if (countryCode > 0 && countryCode <= 19 &&
					areaCode > 0 && areaCode < 999 &&
					phoneNumber >= 1000000 && phoneNumber <= 99999999) {
					m_phoneNumbers[i] = phoneNumbers[i];
				}
			}
		}

	};
	Contact::~Contact()
	{
		delete[] m_phoneNumbers;
	}
	void Contact::display() const
	{
		if (isEmpty()) {
			cout << "Empty Contact!" << endl;
		}
		else {
			cout << m_name << endl;
			if (m_phoneNumbers != nullptr && m_phoneNumbers[0] != '\0') {
				for (int i = 0; i < m_noOfPhoneNumbers; i++) {
					long long countryCode = (m_phoneNumbers[i] / 10000000000);
					long long areaCode = ((m_phoneNumbers[i] % 10000000000) / 10000000);
					int phoneNumber = m_phoneNumbers[i] % 10000000;
					int BeginLineNumber = phoneNumber / 10000;
					int EndLineNumber = phoneNumber % 10000;


					if (countryCode > 0 && countryCode <= 19 &&
						areaCode > 0 && areaCode < 999 &&
						phoneNumber >= 1000000 && phoneNumber <= 99999999) {

						//couldn't figure out how to solve the issue of using mod and keeping ZEROS
						if (EndLineNumber < 9) {
							cout << "(+" << countryCode << ") " << areaCode << " " << BeginLineNumber << "-" << "000" << EndLineNumber << endl;
						}
						else if (EndLineNumber < 99 && EndLineNumber > 9) {
							cout << "(+" << countryCode << ") " << areaCode << " " << BeginLineNumber << "-" << "00" << EndLineNumber << endl;
						}
						else if (EndLineNumber < 999 && EndLineNumber > 99) {
							cout << "(+" << countryCode << ") " << areaCode << " " << BeginLineNumber << "-" << "0" << EndLineNumber << endl;
						}
						else {
							cout << "(+" << countryCode << ") " << areaCode << " " << BeginLineNumber << "-" << EndLineNumber << endl;
						}
					}
				}
			}
		}
	}
	bool Contact::isEmpty() const
	{

		if (m_name[0] == '\0' && m_phoneNumbers == nullptr && m_noOfPhoneNumbers == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	Contact::Contact(const Contact& other) {
		int countryCode;
		int areaCode;
		int lineNumber;
		m_phoneNumbers = nullptr;
		strcpy(m_name, other.m_name);
		m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
		for (int i = 0; i < m_noOfPhoneNumbers; i++) {
			if (other.m_phoneNumbers[i] <= 999999999999 && other.m_phoneNumbers[i] >= 10000000000) {
				if (countryCode > 0 && countryCode <= 19 && areaCode > 0 && areaCode < 999 && lineNumber >= 1000000 && lineNumber <= 99999999) {
					m_phoneNumbers[i] = other.m_phoneNumbers[i];
				}
			}
		}
	}
	Contact& Contact::operator=(const Contact& other) {
		int countryCode;
		int areaCode;
		int lineNumber;
		if (this == &other) {
			delete[] m_phoneNumbers;
			m_phoneNumbers = nullptr;
			strcpy(m_name, other.m_name);
			m_noOfPhoneNumbers = other.m_noOfPhoneNumbers;
			for (int i = 0; i < m_noOfPhoneNumbers; i++) {
				m_phoneNumbers[i] = other.m_phoneNumbers[i];
			}
		}
		return *this;
	}
	Contact & Contact::operator+=(long long newnumber)
	{
		int countryCode;
		int areaCode;
		int lineNumber;
		long long *temp = nullptr;
		temp = new long long [m_noOfPhoneNumbers];
		for (int i = 0; i < m_noOfPhoneNumbers; i++) {
			temp[i] = m_phoneNumbers[i];
		}
		delete[] m_phoneNumbers;
		m_noOfPhoneNumbers += 1;
		m_phoneNumbers = new long long[m_noOfPhoneNumbers];
		for (int i = 0; i < m_noOfPhoneNumbers; i++){
			if (temp[i] <= 999999999999 && temp[i] >= 10000000000) {
				if (countryCode > 0 && countryCode <= 19 && areaCode > 0 && areaCode < 999 && lineNumber >= 1000000 && lineNumber <= 99999999) {

				}
			}
		}
		// TODO: insert return statement here
		return *this;
	}
}
