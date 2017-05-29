#include "stdafx.h"
#include "SalesRecordTest.h"
#include "gtest/gtest.h"
#include "stockAsset.h"
#include <sstream>
#include <string>
#include "dollars.h"
#include "saleRecord.h"

using namespace std;

TEST(Sale_Record_Tests, insertion_test)
{
	Dollars salePrice(5000);
	Dollars buyPrice(100);
	SaleRecord testObj(buyPrice, salePrice, 10);

	stringstream extractor;
	extractor << testObj;

	string actual, expected;
	expected = "Sold 10 shares at $50.00 for a profit of $490.00";

	getline(extractor, actual);

	EXPECT_EQ(expected, actual);
	

}

TEST(Sale_Record_Tests, non_Default_Constrcutor_Test)
{

}
