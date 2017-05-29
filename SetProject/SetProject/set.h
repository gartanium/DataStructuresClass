/***********************************************************************
* Header:
*    Set
* Summary:
*    This class contains the notion of a set. Also, the set is sorted.
*
*    This will contain the class definition of:
*        Set        : A class that holds stuff
*        SetIterator : An interator through Set
* Author
*    Matthew Brown
************************************************************************/
#ifndef SET_H
#define SET_H
#define NULL 0
#pragma once

#define BAD_SHIFT_MESSAGE "ERROR: Improper shift!"
#define BAD_ERASE_INDEX_MESSAGE "ERROR: index out of range!"

#include <cassert>
#include <math.h>
#include <new>

// forward declaration for SetIterator
template <class T>
class SetIterator;

/************************************************
* Set
* A class that holds stuff
***********************************************/
template <class T>
class Set
{
public:
	// default constructor : empty and kinda useless
	Set() : numItems(0), cap(0), data(NULL) {}

	// copy constructor : copy it
	Set(const Set & rhs) throw (const char *);

	// non-default constructor : pre-allocate
	Set(int capacity) throw (const char *);

	// destructor : free everything
	~Set() { if (cap > 0) delete[] data; }

	// is the container currently empty
	bool empty() const { return numItems == 0; }

	// remove all the items from the container
	void clear() { numItems = 0; }

	int capacity() { return cap; }

	// how many items are currently in the container?
	int size() const { return numItems; }

	// Insert an item into the set.	
	void insert(T t) throw (const char *);

	void erase(int index) throw (const char *);

	// return an iterator to the beginning of the list
	SetIterator <T> begin() { return SetIterator<T>(data); }

	// return an iterator to the end of the list
	SetIterator <T> end() { return SetIterator<T>(data + numItems); }

	void shiftLeft(T * begin);

		void shiftRight(T * end);

	Set<T> & operator =(Set<T> & rhs);

	Set<T> operator&&(const Set<T> & right);
	Set<T> operator||(const Set<T> & right);

	void swap(T * left, T * right);

	int find(T t);

private:

	T * data;          // dynamically allocated array of T
	int numItems;      // how many items are currently in the Container?
	int cap;           // how many items can I put on the Container before full?

	void resize() throw (const char *);     // resizes the array.

};

/**************************************************
* Set ITERATOR
* An iterator through Set
*************************************************/
template <class T>
class SetIterator
{
public:
	// default constructor
	SetIterator() : p(NULL) {}

	// initialize to direct p to some item
	SetIterator(T * p) : p(p) {}


	// not equals operator
	bool operator != (const SetIterator & rhs) const
	{
		return rhs.p != this->p;
	}

	// dereference operator
	T & operator * ()
	{
		return *p;
	}

	// prefix increment
	SetIterator <T> & operator ++ ()
	{
		p++;
		return *this;
	}

	// postfix increment
	SetIterator <T> operator++(int postfix)
	{
		SetIterator tmp(*this);
		p++;
		return tmp;
	}

	T * toPointer() { return p; }


private:
	T * p;
};

/*******************************************
* Set :: COPY CONSTRUCTOR
*******************************************/
template <class T>
Set <T> ::Set(const Set <T> & rhs) throw (const char *)
{
	assert(rhs.cap >= 0);

	// do nothing if there is nothing to do
	if (rhs.cap == 0)
	{
		cap = numItems = 0;
		data = NULL;
		return;
	}

	// attempt to allocate
	try
	{
		data = new T[rhs.cap];
	}
	catch (std::bad_alloc ba)
	{
		throw "ERROR: Unable to allocate buffer";
	}

	// copy over the capacity and size
	assert(rhs.numItems >= 0 && rhs.numItems <= rhs.cap);
	cap = rhs.cap;
	numItems = rhs.numItems;

	// copy the items over one at a time using the assignment operator
	for (int i = 0; i < numItems; i++)
		data[i] = rhs.data[i];

	// the rest needs to be filled with the default value for T
	for (int i = numItems; i < cap; i++)
		data[i] = T();
}

/**********************************************
* Set : NON-DEFAULT CONSTRUCTOR
* Preallocate the container to "capacity"
**********************************************/
template <class T>
Set <T> ::Set(int capacity) throw (const char *)
{
	assert(capacity >= 0);

	// do nothing if there is nothing to do
	if (capacity == 0)
	{
		this->cap = this->numItems = 0;
		this->data = NULL;
		return;
	}

	// attempt to allocate
	try
	{
		data = new T[capacity];
	}
	catch (std::bad_alloc ba)
	{
		throw "ERROR: Unable to allocate buffer";
	}


	// copy over the stuff
	this->cap = capacity;
	this->numItems = 0;

	// initialize the container by calling the default constructor
	for (int i = 0; i < capacity; i++)
		data[i] = T();
}

/***************************************************
* Set :: INSERT
* Inserts an item into thes et.
**************************************************/
template<class T>
void Set<T>::insert(T t) throw(const char *)
{
	// Are we out of space? Resize!
	if (cap == numItems)
	{
		resize();
	}


	// If only one item, add it!
	if (numItems == 0)
	{
		data[0] = t;
		numItems++;
	}
	// Else, sort it! 
	else
	{
		for (int i = 0; i < numItems; i++)
		{
			// If item is less then a given item, put it in front!
			if (data[i] > t)
			{
				shiftRight(data + i);
				data[i] = t;
				numItems++;
				return;
			}
			// Is the item in the set already? Return!
			else if (data[i] == t)
			{
				return;
			}
			// If there are no more items in the set, add it at the end!
			else if (i + 1 == numItems)
			{
				data[i + 1] = t;
				numItems++;
				return;
			}
		}
	}


}

/***************************************************
* Set :: ERASE
* Erases an element at a given indx
**************************************************/
template<class T>
void Set<T>::erase(int index) throw(const char *)
{
	if (index < numItems && index >= 0)
	{
		if (numItems == 1)
		{
			numItems--;
		}
		else if (numItems > 1)
		{
			shiftLeft(data + index);
			numItems--;
		}
	}
	else
		throw BAD_ERASE_INDEX_MESSAGE;
}

/***************************************************
* Set :: SHIFT LEFT
* Shifts all elements left by 1
* T * begin: Should contain nothing. (Extraction)
**************************************************/
template<class T>
void Set<T>::shiftLeft(T * beg)
{
	if (numItems > 1)
	{
		// Problems: This function could cause problems if
		// The number of items isn't decrimented.
		// Essentialy, we want our removed value to be over written!
		T * itEnd = data + numItems - 1;

		for (beg; beg < itEnd; beg++)
		{
			*beg = *(beg + 1);

		}
	}
}

/***************************************************
* Set :: SHIFT RIGHT
* Shifts all elements right by 1
* T * begin: Should contain nothing. (Insertion)
**************************************************/
template<class T>
void Set<T>::shiftRight(T * beg)
{
	// Because we don't subtract one, it brings in the end spacer!
	T * it = data + numItems;

	for (; it >= beg + 1; it--)
	{
		swap(it, it - 1);
	}

}

/***************************************************
* Set :: ASSIGNMENT OPERATOR
* ASSIGN LEFT HAND TO RIGHT HAND.
**************************************************/
template<class T>
Set<T>& Set<T>::operator=(Set<T>& rhs)
{

	delete[] data;
	data = new T[rhs.cap];
	cap = rhs.cap;
	numItems = rhs.numItems;

	for (int i = 0; i < rhs.size(); i++)
	{
		data[i] = rhs.data[i];
	}

	return *this;
}

/***************************************************
* Set :: INTERSECTION OPERATOR
* Returns a new set of items that both sets contain.
**************************************************/
template<class T>
Set<T> Set<T>::operator&&(const Set<T>& right)
{
	Set<T> commonSet;
	int lhsIterator = 0;
	int rhsIterator = 0;

	// Algorithims looks at two sides. Which ever set has the lesser
	// Item iterates it's iterator. Otherwise, it adds it to the set.
	while (lhsIterator < numItems && rhsIterator < right.numItems)
	{
		if (data[lhsIterator] < right.data[rhsIterator])
			lhsIterator++;
		else if (right.data[rhsIterator] < data[lhsIterator])
			rhsIterator++;
		else
		{
			commonSet.insert(data[lhsIterator]);
			lhsIterator++;
			rhsIterator++;
		}
	}

	return commonSet;
}

template<class T>
Set<T> Set<T>::operator||(const Set<T>& right)
{
	Set<T> diffrenceSet;
	//int lhsIterator = 0;
	//int rhsIterator = 0;

	//// Algorithims looks at two sides. Which ever set has the lesser
	//// Item iterates it's iterator. Otherwise, it adds it to the set.
	//while (lhsIterator < numItems && rhsIterator < right.numItems)
	//{
	//	if (data[lhsIterator] < right.data[rhsIterator])
	//	{
	//		// Add the lesser item!
	//		diffrenceSet.insert(data[lhsIterator]);
	//		lhsIterator++;
	//
	//	}
	//	else if (right.data[rhsIterator] < data[lhsIterator])
	//	{
	//		// Add the lesser item!
	//		diffrenceSet.insert(right.data[rhsIterator]);
	//		rhsIterator++;
	//	}
	//	else
	//	{
	//		// Iterate both!
	//		lhsIterator++;
	//		rhsIterator++;
	//	}
	//}

	// Now, add any remaining items for ether sets
	for (int lhsIterator = 0; lhsIterator < numItems; lhsIterator++)
	{
		diffrenceSet.insert(data[lhsIterator]);

	}
	for (int rhsIterator = 0; rhsIterator < right.numItems; rhsIterator++)
	{
		diffrenceSet.insert(right.data[rhsIterator]);
	}

	return diffrenceSet;
}

/***************************************************
* Set :: SWAP
* SWAP LEFT AND RIGHT
**************************************************/
template<class T>
void Set<T>::swap(T * left, T * right)
{
	T temp = *left;
	*left = *right;
	*right = temp;
}

/***************************************************
* Set :: FIND
* Returns the index of the item. If not found, 
returns -1;
**************************************************/
template<class T>
int Set<T>::find(T t)
{
	int left = 0, right = numItems - 1;

	while (true)
	{
		if (right >= left)
		{
			int middle = floor((right + left) / 2);
			if (data[middle] < t)
			{
				left = middle + 1; 
			}
			else if (data[middle] > t)
			{
				right = middle - 1;
			}
			else if (data[middle] == t)
			{					
				return middle;
			}
		}
		else
		{
			return -1;
		}
	}

}

#endif 

/***************************************************
* Set :: RESIZE
* RESIZE THE ARRAY
**************************************************/
template <class T>
void Set <T> ::resize() throw (const char *)
{
	T * newData;

	if (cap != 0)
	{

		// Dynamicaly allocate a new array that is double the size of before.
		try
		{
			cap *= 2;
			newData = new T[cap];

		}
		catch (std::bad_alloc ba)
		{
			throw "ERROR: Unable to allocate buffer";
		}

		// Copy over all the crap to the new array.
		for (int i = 0; i < numItems; i++)
		{

			newData[i] = data[i];

		}

		// Set the address of the old array equal to the new array.
		delete[] data;
		data = newData;


	}
	else
	{
		cap = 1;

		try
		{
			newData = new T[cap];

		}
		catch (std::bad_alloc ba)
		{
			throw "ERROR: Unable to allocate buffer";
		}

		data = newData;
	}
}