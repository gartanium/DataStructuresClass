#include "stdafx.h"
#include "AssetSheetTest.h"
#include "assetSheet.h"
#include <iostream>
#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "stockAsset.h"
#include "dollars.h"

using namespace std;

TEST(Asset_Sheet_Tests, insertion_operator_test)
{
	//AssetSheet testObj;
	//Dollars testDollar1(50000);
	//StockAsset testData1(testDollar1, 10); // 50$ a pop and 10 in total.

	//Dollars testDollar2(100);
	//StockAsset testData2(testDollar2, 100); // 1$ a pop and 100 in total.

	//testObj.addStock(testData1);
	//testObj.addStock(testData2);

	//string expected;

	//stringstream extractor;
	//extractor << testObj;
	//string actual = "";

	//for (int i = 0; i < 6; i++)
	//{
	//	string input;
	//	getline(extractor, input);
	//	actual += input;

	//}


	//expected =  "Currently held:\n";
	//expected += "\tBought 10 shares at $50.00\n";
 //   expected += "\tBought 100 shares at $1.00";

	//EXPECT_EQ(expected, actual);

}

TEST(Asset_Sheet_Tests, add_stock_test)
{
	AssetSheet testObj;

	for (int i = 0; i < 10; i++)
	{
		StockAsset nextStock;
		testObj.addStock(nextStock);
		EXPECT_EQ(testObj.size(), i + 1);
	}
}

TEST(Asset_Sheet_Test, push_test)
{

}
