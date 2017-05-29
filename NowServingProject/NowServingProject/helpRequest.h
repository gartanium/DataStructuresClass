/***********************************************************************
* Header:
*    Help Request
* Summary:
*    Class containing student info for a help request.
* Author
*    Matthew Brown
************************************************************************/

#pragma once
#ifndef HELPREQUEST_H
#define HELPREQUEST_H

#include <string>
#include <iostream>

using namespace std;

class HelpRequest
{
private:
	int mTime;
	string mName;
	string mClass;
	bool mEmergency;
	bool mActive;

public:
	HelpRequest() { mTime = 0; mName = "NULL"; mEmergency = false; mClass = "NULL"; mActive = false; }
	HelpRequest(int time, string name, string sClass) { mTime = time; mName = name; mClass = sClass; mEmergency = false; mActive = true; }
	HelpRequest(const HelpRequest & rhs);
	~HelpRequest();
	int getTime() { return mTime; }
	string getName() { return mName; }
	string getClass() { return mClass; }
	void updateTime() { mTime--; }
	friend ostream& operator << (ostream& out, const HelpRequest& rhs);
	void setEmergency(bool value) { mEmergency = value; }
	bool emergency() { return mEmergency; }
	bool isActive() { return mTime > 0; }
	void display() { cout << mClass << " " << mName << " " << mTime; }
	HelpRequest & operator =(const HelpRequest & rhs); 

};

#endif
