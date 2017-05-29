/***********************************************************************
* Program:
*    Sale Record
* Summary:
*    A record that contains info about a stock sale.
* Author
*    Matthew Brown
************************************************************************/
#pragma once
#ifndef SALERECORD_H
#define SALERECORD_H

#include "dollars.h"
#include <iostream>
#include <string>

using namespace std;

class SaleRecord
{
private:
	Dollars mBasePrice;
	Dollars mSellPrice;
	int mQuantity;
	Dollars mProfit;

public:
	SaleRecord();
	SaleRecord(Dollars basePrice, Dollars sellPrice, int quantity);
	~SaleRecord();

	Dollars getProfit() { return mProfit; }
	friend ostream & operator << (ostream&out, const SaleRecord & rhs);
};

#endif