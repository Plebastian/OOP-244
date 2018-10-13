#include "ErrorMessage.h"
// Final Project Milestone 2
// Version 1.0
// Date	
// Author	
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS
#include	"ErrorMessage.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
sict::ErrorMessage::ErrorMessage(const char * errorMessage)
{
	if (errorMessage == nullptr) {
		this->m_ErrorMessage = '\0';
	}
	else {
	m_ErrorMessage = new char [strlen(errorMessage ) + 1];
	strcpy(m_ErrorMessage, errorMessage);
	}
}


sict::ErrorMessage::~ErrorMessage()
{
	delete[] m_ErrorMessage;
}

void sict::ErrorMessage::clear()
{
	delete[] m_ErrorMessage; 
	m_ErrorMessage = nullptr;
}

bool sict::ErrorMessage::isClear() const
{
	if (m_ErrorMessage == nullptr) {
		return true;
	}
	else
	return false;
}

void sict::ErrorMessage::message(const char * str)
{
	//de-alocate
	clear();
	m_ErrorMessage = new char[strlen(str) + 1];
	strcpy(m_ErrorMessage, str);
}

const char * sict::ErrorMessage::message() const
{
	return m_ErrorMessage;
}

std::ostream & sict::operator<<(std::ostream & ostr, const ErrorMessage & D)
{
	if (D.isClear()) {
		//nothing
	}
	else{
		ostr << D.message();
	}
	return ostr;
}
