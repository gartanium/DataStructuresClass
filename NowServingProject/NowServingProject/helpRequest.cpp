/***********************************************************************
* Header:
*    Help Request
* Summary:
*    Class containing student info for a help request.
* Author
*    Matthew Brown
************************************************************************/
#include "helpRequest.h"

HelpRequest::HelpRequest(const HelpRequest & rhs)
{
	mTime = rhs.mTime;
	mName = rhs.mName;
	mClass = rhs.mClass;
	mEmergency = rhs.mEmergency;
	mActive = rhs.mActive;
}

/**********************************************************************
* HELPREQUEST :: Deconstructor
*
***********************************************************************/
HelpRequest::~HelpRequest()
{
}

HelpRequest & HelpRequest::operator=(const HelpRequest & rhs)
{
	 mTime = rhs.mTime; 
	 mName = rhs.mName;
	 mClass = rhs.mClass; 
	 mEmergency = rhs.mEmergency; 
	 mActive = rhs.mActive; 
	 return *this; 
}

/**********************************************************************
* HELPREQUEST :: Insertion operator
*
***********************************************************************/
ostream & operator<<(ostream & out, const HelpRequest & rhs)
{
	if (!rhs.mEmergency)
		out << "\tCurrently serving " << rhs.mName << " for class "
		<< rhs.mClass << ". Time left: " << rhs.mTime;
	else
	{
		out << "\tEmergency for " << rhs.mName << " for class "
			<< rhs.mClass << ". Time left: " << rhs.mTime;
	}

	return out;
}
