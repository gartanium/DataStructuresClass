/***********************************************************************
* ServingSystem: The common deque data structure.
* Author:
*    Matthew Brown
* Summary:
*    This class implements the deque and help request classes. 
*    Implements most of the logic for the program. Has logic for updating
*    the system, removing items, and updating the time.
************************************************************************/
#pragma once

#ifndef SERVINGSYSTEM_H 
#define SERVINGSYSTEM_H

#include <string>
#include <iostream>
#include "deque.h"
#include "helpRequest.h"

class ServingSystem
{

private:
	Deque<HelpRequest> requests;
	HelpRequest currentRequest;

public:
	ServingSystem();
	~ServingSystem();

	void addRequest(string name, string sClass, int time);
	void addEmergency(string name, string sClass, int time);
	void updateTime();
	void cleanUp();
	void displayInfo();
	int waitingInLine() { return requests.size(); }


};

#endif
