// unit_test_driver.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "gtest/gtest.h"
#include "stack.h"
#include <string>
#include "infixAlg.h"


using namespace std;

// Stack tests
TEST(Stack_Tests, is_empty_test)
{
	Stack<int> testObj;

	for (int i = 0; i < 5; i++)
	{
		testObj.push(i);
	}

	int expected = 5;
	int actual = testObj.size();

	EXPECT_EQ(expected, actual);

	for (int i = 0; i < 5; i++)
	{
		testObj.pop();
	}

	EXPECT_TRUE(testObj.empty());

	testObj.push(1);
	EXPECT_FALSE(testObj.empty());
}

// Test to make sure that the stack pops back okay.
TEST(Stack_Tests, pop_Test)
{
	Stack<int> testObj;
	const int stackFillAmount = 100;
	
	// Fill her up!
	for (int i = 0; i < stackFillAmount; i++)
	{
		testObj.push(i);
	}

	for (int i = 0; i < stackFillAmount / 2; i++)
	{
		testObj.pop();
	}

	int expected1 = stackFillAmount / 2;
	int actual1 = testObj.size();

	EXPECT_EQ(expected1, actual1);

	// Iterate again. Size should be 0.
	for (int i = 0; i < stackFillAmount / 2; i++)
	{
		testObj.pop();
	}
	int expected2 = 0;
	int actual2 = testObj.size();

	EXPECT_EQ(expected2, actual2);
}

// Test to ensure that the proper exception is thrown!
TEST(Stack_Tests, pop_Exception_Test)
{
	Stack<int> testObj;
	string expected = "ERROR: Unable to pop from an empty Stack";

	try
	{
		testObj.pop();
		FAIL();
	}
	catch(char * msg)
	{
		string errorMsg(msg);
		ASSERT_EQ(expected, errorMsg);
	}
}

// Tests to ensure that the size of the stack is increasing on a push.
TEST(Stack_Tests, push_Test)
{
	// Make sure we really push in 100 items
	Stack<int> testObj;
	for (int i = 0; i < 100; i++)
	{
		testObj.push(i);
		EXPECT_EQ(testObj.size(), i+1); // Is the size equal?
	}
}

// Ensure that top reveals the top item in the stack.
TEST(Stack_Tests, top_Test)
{
	Stack<int> testObj;

	for (int i = 0; i < 50; i++)
	{
		testObj.push(i);
		
		int topObj = testObj.top();

		EXPECT_EQ(topObj, i);
	}

}

// Ensure that an error is thrown properly.
TEST(Stack_Tests, top_Exception_Test)
{
	Stack<int> testObj;
	string expected = "ERROR: Unable to reference the element from an empty Stack";
	bool doesItContinue = false;

	try
	{
		testObj.top();
		FAIL();
	}
	catch (char * msg)
	{
		string errorMsg(msg);
		ASSERT_EQ(expected, errorMsg);
	}
}

// Ensures that the stack is cleared.
TEST(Stack_Tests, clear_Test)
{
	// We want to make sure size is set to zero.
	Stack<int> testObj;

	for (int i = 0; i < 100; i++)
	{
		testObj.push(i);
	}

	// Make sure it's size starts at 100.
	EXPECT_EQ(testObj.size(), 100);
	testObj.clear();
	EXPECT_EQ(testObj.size(), 0);

}

// Ensure it's capacity is larger then size lol.
TEST(Stack_Tests, capacity_test)
{
	Stack<int> testObj;

	for (int i = 0; i < 100; i++)
	{
		testObj.push(i);
		EXPECT_TRUE(testObj.capacity() > i);
	}

}

TEST(Stack_Tests, assignment_operator_test)
{
	Stack<int> testObj1;
	Stack<int> testObj2;

	// Fill test object 2.
	for (int i = 0; i < 100; i++)
	{
		testObj2.push(i);
	}

	// set them equal.
	testObj1 = testObj2;

	EXPECT_EQ(testObj1.size(), testObj2.size());

	// Ensure that they are truly equal.
	for (int i = 0; i < 99; i++)
	{
		try
		{
			EXPECT_EQ(testObj1.top(), testObj2.top());
			testObj1.pop();
			testObj2.pop();
			EXPECT_EQ(testObj1.top(), testObj2.top());
		}
		catch (char * msg)
		{
			FAIL() << msg;
		}
	}
}

// Infix tests...

// Simple function for testing conversion from infix to postfix.
void testInfixToPostFix(string infix, string expected)
{
	InfixAlg testObj(infix);
	string actual = testObj.to_postFix();
	EXPECT_EQ(actual, expected);
}

TEST(Infix_Tests, to_postFix_Test)
{

	testInfixToPostFix("alpha * beta + 123", " alpha beta * 123 +");
	testInfixToPostFix("alpha + beta", " alpha beta +");
	testInfixToPostFix("a - b - c - d - e - f", " a b - c - d - e - f -");
	testInfixToPostFix("4.0 + 4", " 4.0 4 +");
	testInfixToPostFix("5 ^ 3 + 5 + 1", " 5 3 ^ 5 + 1 +");
	testInfixToPostFix("4 * (9 + 3)", " 4 9 3 + *");
	testInfixToPostFix("0.5 .4", " 0.5 .4");
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

