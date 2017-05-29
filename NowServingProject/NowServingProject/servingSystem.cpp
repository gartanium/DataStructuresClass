#include "servingSystem.h"


/************************************************
* SERVINGSYSTEM :: Default constructor
* 
***********************************************/
ServingSystem::ServingSystem()
{

}

/************************************************
* SERVINGSYSTEM :: Deconstructor constructor
*
***********************************************/
ServingSystem::~ServingSystem()
{
}

/************************************************
* SERVINGSYSTEM :: Add request
* Adds a help request to the system.
***********************************************/
void ServingSystem::addRequest(string name, string sClass, int time)
{
	HelpRequest nextItem(time, name, sClass);
	nextItem.setEmergency(false);

	if (currentRequest.isActive() == false)
		currentRequest = nextItem;
	else
		requests.push_back(nextItem);
}

/************************************************
* SERVINGSYSTEM :: Add emergency
* Adds an emergency request.
***********************************************/
void ServingSystem::addEmergency(string name, string sClass, int time)
{
	HelpRequest nextItem(time, name, sClass);
	nextItem.setEmergency(true);

	requests.push_front(nextItem);
}

/************************************************
* SERVINGSYSTEM :: Update TIme
* Updates the time for the system.
***********************************************/
void ServingSystem::updateTime()
{
	if (requests.size() > 0)
	{
		if (requests.front().emergency())
		{
			requests.front().updateTime();
		}
		else
		{
			currentRequest.updateTime(); 
		}
	}
	else
	{
		currentRequest.updateTime();
	}
}

/************************************************
* SERVINGSYSTEM :: Clean up
* Cleans up the help requests.
***********************************************/
void ServingSystem::cleanUp()
{
	// If the first entry's time up is up, clear it!
	// If the current item is empty, clear it, and get a new item!
	// First, is there an emergency?
	
	if (requests.size() > 0)
	{
		if (requests.front().emergency())
		{
			if (!requests.front().isActive())
			{
				requests.pop_front();
			}
		}
		else
		{
			if (!currentRequest.isActive())
			{
				currentRequest = HelpRequest(requests.front());
				requests.pop_front();
			}
		}
	}
	else
	{
		if (!currentRequest.isActive())
		{

		}
	}
}

/************************************************
* SERVINGSYSTEM :: Display info
* Displays info for the system.
***********************************************/
void ServingSystem::displayInfo()
{
	if (requests.size() > 0)
	{
		if (requests.front().emergency())
		{
			if(requests.front().getTime() > 0)
				cout << requests.front() << endl;
		}
		else
		{
			if (currentRequest.isActive())
			{
				if (currentRequest.getTime() > 0)
					cout << currentRequest << endl;
			}
		}

	}
	else if (currentRequest.isActive())
	{
		if (currentRequest.getTime() > 0)
			cout << currentRequest << endl;
	}

	
}

