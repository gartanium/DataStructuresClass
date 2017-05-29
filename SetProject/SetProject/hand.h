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
#ifndef HAND_H
#define HAND_H
#pragma once
#include "set.h"
#include "card.h"
#include <string>

using namespace std;

/************************************************
* Hand
* A class that holds cards using a Set.
***********************************************/
class Hand
{
private:
	Set<Card> hand;
public:
	Hand();
	~Hand();
	void loadHand(char * path);
	bool isInHand(Card card);
	void remove(Card card);
	void remove(int index);
	void displayRemaining();
	int size() { return hand.size(); }

};

#endif