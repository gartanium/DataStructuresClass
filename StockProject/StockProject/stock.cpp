/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Matthew Brown
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "assetSheet.h"
#include "recordSheet.h"
#include "stockAsset.h"
#include "saleRecord.h"
#include <sstream>

using namespace std;

/**********************************************************************
* STOCK :: Default Constructor
*
***********************************************************************/
Dollars Stock::getDollars()
{
	Dollars nextItem;
	cin >> nextItem;
	return nextItem;
}

/**********************************************************************
* STOCK :: getQuantity
*
***********************************************************************/
int Stock::getQuantity()
{
	int quantity;
	cin >> quantity;
	return quantity;
}

/**********************************************************************
* STOCK :: Default Constructor
*
***********************************************************************/
Stock::Stock()
{
}

/**********************************************************************
* STOCK :: DeConstructor
*
***********************************************************************/
Stock::~Stock()
{
}

/**********************************************************************
* STOCK :: Buy
* Buy a stock!
***********************************************************************/
void Stock::buy(int quantity, Dollars price)
{
	StockAsset nextItem(price, quantity);
	mAssetSheet.addStock(nextItem);
}

/**********************************************************************
* STOCK :: Sell 
* Sell a stock!
***********************************************************************/
void Stock::sell(int quantity, Dollars price)
{
	while (quantity > 0)
	{
		// does our stock have enough quantity?
		StockAsset currentItem = mAssetSheet.front();
		if (currentItem.getQuantity() > quantity)
		{
			
			mAssetSheet.front().removeQuantity(quantity);
			mSaleRecord.createRecord(quantity, currentItem.getBuyPrice(), price);
			quantity = 0;

		}
		// No? Well use the next one!
		else
		{
			mSaleRecord.createRecord(currentItem.getQuantity(), currentItem.getBuyPrice(), price);
			quantity -= currentItem.getQuantity();
			mAssetSheet.removeStock();
			
		}

		proceeds += mSaleRecord.back().getProfit();
	}
}

/**********************************************************************
* STOCK :: displayAssets
*
***********************************************************************/
void Stock::displayAssets()
{
	cout << mAssetSheet;
}

/**********************************************************************
* STOCK :: Display sale record
*
***********************************************************************/
void Stock::displaySaleRecord()
{
	cout << mSaleRecord;
}

/**********************************************************************
* STOCK :: Display proceeds
*
***********************************************************************/
void Stock::displayProceeds()
{
	cout << "Proceeds: " << proceeds << endl;
}

/**********************************************************************
* STOCK :: Handle commands
* Menu
***********************************************************************/
void Stock::handleCommands()
{
	bool quit = false;
	string command1;

	while (quit == false)
	{
		cout << "> ";
		cin >> command1;


		if (command1 == "buy")
		{
			int quantity = getQuantity();
			Dollars price = getDollars();
			buy(quantity, price);
		}
		else if (command1 == "sell")
		{
			int quantity = getQuantity();
			Dollars price = getDollars();
			sell(quantity, price);

		}
		else if (command1 == "display")
		{
			displayAssets();

			if (mSaleRecord.size() > 0)
				displaySaleRecord();

			displayProceeds();

		}
		else if (command1 == "quit")
		{
			quit = true;
		}
		else
		{
			quit = true;
		}

			
	}
}

/************************************************
* STOCKS BUY SELL
* The interactive function allowing the user to
* buy and sell stocks
***********************************************/
void stocksBuySell()
{
	Stock stock;

	// instructions
	cout << "This program will allow you to buy and sell stocks. "
		<< "The actions are:\n";
	cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
	cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
	cout << "  display         - Display your current stock portfolio\n";
	cout << "  quit            - Display a final report and quit the program\n";

	stock.handleCommands();
}