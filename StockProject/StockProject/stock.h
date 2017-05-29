/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include <iostream>    // for ISTREAM and OSTREAM
#include "assetSheet.h"
#include "recordSheet.h"

// the interactive stock buy/sell function
void stocksBuySell();

class Stock
{
private:
	AssetSheet mAssetSheet;
	RecordSheet mSaleRecord;


	Dollars proceeds;

public:
	Stock();
	~Stock();

	void buy(int quantity, Dollars price);
	void sell(int quantity, Dollars price);
	void displayAssets();
	void displaySaleRecord();
	void displayProceeds();

	int getQuantity();
	Dollars getDollars();
	
	void handleCommands();

};

#endif // STOCK_H

