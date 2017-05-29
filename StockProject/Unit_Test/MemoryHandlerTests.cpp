#include "stdafx.h"
#include "gtest/gtest.h"
#include "queue.h"
#include <string>
#include "MemoryHandlerTests.h"
#include "memoryHandler.h"

TEST(Memory_Handler_Test, default_Constructor)
{
	MemoryHandler<int> testObj;
}

TEST(Memory_Handler_Test, non_default_Constructor)
{
	MemoryHandler<int> testObj(10);
}

TEST(Memory_Handler_Test, copy_Constructor)
{
	MemoryHandler<int> testObj;
	MemoryHandler<int> testObj2(testObj);
}

TEST(Memory_Handler_Test, assignment_Operator)
{
	MemoryHandler<int> testObj;
	MemoryHandler<int> testObj2(10);

	testObj = testObj2;
}

// Now for some more indepth tests.
TEST(Memory_Handler_Test, non_default_Constructor1)
{
	MemoryHandler<int> testObj(10);
	EXPECT_EQ(testObj.getSize(), 10);
	EXPECT_EQ(testObj.getNumItems(), 0);
	
}

TEST(Memory_Handler_Test, non_default_Constructor2)
{
	MemoryHandler<int> testObj(10);

	for (int i = 0; i < 10; i++)
	{
		testObj.insertItem(i);
		EXPECT_EQ(testObj.getNumItems(), i + 1);
	}
}

TEST(Memory_Handler_Test, non_default_Constructor3)
{
	MemoryHandler<int> testObj(10);
	

	for (int i = 0; i < 10; i++)
	{
		
		EXPECT_TRUE(testObj.isFull() == false);

		testObj.insertItem(i);
		
	}

	EXPECT_TRUE(testObj.isFull());
}

TEST(Memory_Handler_Test, non_default_Constructor_Is_Empty)
{
	MemoryHandler<int> testObj(10);
	EXPECT_TRUE(testObj.isEmpty() == true);


	for (int i = 0; i < 10; i++)
	{

		testObj.insertItem(i);
		EXPECT_TRUE(testObj.isEmpty() == false);

	}
}

TEST(Memory_Handler_Test, Insertion_Test1)
{
	MemoryHandler<int> testObj(10);

	for (int i = 0; i < 10; i++)
	{
		testObj.insertItem(i);
	}

	for (int i = 0; i < 10; i++)
	{
		int actual = testObj.extractItem();
		EXPECT_EQ(i, actual);
	}
}

TEST(Memory_Handler_Test, Circular_Memory_Test)
{
	MemoryHandler<int> testObj(10);

	for (int i = 0; i < 10; i++)
	{
		testObj.insertItem(i);
	}

	for (int i = 0; i < 10; i++)
	{
		testObj.extractItem();
	}

	for (int i = 0; i < 10; i++)
	{
		testObj.insertItem(i);
	}

	for (int i = 0; i < 10; i++)
	{
		int actual = testObj.extractItem();
		EXPECT_EQ(i, actual);
	}
}

TEST(Memory_Handler_Test, Back_Test)
{
	MemoryHandler<int> testObj(10);

	for (int i = 0; i < 15; i++)
	{
		testObj.insertItem(i);
		int actual = testObj.getBack();
		testObj.extractItem();

		EXPECT_EQ(actual, i);
	}
}


TEST(Memory_Handler_Test, Front_Test)
{
	MemoryHandler<int> testObj(10);

	for (int i = 0; i < 5; i++)
	{
		testObj.insertItem(i);
	}

	for (int i = 0; i < 5; i++)
	{
		int actual = testObj.getFront();
		EXPECT_EQ(i, actual);
		testObj.extractItem();
	}
}

TEST(Memory_Handler_Test, clear_Test1)
{
	MemoryHandler<int> testObj(10);

	for (int i = 0; i < 10; i++)
	{
		testObj.insertItem(i);
	}

	testObj.clear();

	EXPECT_EQ(testObj.getSize(), 10);
	EXPECT_EQ(testObj.getNumItems(), 0);

}

TEST(Memory_Handler_Test, clear_Test2)
{
	MemoryHandler<int> testObj(10);

	for (int i = 0; i < 10; i++)
	{
		testObj.insertItem(i);
	}

	testObj.clear();

	for (int i = 0; i < 5; i++)
	{
		testObj.insertItem(i);
	}

	EXPECT_EQ(testObj.getSize(), 10);
	EXPECT_EQ(testObj.getNumItems(), 5);

}

TEST(Memory_Handler_Test, Assignment_Operator_Test)
{
	MemoryHandler<int> testObj(10);
	MemoryHandler<int> emptyTObj;

	for (int i = 0; i < 10; i++)
	{
		testObj.insertItem(i);
	}

	emptyTObj = testObj;

	for (int i = 0; i < 10; i++)
	{
		EXPECT_EQ(emptyTObj.extractItem(), i);
	}
}