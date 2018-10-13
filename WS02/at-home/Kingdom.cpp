
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

	void display(Kingdom * pKingdom, int count)
	{
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < count; i++) {
			cout << i + 1 << ". ";
			display(pKingdom[i]);
		}
		cout << "------------------------------" << endl;
		//calculate total population
		int total_population = 0;
		for (int i = 0; i < count; i++) {
			total_population += pKingdom[i].m_population;
		}
		cout << "Total population of SICT: " << total_population << endl;
		cout << "------------------------------" << endl;
	}

	}