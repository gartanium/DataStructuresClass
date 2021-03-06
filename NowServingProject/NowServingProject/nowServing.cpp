/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
#include "servingSystem.h"
using namespace std;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here
   ServingSystem servingSystem;
   bool runProgram = true;
   int stepCount = 0;
   bool addEmergency = false;
   string nextInput;
   string name;
   string className;

   while (runProgram)
   {

	   int minutes;
	   cout << "<" << stepCount << "> ";
	   cin >> nextInput;
	  
	   if (addEmergency)
	   {
		   addEmergency = false;
		   servingSystem.addEmergency(name, className, minutes);
		   
	   }
	   else
	   {

		   if (nextInput == "finished")
		   {
			   runProgram = false;
		   }
		   else if (nextInput == "!!")
		   {
			   cin >> className;
			   cin >> name;
			   cin >> minutes;
			   addEmergency = true;

		   }
		   else if (nextInput == "none")
		   {

		   }
		   else
		   {
			   cin >> name;
			   cin >> minutes;
			   servingSystem.addRequest(name, nextInput, minutes);
		   }
	   }

	   servingSystem.displayInfo();
	   servingSystem.updateTime();
	   servingSystem.cleanUp();
	   stepCount++;

   }
   // end
   cout << "End of simulation\n";

	
  
}


