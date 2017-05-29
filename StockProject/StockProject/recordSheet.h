/***********************************************************************
* Program:
*    RecordSheet
* Summary:
*    Contains a queue of records!
* Author
*    Matthew Brown
************************************************************************/
#pragma once
#ifndef RECORDSHEET_H
#define RECORDSHEET_H

#include <iostream>
#include <string>

#include "saleRecord.h"
#include "stockAsset.h"
#include "queue.h"

class RecordSheet
{

private:
	Queue<SaleRecord> mRecords;

public:
	RecordSheet();
	~RecordSheet();

	void createRecord(int quantity, Dollars basePrice, Dollars sellPrice);
	friend ostream & operator << (ostream&out, const RecordSheet & rhs);

	int size() { return mRecords.size(); }
	
	SaleRecord back() { return mRecords.back(); }
};

#endif

