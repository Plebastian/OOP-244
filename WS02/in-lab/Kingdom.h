/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H

// TODO: sict namespace
namespace sict {
// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom
	{
		//kingdom name
			char m_name[33];
		//kingdom pop
			int m_population;

	};
// TODO: declare the function display(...),
//         also in the sict namespace
	void display(Kingdom& a);
}
#endif //!KINGDOM_H