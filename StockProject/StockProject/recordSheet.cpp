/***********************************************************************
* Program:
*    RecordSheet
* Summary:
*    Contains a queue of records!
* Author
*    Matthew Brown
************************************************************************/
#include "recordSheet.h"


/**********************************************************************
* Sale Record :: Default Constructor
*
***********************************************************************/
RecordSheet::RecordSheet()
{
}

/**********************************************************************
* Sale Record :: DeConstructor
*
***********************************************************************/
RecordSheet::~RecordSheet()
{
}

/**********************************************************************
* Sale Record :: Create Record
* Adds a record to the queue!
***********************************************************************/
void RecordSheet::createRecord(int quantity, Dollars basePrice, Dollars sellPrice)
{
	SaleRecord nextItem(basePrice, sellPrice, quantity);
	mRecords.push(nextItem);
}

/**********************************************************************
* Sale Record :: Insertion Operator
*
***********************************************************************/
ostream & operator<<(ostream & out, const RecordSheet & rhs)
{
	Queue<SaleRecord> copy = Queue<SaleRecord>(rhs.mRecords);

	out << "Sell History:" << endl;

	while (copy.size() > 0)
	{
		// TODO: insert return statement here
		out << "\t" << copy.front();
		copy.pop();
	}

	return out;
}
