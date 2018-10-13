
/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 9/20/2017
// Author Sebastian Djurovic 042584144
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include "Kingdom.h"
#include <iostream>
// TODO: the sict namespace
using namespace std;
namespace sict{
    // TODO:definition for display(...) 
	void display(Kingdom& a)
		{
		
			cout << a.m_name << ", population " << a.m_population << endl;
		
		}
	}