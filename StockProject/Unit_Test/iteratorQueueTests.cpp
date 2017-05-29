#include "stdafx.h"
#include "queueTests.h"
#include "gtest/gtest.h"
#include "queueIterator.h"
#include <string>

/********************************************************
* Test: Constructor -  Default
* Rules:
*
**********************************************************/
TEST(QueueIterator_Tests, defaultConstructor)
{
	QueueIterator testObj;
	EXPECT_EQ(testObj.getSize(), 0);
}

/********************************************************
* Test: Constructor - Non Default
* Rules:
*
**********************************************************/
TEST(QueueIterator_Tests, nonDefaultConstructor)
{
	QueueIterator testObj(10);
	EXPECT_EQ(testObj.getSize(), 10);
}

/********************************************************
* Test: Left Of Test
* Rules:
*
**********************************************************/
TEST(QueueIterator_Tests, LeftOfTest)
{
	QueueIterator testObj(10);
	int dataExpected[] = { 9, 0, 1, 2, 3, 4, 5, 6, 7, 8 };

	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(testObj.leftOf(), dataExpected[i]);
		testObj++;
	}
}

/********************************************************
* Test: Right Of Test
* Rules:
*
**********************************************************/
TEST(QueueIterator_Tests, RightOfTest)
{
	QueueIterator testObj(10);
	int dataExpected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(testObj.rightOf(), dataExpected[i]);
		testObj++;
	}
}

/********************************************************
* Test: Current Index Test
* Rules:
*
**********************************************************/
TEST(QueueIterator_Tests, CurentIndexTest)
{
	QueueIterator testObj(10);
	int dataExpected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(testObj.currentIndex(), dataExpected[i]);
		testObj++;
	}
}
