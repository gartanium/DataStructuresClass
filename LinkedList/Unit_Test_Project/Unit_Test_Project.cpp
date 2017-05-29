// Unit_Test_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "node.h"
#include <sstream>
#include <string>
#include "sortInsertion.h"

using namespace std;

TEST(node_Tests, copy_Test)
{
	Node<int> head(0);
	Node<int> n1(1);
	Node<int> n2(2);
	Node<int> n3(3);

	head.pNext = &n1;
	n1.pNext = &n2;
	n2.pNext = &n3;
	n3.pNext = NULL;

	Node<int> * actual = copy(&head);

	EXPECT_EQ(actual->data, 0);
	EXPECT_EQ(actual->pNext->data, 1);
	EXPECT_EQ(actual->pNext->pNext->data, 2);
	EXPECT_EQ(actual->pNext->pNext->pNext->data, 3);
}

TEST(node_Tests, insertion_test)
{

	Node<int> * actual = new Node<int>();
	actual->data = 0;

	insert(1, actual);
	insert(2, actual->pNext);
	insert(3, actual->pNext->pNext);

	EXPECT_EQ(actual->data, 0);
	EXPECT_EQ(actual->pNext->data, 1);
	EXPECT_EQ(actual->pNext->pNext->data, 2);
	EXPECT_EQ(actual->pNext->pNext->pNext->data, 3);

}

TEST(node_Tests, find_test)
{
	Node<int> head(0);
	Node<int> n1(1);
	Node<int> n2(2);
	Node<int> n3(3);

	head.pNext = &n1;
	n1.pNext = &n2;
	n2.pNext = &n3;
	n3.pNext = NULL;

	
    Node<int> * actual = find(&head, 3);

	EXPECT_EQ(actual, &n3);
}

TEST(node_Tests, print_test)
{
	Node<int> head(0);
	Node<int> n1(1);
	Node<int> n2(2);
	Node<int> n3(3);

	head.pNext = &n1;
	n1.pNext = &n2;
	n2.pNext = &n3;
	n3.pNext = NULL;

	string actual;
	stringstream buffer;
	buffer << &head;

	getline(buffer, actual);
	EXPECT_EQ("0, 1, 2, 3", actual);
}

TEST(node_Tests, insert_Then_Print)
{
	Node<int> * testObj = NULL;
	insert(0, testObj);
	insert(1, testObj);
	insert(2, testObj);
	insert(3, testObj);
	insert(4, testObj);
	
	EXPECT_EQ(testObj->data, 0);
	EXPECT_EQ(testObj->pNext->data, 1);
	EXPECT_EQ(testObj->pNext->pNext->data, 2);
	EXPECT_EQ(testObj->pNext->pNext->pNext->data, 3);
	EXPECT_EQ(testObj->pNext->pNext->pNext->pNext->data, 4);
}

TEST(node_Tests, sort_insertion)
{
	int items[] = { 9, 8 , 7, 6, 5 };

	sortInsertion(items, 5);
}

int main(int ac, char* av[])
{
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}

