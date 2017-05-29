/***********************************************************************
* Program:
*    Stock Asset
* Summary:
*    A stock with info about it.
* Author
*    Matthew Brown
************************************************************************/
#include "stockAsset.h"

#define BAD_VALUE_MSG "ERROR: Invalid value!";

/**********************************************************************
* STOCK ASSET :: Default Constructor
*
***********************************************************************/
StockAsset::StockAsset()
{
	mBuyPrice = Dollars(0);
	mQuantity = 0;
}

/**********************************************************************
* STOCK ASSET :: Non-Default Constructor
*
***********************************************************************/
StockAsset::StockAsset(Dollars price, int quantity)
{
	try
	{
		if (quantity > 0)
		{
			mBuyPrice = price;
			mQuantity = quantity;
		}
		else
			throw BAD_VALUE_MSG;
	}
	catch (char * msg)
	{
		throw msg;
	}

}

/**********************************************************************
* STOCK ASSET :: DeConstructor
*
***********************************************************************/
StockAsset::~StockAsset()
{
}

/**********************************************************************
* STOCK ASSET :: Remove Quantity
* Remove quantity from stock!
***********************************************************************/
bool StockAsset::removeQuantity(int quantity)
{
	if (quantity <= mQuantity)
	{
		mQuantity -= quantity;
		return true;
	}
	else
		return false;
}

/**********************************************************************
* STOCK ASSET :: Insertion operator.
*
***********************************************************************/
ostream & operator << (ostream & out, const StockAsset & rhs)
{
	out << "Bought " << rhs.getQuantity()
		<< " shares at " << rhs.getBuyPrice() << endl;

	return out;
}
