// UnitTest_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


// unittest_setProject.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "gtest/gtest.h"
#include "set.h"
#include "hand.h"
#include <string>

//************** Set Tests **************

// Default Con test
TEST(Set_Tests, Default_Constructor_Test)
{
	Set<int> testObj;
	EXPECT_EQ(testObj.size(), 0);
	EXPECT_EQ(testObj.capacity(), 0);
}

// Non Default Con Test
TEST(Set_Tests, Non_Default_Constructor_Test)
{
	Set<int> testObj(100);
	EXPECT_EQ(testObj.capacity(), 100);
}

// Empty test
TEST(Set_Tests, empty_Test_1)
{
	Set<int> testObj;
	EXPECT_TRUE(testObj.empty());
}

// Test insertion by size.
TEST(Set_Tests, insertion_Test_Size)
{
	Set<int> testObj;

	for (int i = 0; i < 5; i++)
	{
		testObj.insert(i);
		EXPECT_EQ(testObj.size(), i + 1);

	}


}

TEST(Set_Tests, insertion_Test_Sorted)
{
	Set<int> testObj;

	for (int i = 5; i >= 0; i--)
	{
		testObj.insert(i);
	}

	SetIterator<int> it = testObj.begin();

	int counter = 0;
	while(it != testObj.end())
	{
		EXPECT_EQ(*it, counter);

		counter++;
		it++;
	}
}

TEST(Set_Tests, erase_Test_Size)
{
	Set<int> testObj;

	for(int i = 0; i < 100; i++)
	{
		testObj.insert(i);
	}

	testObj.erase(2);
	EXPECT_EQ(testObj.size(), 99);

	
}


TEST(Set_Tests, erase_Test_Items)
{
	Set<int> testObj;
	int expected[] = { 0, 1, 3, 4 };

	for (int i = 0; i < 5; i++)
	{
		testObj.insert(i);
	}

	testObj.erase(2);

	SetIterator<int> it = testObj.begin();
	int counter = 0;

	while (it != testObj.end())
	{
		EXPECT_EQ(*it, expected[counter]);
		counter++;
		it++;
	}
}

TEST(Set_Test, find_Test)
{
	Set<int> testObj;
	for (int i = 0; i < 1000; i++)
	{
		testObj.insert(i);
	}

	EXPECT_EQ(testObj.find(99), 99);
}

TEST(Set_Test, find_Test_FAIL)
{
	Set<int> testObj;
	for (int i = 0; i < 1000; i++)
	{
		testObj.insert(i);
	}

	EXPECT_EQ(testObj.find(10001), -1);
}

TEST(Set_Test, Intersection_Test)
{
	Set<int> testObjLhs;
	for (int i = 0; i < 15; i++)
	{
		testObjLhs.insert(i);
	}

	Set<int> testObjRhs;
	for (int i = 10; i < 20; i++)
	{
		testObjRhs.insert(i);
	}

	Set<int> actual = testObjLhs && testObjRhs;

	EXPECT_EQ(actual.size(), 5);
}

TEST(Set_Test, Union_Test)
{
	Set<int> testObjLhs;
	for (int i = 0; i < 15; i++)
	{
		testObjLhs.insert(i);
	}

	Set<int> testObjRhs;
	for (int i = 10; i < 20; i++)
	{
		testObjRhs.insert(i);
	}

	Set<int> actual = testObjLhs || testObjRhs;

	EXPECT_EQ(actual.size(), 20);
	
}

// Hand tests
TEST(Hand_Tests, load_Test)
{
	Hand myHand;
	myHand.loadHand("C:/Users/Matthew/Documents/Visual Studio 2017/Projects/CS235Algorithims/SetProject/SetProject/foo.txt");

	EXPECT_EQ(myHand.size(), 5);

	
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



