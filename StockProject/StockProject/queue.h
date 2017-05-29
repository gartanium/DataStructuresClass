/***********************************************************************
* Queue: The common Queue data structure.
* Author:
*    Matthew Brown
* Summary:
*    This class implements the common Queue data structure. Most of
*    the logic of the queue is implemented in my memory handler class.
*    It is true that I could have implemented the same logic in the 
*    queue, however, this way helped me to Unit Test my code.
************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#define BAD_ALLOC_MSG "ERROR: Unable to allocate a new buffer for Queue";
#define BAD_POP_MSG "ERROR: attempting to pop from an empty queue";
#define BAD_ACCES_ATTEMPT_MSG "ERROR: attempting to access an item in an empty queue";

#include <iostream>
#include "memoryHandler.h"

#pragma once
/************************************************
* QUEUE
* A class that holds stuff
***********************************************/
template <class T>
class Queue
{
private:
	void resize() throw (const char *);
	MemoryHandler<T> mHandler;
	

public:
	// Empty and kinda useless
	Queue();

	// Copy constructor
	Queue(const Queue & rhs) throw (const char *);

	// non-default constructor : pre-allocate
	Queue(int capacity) throw (const char *);

	// Destructor, free everything!
	~Queue();

	// Am I empty?
	bool empty() const { return mHandler.getNumItems() == 0; }

	// Remove all items from container!
	void clear() { mHandler.clear(); }

	// Capacity of object!
	int capacity() { return mHandler.getSize(); }

	// How many items?
	int size() const { return mHandler.getNumItems(); }

	// Push!
	void push(const T & t) throw (const char *);

	// Pop!
	void pop() throw (const char *);

	T & front() throw (const char *);

	T & back() throw (const char *);

	Queue<T> & operator =(Queue<T> & rhs);
};

#endif

/**********************************************************************
* QUEUE :: resize
* Resizes the queue by double.
***********************************************************************/
template<class T>
void Queue<T>::resize() throw(const char *)
{
	try
	{
		int newCap;

		if (mHandler.getSize() < 2)
		{
			newCap = 2;
		}
		else
			newCap = mHandler.getSize() * 2;

		MemoryHandler<T> newMemHndlr(newCap);

		while (!mHandler.isEmpty())
		{

			T nextItem = mHandler.extractItem();
			newMemHndlr.insertItem(nextItem);
		}

		mHandler = newMemHndlr;
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE :: Default constructor
*
***********************************************************************/
template<class T>
Queue<T>::Queue()
{
}

/**********************************************************************
* QUEUE :: Copy constructor
*
***********************************************************************/
template<class T>
Queue<T>::Queue(const Queue & rhs) throw(const char *)
{
	try
	{
		mHandler = rhs.mHandler;
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE :: non-default Constructor
*
***********************************************************************/
template<class T>
Queue<T>::Queue(int startCap) throw(const char *)
{
	try
	{
		mHandler = MemoryHandler<T>(startCap);
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE :: deconstructor
*
***********************************************************************/
template<class T>
Queue<T>::~Queue()
{
}

/**********************************************************************
* QUEUE :: push
* Pushes an item onto the queue. Checks to see if the capacity is
* empty or not. If it's not empty.
***********************************************************************/
template<class T>
void Queue<T>::push(const T & t) throw(const char *)
{
	try
	{
		if (!mHandler.isFull())
			mHandler.insertItem(t);
		else
		{
			resize();
			mHandler.insertItem(t);
		}
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE ::
*
***********************************************************************/
template<class T>
void Queue<T>::pop() throw(const char *)
{
	try
	{
		mHandler.extractItem();
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE ::
*
***********************************************************************/
template<class T>
T & Queue<T>::front() throw(const char *)
{
	try
	{
		return mHandler.getFront();
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE ::
*
***********************************************************************/
template<class T>
T & Queue<T>::back() throw(const char *)
{
	try
	{
		return mHandler.getBack();
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE :: Assignment Operator.
* 
***********************************************************************/
template<class T>
Queue<T>& Queue<T>::operator=(Queue<T>& rhs)
{
	try
	{
		mHandler = rhs.mHandler;
		return *this;
	}
	catch (char * msg)
	{
		throw msg;
	}
}
