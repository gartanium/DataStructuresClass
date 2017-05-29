/***********************************************************************
* Header:
*    Node
* Summary:
*    Contains a basic Node with data and a pointer to the next Node.
* Author
*    Matthew Brown
************************************************************************/
#pragma once
#ifndef NODE_H
#define NODE_H

#define NULL 0
#include <iostream>
using namespace std;

template <class T>
class Node
{

public:
	T data;
	Node<T> * pNext;
	Node() { pNext = NULL; }
	Node(T t) { data = t; pNext = NULL; }
	~Node();
};

#endif

/**********************************************************************
* Copy
* Copys a linked list starting at Head. Returns it.
***********************************************************************/
template <class T>
Node<T> * copy(Node<T> * head)
{

	Node<T> * current = new Node<T>();

	current->data = head->data;
	
	if (head->pNext != NULL)
	{
		current->pNext = copy(head->pNext);
	}

	return current;
}

/**********************************************************************
* Insert
* Inserts a new node into the current linked-list
***********************************************************************/
template <class T>
void insert(T t, Node<T> * &preceding, bool optionHead = false)
{
	Node<T> * newNode = new Node<T>();
	newNode->data = t;
	
	// Is preceding empty?
	if (preceding == NULL)
	{
		preceding = newNode; 
	}
	// Insert it at the beginning with preceding being the new one. 
	else if (optionHead)
	{
		newNode->pNext = preceding;
		preceding = newNode;
	}
	else
	{
		newNode->pNext = preceding->pNext;
		preceding->pNext = newNode;
	}
}

/**********************************************************************
* find
* Find the node corresponding to a given passed value from a given
* Linked List
***********************************************************************/
template <class T>
Node<T> * find(Node<T> * head, T t)
{
	// When Null, we have reached the end!
	if (head->pNext != NULL)
	{
		if (head->data == t)
			return head;
		else
			return find(head->pNext, t);
	}
	else if (head->data == t)
		return head;
	else
		return NULL;
}

/**********************************************************************
* Insertion operator
* Inserts the contents of the linked list into the iostream.
***********************************************************************/
template <class T>
ostream& operator<<(ostream& os, const Node<T>* const & head)
{
	//Copy our itterator!
	const Node<T> * current = head;
	if (current == NULL)
	{
		return os;
	}
	// Add any Node that has a node after it!
	while (current->pNext != NULL)
	{
		os << current->data << ", ";
		current = current->pNext;
	}

	// Add the tail!
	os << current->data;
	
	return os;
}

/**********************************************************************
* freeData
* Frees the content of a linked list.
***********************************************************************/
template <class T>
void freeData(Node<T> * &head)
{
	// Step through to end
	if (head->pNext != NULL)
	{
		freeData(head->pNext); // Recursion!
	}

	// Free data for each function call.
	delete head;
	head = NULL;
}

/**********************************************************************
* Deconstructor
* Frees data associated with node.
***********************************************************************/
template<class T>
Node<T>::~Node()
{

}
