// unittest_vector_project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "vector.h"
#include <string>

using namespace std;

// Test for Push Back.
TEST(vector_tests, push_back_test)
{
	Vector<int> testObj;

	for (int i = 0; i < 100; i++)
	{
		EXPECT_EQ(testObj.size(), i);
		testObj.push_back(i);
	}
}

TEST(vector_tests, assignment_operator_tests)
{
	Vector<int> testObjLhs;
	Vector<int> testObjRhs;

	testObjLhs.push_back(1);

	testObjRhs.push_back(9);
	testObjRhs.push_back(8);
	testObjRhs.push_back(7);

	testObjLhs = testObjRhs;

	EXPECT_EQ(testObjLhs[0], 9);
	EXPECT_EQ(testObjLhs[1], 8);
	EXPECT_EQ(testObjLhs[2], 7);
}

TEST(vector_tests, assignment_operator_Null_test)
{
	Vector<int> myNotNullTestObj;
	Vector<int> myNullTestObj;

	myNotNullTestObj.push_back(1);

	myNotNullTestObj = myNullTestObj;

	EXPECT_EQ(myNotNullTestObj.capacity(), 0);
}

TEST(vector_tests, index_operator_tests)
{
	Vector<int> testObj;
	for (int i = 0; i < 100; i++)
	{
		testObj.push_back(i);
		EXPECT_EQ(i, testObj[i]);
	}
}

// Test for adding text.
TEST(vector_tests, string_push_back_test)
{
	Vector<string> testObj;

	testObj.push_back("hi");
	testObj.push_back("bye");
	testObj.push_back("hello");
	testObj.push_back("good bye");
	testObj.push_back("Hello, have a good day!");

	EXPECT_EQ(testObj[0], "hi");
	EXPECT_EQ(testObj[1], "bye");
	EXPECT_EQ(testObj[2], "hello");
	EXPECT_EQ(testObj[3], "good bye");
	EXPECT_EQ(testObj[4], "Hello, have a good day!");

}

TEST(vector_tests, resize_test)
{
	Vector<int> testObj;
	
	// 1
	// 2
	// 4
	// 8
	// 16
	// 32
	// 64
	// 128
	for (int i = 0; i < 64; i++)
	{
		testObj.push_back(i);
	}

	testObj.push_back(1);

	EXPECT_EQ(testObj.capacity(), 128);

}

TEST(vector_tests, size_test)
{
	Vector<int> testObj;

	for (int i = 0; i < 100; i++)
	{
		testObj.push_back(i);
	}

	EXPECT_EQ(testObj.size(), 100);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

