#include "stdafx.h"
#include "queueTests.h"
#include "gtest/gtest.h"
#include "deque.h"
#include <string>

using namespace std;

/********************************************************
* Test: Constructor
* Rules:
* Ensures that an empty constructor is allocated
* Ensures Error message is printed:
* "ERROR: Unable to allocate a new buffer for queue"
**********************************************************/
TEST(Queue_Tests, Constructor)
{
	Queue<int> testObj;

	EXPECT_EQ(testObj.size(), 0);
	EXPECT_EQ(testObj.capacity(), 0);

}


/********************************************************
* Test: Destructor
* Rules:
* Make sure all memory is deallocated when class is destroyed.
*
**********************************************************/
TEST(Queue_Tests, Destructor)
{

}

/********************************************************
* Test: Operator =
* Rules:
* Ensures assignment operator takes a queue, and copies
* all elements over to it. Reallocates buffer if more
* memory is needed. If there is not enough memory, the
* following error message is thrown:
* "ERROR: Unable to allocate a new buffer for Queue"
**********************************************************/
TEST(Queue_Tests, assignment_Op_test)
{
	Queue<int> testObj1;
	Queue<int> testObj2;

	for (int i = 0; i < 10; i++)
	{
		testObj1.push(i);
	}

	for (int i = 0; i < 100; i++)
	{
		testObj2.push(i);
	}

	testObj1 = testObj2;

	// Make sure they are equal.
	EXPECT_EQ(testObj1.capacity(), testObj2.capacity()); // Same capacity?
	EXPECT_EQ(testObj1.size(), testObj2.size()); //   // Same size?

	// All objects equal?
	for (int i = 0; i < 100; i++)
	{
		int actual = testObj1.front();
		int expected = testObj2.front();
		EXPECT_EQ(actual, expected);
		testObj1.pop();
		testObj2.pop();
	}

}

/********************************************************
* Test: empty
* Rules:
* Tests whether or not the empty method is functional. 
* It's expected to return true if the queue is empty.
**********************************************************/
TEST(Queue_Tests, empty_test)
{
	
	Queue<int> testObj;
	EXPECT_TRUE(testObj.empty());
	
	testObj.push(1);
	EXPECT_FALSE(testObj.empty());
}


/********************************************************
* Test: size 
* Rules:
* Test to see if function returns the queue's size.
*
**********************************************************/
TEST(Queue_Tests, size_test)
{
	Queue<int> testObj;
	EXPECT_EQ(testObj.size(), 0);

	for (int i = 0; i < 103; i++)
	{
		testObj.push(i);
	}

	EXPECT_EQ(testObj.size(), 103);
}


/********************************************************
* Test: capacity
* Rules:
* Tests to see if the queue's capacity is valid.
*
**********************************************************/
TEST(Queue_Tests, capacity_test)
{

}


/********************************************************
* Test: clear
* Rules:
* Clears the queue
*
**********************************************************/
TEST(Queue_Tests, clear_test)
{
	Queue<bool> testObj;


	for (int i = 0; i < 100; i++)
	{
		testObj.push(true);
	}

	EXPECT_EQ(testObj.size(), 100);

	testObj.clear();

	EXPECT_EQ(testObj.size(), 0);
}


/********************************************************
* Test: push
* Rules:
* Pushes an item onto the queue
* If insufficient memory, throw error:
* "ERROR: Unable to allocate a new buffer for queue"
**********************************************************/
TEST(Queue_Tests, push_test)
{
	Queue<int> testObj;
	
	for (int i = 0; i < 10; i++)
	{
		testObj.push(i);
		EXPECT_EQ(testObj.back(), i);
		EXPECT_EQ(testObj.front(), 0);
	}
}


/********************************************************
* Test: pop
* Rules:
* Removes the front item of the queue.
* If queue is empty, throw error message:
* "ERROR: attempting to pop from an empty queue."
**********************************************************/
TEST(Queue_Tests, pop_test)
{
	Queue<int> testObj;
	for (int i = 0; i < 10; i++)
	{
		testObj.push(i);
	}

	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(testObj.front(), i);
		testObj.pop();
	}
}

/********************************************************
* Test: front
* Rules:
* Returns item at the front of the queue.
* Exception thrown if queue is empty:
* "Error: attempting to access an item in an empty queue"
**********************************************************/
TEST(Queue_Tests, front_test)
{

}


/********************************************************
* Test: back
* Rules:
* Returns the item at the back of the queue.
* Exception thrown if it's empty:
* "ERROR: attempting to access an item in an empty queue"
**********************************************************/
TEST(Queue_Tests, back_test)
{

}

/********************************************************
* Test: push_test
* See if it works
**********************************************************/
TEST(Queue_Tests, push_non_default_constructor)
{
	Queue<int> testObj(1000);

	for (int i = 0; i < 10; i++)
	{
		testObj.push(i);
		EXPECT_EQ(testObj.size(), i + 1);
	}
}

/********************************************************
* Test: push_default_constructor
* Test push with default constructor.
**********************************************************/
TEST(Queue_Tests, push_default_constructor)
{
	Queue<int> testObj;

	for (int i = 0; i < 10; i++)
	{
		testObj.push(i);
		EXPECT_EQ(testObj.size(), i + 1);
	}
}

/********************************************************
* Test: Pop test
* Test to see if size works with pop
**********************************************************/
TEST(Queue_Tests, pop_num_Items_test)
{
	Queue<int> testObj;

	for (int i = 0; i < 10; i++)
	{
		testObj.push(i);
	}

	for (int i = 10; i > 0; i--)
	{
		EXPECT_EQ(testObj.size(), i);
		testObj.pop();
	}
}

/********************************************************
* Test: pop_ring_Functionaliy_test
* Tests ring functionality of queue.
**********************************************************/
TEST(Queue_Tests, pop_ring_Functionaliy_test)
{
	Queue<int> testObj(4);

	for (int i = 0; i < 4; i++)
	{
		testObj.push(i);
	}

	// Pop it once!
	testObj.pop();

	// Pop it twice!
	testObj.pop();

	// Now insert 2 other numbers
	testObj.push(8);
	testObj.push(9);

	// it should be like this:
	// 2 3 8 9

	EXPECT_EQ(testObj.front(), 2);
	EXPECT_EQ(testObj.back(), 9);

	testObj.pop();
	EXPECT_EQ(testObj.front(), 3);
	
	testObj.pop();
	EXPECT_EQ(testObj.front(), 8);

	testObj.pop();
	EXPECT_EQ(testObj.front(), 9);
	
}

/********************************************************
* Test: Copy_Constructor_Test
* Tests to see if copy constructor functions properly.
**********************************************************/
TEST(Queue_Tests, copy_constructor_test)
{
	Queue<int> testObj1;
	
	for (int i = 0; i < 10; i++)
	{
		testObj1.push(i);
	}

	Queue<int> testObj2(testObj1);

	EXPECT_EQ(testObj2.capacity(), testObj1.capacity());
	EXPECT_EQ(testObj2.size(), testObj1.size());

	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(testObj2.front(), testObj1.front());
		EXPECT_EQ(testObj2.back(), testObj1.back());

		testObj1.pop();
		testObj2.pop();
	}
}

// Exception tests

/********************************************************
* Test: pop_Exception_Test
* Tests to see if pop throws an exception!
**********************************************************/
TEST(Queue_Exception_Tests, pop_Exception_Test)
{
	Queue<int> testObj;

	try {
		testObj.pop();
		FAIL() << "Expected: ERROR: attempting to pop from an empty queue";
	}
	catch (char * msg)
	{
		EXPECT_EQ(msg, "ERROR: attempting to pop from an empty queue");
		            
	}

}

/********************************************************
* Test: front_Exception_Test
* Tests to see if an exception is thrown when front item is
* accessed in an empty queue
**********************************************************/
TEST(Queue_Exception_Tests, front_Exception_Test)
{
	Queue<int> testObj;

	try
	{
		testObj.front();
		FAIL() << "Expected: ERROR: attempting to access an item in an empty queue";
	}
	catch (char * msg)
	{
		EXPECT_EQ(msg, "ERROR: attempting to access an item in an empty queue");
	}
}

/********************************************************
* Test: back_Exception_Test
* Tests to see if an exception is thrown when a back item is
* accessed in an empty queue
**********************************************************/
TEST(Queue_Exception_Tests, back_Exception_Test)
{
	Queue<int> testObj;

	try
	{
		testObj.back();
		FAIL() << "Expected: ERROR: attempting to access an item in an empty queue";
	}
	catch (char * msg)
	{
		EXPECT_EQ(msg, "ERROR: attempting to access an item in an empty queue");
	}
}
