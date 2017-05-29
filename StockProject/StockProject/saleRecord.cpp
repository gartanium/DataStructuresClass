/***********************************************************************
* Program:
*    Sale Record
* Summary:
*    A record that contains info about a stock sale.
* Author
*    Matthew Brown
************************************************************************/
#include "saleRecord.h"


/**********************************************************************
* Sale Record :: Default Constructor
*
***********************************************************************/
SaleRecord::SaleRecord()
{
	mBasePrice = Dollars(0);
	mSellPrice= Dollars(0);
	mQuantity = 0;
	mProfit = Dollars(0);
}

/**********************************************************************
* Sale Record :: Non-Default Constructor
*
***********************************************************************/
SaleRecord::SaleRecord(Dollars basePrice, Dollars sellPrice, int quantity)
{
	mBasePrice = basePrice;
	mSellPrice = sellPrice;
	mQuantity = quantity;
	mProfit = Dollars(0);

	for (int i = 0; i < quantity; i++)
	{
		mProfit += mSellPrice - mBasePrice;
	}
}

/**********************************************************************
* Sale Record :: DeConstructor
*
***********************************************************************/
SaleRecord::~SaleRecord()
{
}

/**********************************************************************
* Sale Record :: Insertion operator
*
***********************************************************************/
ostream & operator<<(ostream & out, const SaleRecord & rhs)
{
	// TODO: insert return statement here
	out << "Sold " << rhs.mQuantity << " shares at "
		<< rhs.mSellPrice << " for a profit of "
		<< rhs.mProfit << endl;

	return out;
}
