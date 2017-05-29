/***********************************************************************
* Program:
*    AssetSheet
* Summary:
*    This file contains the notion of an asset sheet
* Author
*    Matthew Brown
************************************************************************/
#include "assetSheet.h"

/**********************************************************************
* Asset Sjeet :: Default Constructor
*
***********************************************************************/
AssetSheet::AssetSheet()
{
}

/**********************************************************************
* Sale Record :: DeConstructor
*
***********************************************************************/
AssetSheet::~AssetSheet()
{
}

/**********************************************************************
* Sale Record :: Remove Stock
* Remove Stock from asset sheet!
***********************************************************************/
StockAsset AssetSheet::removeStock()
{
	StockAsset rObj = mStockAssets.front();
	mStockAssets.pop();
	return rObj;
}

/**********************************************************************
* Sale Record :: Add Stock
* Add stock to asset sheet!
***********************************************************************/
void AssetSheet::addStock(StockAsset stock)
{
	mStockAssets.push(stock);
}

/**********************************************************************
* Sale Record :: Insertion operator
*
***********************************************************************/
ostream & operator<<(ostream & out, const AssetSheet & rhs)
{
	if (rhs.size() > 0)
	{
		Queue<StockAsset> copy = Queue<StockAsset>(rhs.mStockAssets);
		out << "Currently held:" << endl;

		for (int i = 0; i < rhs.size(); i++)
		{
			// TODO: insert return statement here
			out << "\t" << copy.front();
			copy.pop();
		}
	}
	else
	{
		out << "";
	}

	return out;
}
