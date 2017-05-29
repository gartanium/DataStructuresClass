#include "stdafx.h"
#include "StockAssetTest.h"
#include "gtest/gtest.h"
#include "stockAsset.h"
#include <sstream>
#include <string>
#include "dollars.h"

TEST(Stock_Asset_Tests, insertion_test)
{
	string actual;
	string expected;

	Dollars buyPrice(5000);
	StockAsset testObj(buyPrice, 30);

	stringstream extractor;
	extractor << testObj;

	getline(extractor, actual);

	expected = "Bought 30 shares at $50.00";

	EXPECT_EQ(expected, actual);
}

TEST(Stock_Asset_Tests, Copy_Constructor_Test)
{
	Dollars testD(5000);


	StockAsset testObj(testD, 30);
	StockAsset testObj2(testObj);

	EXPECT_EQ(testObj.getBuyPrice(), testObj2.getBuyPrice());
	EXPECT_EQ(testObj.getQuantity(), testObj2.getQuantity());
}

TEST(Stock_Asset_Tests, assignment_op_Test)
{
	Dollars testD(5000);


	StockAsset testObj(testD, 30);
	StockAsset testObj2 = testObj;

	EXPECT_EQ(testObj.getBuyPrice(), testObj2.getBuyPrice());
	EXPECT_EQ(testObj.getQuantity(), testObj2.getQuantity());

}

TEST(Stock_Asset_Tests, exception_test)
{

}