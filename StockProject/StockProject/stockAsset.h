/***********************************************************************
* Program:
*    Stock Asset
* Summary:
*    A stock with info about it.
* Author
*    Matthew Brown
************************************************************************/
#pragma once
#ifndef STOCKASSET_H
#define STOCKASSET_H

#include "dollars.h"
#include <string>
#include <iostream>

using namespace std;

class StockAsset
{

private:
	Dollars mBuyPrice;
	int mQuantity;

public:
	StockAsset();
	StockAsset(Dollars price, int quantity);
	~StockAsset();
	
	int getQuantity() const { return mQuantity; }
	Dollars getBuyPrice() const { return mBuyPrice; }
	Dollars getNonConstBuyPrice() { return mBuyPrice; }
	int getNonConstQuantity() { return mQuantity; }

	bool removeQuantity(int quantity);
	void setQuantity(int quantity) { mQuantity = quantity; }


	friend ostream & operator << (ostream&out, const StockAsset & rhs);
};

#endif