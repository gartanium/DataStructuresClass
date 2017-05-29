/***********************************************************************
* Class: Memory Handler
* Author:
*    Matthew Brown
* Summary:
*    Contains most the logic for the queue, other than resizing.
*	 Contains an iterator to handle wrapping around for the circle queue.
************************************************************************/
#pragma once
#ifndef MEMORYHANDLER_H
#define MEMORYHANDLER_H

#define BAD_ALLOC_MSG "ERROR: Unable to allocate a new buffer for Queue";
#define BAD_ARGUMENT_MSG "ERROR: Invalid argument!";
#define BAD_ACCES_ATTEMPT_MSG "ERROR: attempting to access an item in an empty queue";
#define BAD_POP_MSG "ERROR: attempting to pop from an empty queue";

#define NULL 0

#include "queueIterator.h"
#include <exception>
#include <new>


template <class T>
class MemoryHandler
{

private:
	int size;
	int numItems;
	QueueIterator front;
	QueueIterator back;
	T * data;
	T * alloc(int newSize) throw(const char *);

public:
	MemoryHandler();
	MemoryHandler(int size);
	MemoryHandler(const MemoryHandler &obj) throw(const char *);
	~MemoryHandler();

	bool isFull() { return numItems == size; }
	bool isEmpty() { return numItems == 0; }

	T & getFront();
	T & getBack();

	void insertItem(T t);
	T extractItem();

	MemoryHandler<T> & operator =(const MemoryHandler<T> & rhs);

	int getSize() { return size; }
	int getNumItems() const { return numItems; }

	void clear();
};



#endif

/************************************************
* MEMORYHANDLER: Default Constructor
* 
***********************************************/
template<class T>
MemoryHandler<T>::MemoryHandler()
{
	size = 0;
	front = QueueIterator(0);
	back = QueueIterator(0);
	data = NULL;
	numItems = 0;
}

/************************************************
* MEMORYHANDLER: Constructor
*
***********************************************/
template<class T>
MemoryHandler<T>::MemoryHandler(int newSize)
{
	size = newSize;
	front = QueueIterator(newSize);
	back = QueueIterator(newSize);
	data = alloc(newSize);
	numItems = 0;

}

/************************************************
* MEMORYHANDLER: Copy Constructor
*
***********************************************/
template<class T>
MemoryHandler<T>::MemoryHandler(const MemoryHandler &obj) throw(const char *)
{
	size = obj.size;
	front = obj.front;
	back = obj.back;
	numItems = obj.numItems;

	try
	{
		data = alloc(obj.size);
	}
	catch(char * msg)
	{
		throw msg;
	}

	if (size > 0 && data != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			data[i] = obj.data[i];
		}
	}

}

/************************************************
* MEMORYHANDLER: deconstructor
*
***********************************************/
template<class T>
MemoryHandler<T>::~MemoryHandler()
{
	delete[] data;
}

/************************************************
* MEMORYHANDLER: getBack
* Returns the back item in memory.
***********************************************/
template<class T>
T & MemoryHandler<T>::getBack()
{
	try
	{
		if (numItems > 0)
		{
			return data[back.leftOf()];
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

/************************************************
* MEMORYHANDLER: get Front
* Returns the front item in memory.
***********************************************/
template<class T>
T & MemoryHandler<T>::getFront()
{
	try
	{
		if (numItems > 0)
		{
			return data[front.currentIndex()];
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

/************************************************
* MEMORYHANDLER: Insert Item
* Inserts an item into memory at the front.
***********************************************/
template<class T>
void MemoryHandler<T>::insertItem(T t)
{
	if (!isFull() && size > 0)
	{
		data[back.currentIndex()] = t;
		back++;
		numItems++;
	}
}

/************************************************
* MEMORYHANDLER: Extract Item.
* Extracts the last item in memory
***********************************************/
template<class T>
T MemoryHandler<T>::extractItem()
{
	if (size > 0 && numItems > 0)
	{
		/*T returnObj = data[front.currentIndex()];
		front++;
		numItems--;
		return returnObj;*/

		numItems--;
		front++;
		return data[front.leftOf()];
	}
	else
		throw BAD_POP_MSG;
}

/************************************************
* MEMORYHANDLER: Assignment operator
* Copys rhs to this value.
***********************************************/
template<class T>
MemoryHandler<T>& MemoryHandler<T>::operator=(const MemoryHandler<T>& rhs)
{
	// First delete data
	delete[] data;
	
	size = rhs.size;
	front = rhs.front;
	back = rhs.back;
	numItems = rhs.numItems;

	try 
	{
		data = alloc(size);

		for (int i = 0; i < rhs.size; i++)
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
* MEMORYHANDLER: Clear
* Clears the memory.
***********************************************/
template<class T>
inline void MemoryHandler<T>::clear()
{
	numItems = 0;
	front.reset();
	back.reset();
	
}

/************************************************
* MEMORYHANDLER: alloc
* Allocates more memory for data.
***********************************************/
template<class T>
T * MemoryHandler<T>::alloc(int newSize) throw(const char *)
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

