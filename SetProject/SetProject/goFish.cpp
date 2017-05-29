/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother ErcanBrack, CS 235
* Author:
*    Matthew Brown
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  10 hrs   
*    Actual:     8 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include "set.h"
#include "card.h"
#include "goFish.h"
#include "hand.h"
using namespace std;

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
	Hand hand;
	hand.loadHand("/home/cs235e/week05/hand.txt");
	int matchCount = 0;
	cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand" << endl;
	for (int i = 0; i < 5; i++)
	{
		Card nextCard;
		cout << "round " << i + 1 << ": ";
		cin >> nextCard;

		if (hand.isInHand(nextCard))
		{
			matchCount++;
			cout << "\tYou got a match!" << endl;
			hand.remove(nextCard);
		}
		else
			cout << "\tGo Fish!" << endl;
	}

	cout << "You have " << matchCount << " matches!" << endl;
	hand.displayRemaining();
}
