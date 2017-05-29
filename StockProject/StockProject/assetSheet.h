/***********************************************************************
* Program:
*    AssetSheet
* Summary:
*    This file contains the notion of an asset sheet
* Author
*    Matthew Brown
************************************************************************/
#pragma once
#ifndef ASSETSHEET_H
#define ASSETSHEET_H

#include <iostream>
#include <string>

#include "stockAsset.h"
#include "queue.h"

class AssetSheet
{
private:
	Queue<StockAsset> mStockAssets;

public:
	AssetSheet();
	~AssetSheet();

	StockAsset removeStock();
	void addStock(StockAsset stock);
	StockAsset & front() { return mStockAssets.front(); }
	friend ostream & operator << (ostream&out, const AssetSheet & rhs);
	int size() const { return mStockAssets.size(); }

};

#endif