/***********************************************************************
* Queue: The common Queue data structure.
* Author:
*    Matthew Brown
* Summary:
*    This class implements the common Deque data structure. Most of
*    Class uses a custom "iterator" to iterate through the deque.
************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#define BAD_ALLOC_MSG "ERROR: Unable to allocate a new buffer for deque";
#define BAD_ARGUMENT_MSG "ERROR: Invalid argument!";
#define BAD_ACCES_ATTEMPT_MSG "ERROR: unable to access data from an empty deque";
#define BAD_POP_MSG "ERROR: attempting to pop from an empty deque";
#define BAD_FRONT_POP_MSG "ERROR: unable to pop from the front of empty deque";
#define BAD_BACK_POP_MSG "ERROR: unable to pop from the back of empty deque";

#include <iostream>
#include "queueIterator.h"

#pragma once
/************************************************
* QUEUE
* A class that holds stuff
***********************************************/
template <class T>
class Deque
{
private:
	void resize() throw (const char *);
	int mSize;
	int numItems;
	QueueIterator mFront;
	QueueIterator mBack;
	T * data;
	T * alloc(int newSize) throw(const char *);
	

public:
	// Empty and kinda useless
	Deque();

	// Copy constructor
	Deque(const Deque & rhs) throw (const char *);

	// non-default constructor : pre-allocate
	Deque(int capacity) throw (const char *);

	// Destructor, free everything!
	~Deque();

	// Am I empty?
	bool empty() const { return numItems == 0; }

	// Remove all items from container!
	void clear() { numItems = 0; mFront.reset(); mBack.reset(); }

	// Capacity of object!
	int capacity() { return mSize; }

	// How many items?
	int size() const { return numItems;}

	// Push Back!
	void push_back(const T & t) throw (const char *);
	void push_front(const T & t) throw (const char *);

	// Pop Front!
	void pop_front() throw (const char *);
	void pop_back() throw (const char *);

	T & front() throw (const char *);

	T & back() throw (const char *);

	Deque<T> & operator =(Deque<T> & rhs);
};

#endif

/**********************************************************************
* QUEUE :: resize
* Resizes the queue by double.
***********************************************************************/
template<class T>
void Deque<T>::resize() throw(const char *)
{

	try
	{
		int newCap;
		T * newData;

		if (mSize < 2)
		{
			newCap = 2;
		}
		else
		{
			newCap = mSize * 2;
		}

		newData = alloc(newCap);

		// Delete the old data. Set the new data.
		// Set the new size.
		// reset the iterators.
		int iterator = 0;
		while (numItems > 0)
		{
			newData[iterator] = front();
			pop_front();
			iterator++;
		}

		numItems = iterator;
		mFront = QueueIterator(newCap);
		mBack = QueueIterator(newCap);
		delete[] data;
		data = newData;
		mSize = newCap;
		mBack = numItems;
		
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
Deque<T>::Deque()
{
	mSize = 0;
	mFront = QueueIterator(0);
	mBack = QueueIterator(0);
	data = NULL;
	numItems = 0;
}

/**********************************************************************
* QUEUE :: Copy constructor
*
***********************************************************************/
template<class T>
Deque<T>::Deque(const Deque & rhs) throw(const char *)
{
	try
	{
		mSize = rhs.mSize;
		mFront = rhs.mFront;
		mBack = rhs.mBack;
		numItems = rhs.numItems;

		try
		{
			data = alloc(rhs.mSize);
		}
		catch (char * msg)
		{
			throw msg;
		}

		if (mSize > 0 && data != NULL)
		{
			for (int i = 0; i < mSize; i++)
			{
				data[i] = rhs.data[i];
			}
		}
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
Deque<T>::Deque(int newSize) throw(const char *)
{
	try
	{
		mSize = newSize;
		mFront = QueueIterator(newSize);
		mBack = QueueIterator(newSize);
		data = alloc(newSize);
		numItems = 0;
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
Deque<T>::~Deque()
{
	delete[] data;
}

/**********************************************************************
* QUEUE :: push
* Pushes an item onto the queue. Checks to see if the capacity is
* empty or not. If it's not empty.
***********************************************************************/
template<class T>
void Deque<T>::push_back(const T & t) throw(const char *)
{
	try
	{
		// Resize if full.
		if (numItems == mSize || mSize == 0)
			resize();
		
		// Add data to array.
		// First add item then incriment cursor!
		data[mBack.currentIndex()] = t;
		mBack++;
		numItems++;
		
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE :: Push_Front
* Push's the item to the front!
***********************************************************************/
template<class T>
inline void Deque<T>::push_front(const T & t) throw(const char *)
{
	try
	{
		// Full ? Resize!
		if (numItems == mSize || mSize == 0)
			resize();
		
		// Add item to front.
		// First decriment front cursor, then set data!
		// - - - - f b - -
		mFront--;
		data[mFront.currentIndex()] = t;
		numItems++;

		
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUE ::pop front
* Pops the front item!
***********************************************************************/
template<class T>
void Deque<T>::pop_front() throw(const char *)
{
	try
	{
		if (mSize > 0 && numItems > 0)
		{
			// - - - f x x x b - - -
			numItems--;
			mFront++;
		}
		else
			throw BAD_FRONT_POP_MSG;
	}
	catch (char * msg)
	{
		throw msg;
	}
}

template<class T>
inline void Deque<T>::pop_back() throw(const char *)
{
	try
	{
		if (mSize > 0 && numItems > 0)
		{
			// - - - f x x x b - - -
			// - - - f x x b - - - -
			numItems--;
			mBack--;
		}
		else
			throw BAD_BACK_POP_MSG;
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
T & Deque<T>::front() throw(const char *)
{
	try
	{
		if (numItems > 0)
		{
			return data[mFront.currentIndex()];
		}
		else
		{
			throw BAD_ACCES_ATTEMPT_MSG;
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
T & Deque<T>::back() throw(const char *)
{
	try
	{
		if (numItems > 0)
		{
			return data[mBack.leftOf()];
		}
		else
		{
			throw BAD_ACCES_ATTEMPT_MSG;
		}
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
Deque<T>& Deque<T>::operator=(Deque<T>& rhs)
{
	// First delete data
	delete[] data;

	mSize = rhs.mSize;
	mFront = rhs.mFront;
	mBack = rhs.mBack;
	numItems = rhs.numItems;

	try
	{
		data = alloc(mSize);

		for (int i = 0; i < rhs.mSize; i++)
		{

			data[i] = rhs.data[i];
		}
	}
	catch (char * msg)
	{
		throw msg;
	}

	return *this;
}

/************************************************
* DEQUE: alloc
* Allocates more memory for data.
***********************************************/
template<class T>
T * Deque<T>::alloc(int newSize) throw(const char *)
{
	if (newSize > 0)
	{
		try
		{
			T * newAllocatedArray = new T[newSize];
			return newAllocatedArray;

		}
		catch (std::bad_alloc & ba)
		{
			throw BAD_ALLOC_MSG;
		}
	}
	else
	{
		return NULL;
	}
}