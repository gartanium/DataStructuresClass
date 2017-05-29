/***********************************************************************
* Header:
*    Hand
* Summary:
*    This class contains the notion of a hand. It includes cards,
*	 and the ability to load a hand from a file.
*
* Author
*    Matthew Brown
************************************************************************/
#include "hand.h"
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;

/************************************************
* Hand :: Defult Constructor
***********************************************/
Hand::Hand()
{
}

/************************************************
* Hand :: DeConstructor
***********************************************/
Hand::~Hand()
{
}

/************************************************
* Hand :: Load Hand
* Loads a hand from a file.
***********************************************/
void Hand::loadHand(char * path)
{
	string stringHand;
	ifstream myFile;
	myFile.open(path);

	if (myFile.is_open())
	{
		getline(myFile, stringHand);
		myFile.close();
	}
	else throw "Open file failed!";

	stringstream converter(stringHand);

	Card nextCard;
	while (converter >> nextCard)
	{
		cerr << nextCard << endl;
		hand.insert(nextCard);
	}

}

/************************************************
* Hand :: Is In Hand
* Searches the set to determine if a card is in it.
***********************************************/
bool Hand::isInHand(Card card)
{
	if (hand.find(card) > 0)
		return true;
	else
		return false;
}

/************************************************
* Hand :: Remove
* Remove card from set.
***********************************************/
void Hand::remove(Card card)
{
	hand.erase(hand.find(card));
}

/************************************************
* Hand :: Remove
* Remove card from set by Index.
***********************************************/
void Hand::remove(int index)
{
	hand.erase(index);
}

/************************************************
* Hand :: Display Remaining
* Displays all remaining cards!
***********************************************/
void Hand::displayRemaining()
{
	SetIterator<Card> it = hand.begin();
	stringstream converter;
	converter << *it;
	it++;

	while (it != hand.end())
	{
		converter << ", " << *it;
		it++;
	}
	
	string display;
	getline(converter, display);

	cout << "The remaining cards: " << display << endl;
}
