/***********************************************************************
* Header:
*    Container
* Summary:
*    This class contains the notion of a container: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the vector, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Container         : A class that holds stuff
*        ContainerIterator : An interator through Container
* Author
*    Br. Helfrich
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>

// forward declaration for ContainerIterator
template <class T>
class VectorIterator;

/************************************************
 * CONTAINER
 * A class that holds stuff
 ***********************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()        { if (cap > 0) delete [] data; }
   
   // is the container currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the container
   void clear()        { numItems = 0;                 }

   int capacity()     { return cap;              }

   // how many items are currently in the container?
   int size() const    { return numItems;              }

   // add an item to the container
   void push_back(const T & t) throw (const char *);
   
   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}

   Vector<T> & operator =(Vector<T> & rhs);
   
   T & operator[](int index) throw (const char *);

   T & operator[](const int & index) const throw (const char *);
   
private:
	
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Container?
   int cap;           // how many items can I put on the Container before full?

   void resize() throw (const char *);     // resizes the array.
};

/**************************************************
 * VECTOR ITERATOR
 * An iterator through Container
 *************************************************/
template <class T>
class VectorIterator
{
  public:
   // default constructor
  VectorIterator() : p(NULL) {}

   // initialize to direct p to some item
  VectorIterator(T * p) : p(p) {}


   // not equals operator
   bool operator != (const VectorIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   VectorIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   VectorIterator <T> operator++(int postfix)
   {
      VectorIterator tmp(*this);
      p++;
      return tmp;
   }


   
  private:
   T * p;
};

/*******************************************
 * VECTOR :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
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
   catch (std::bad_alloc)
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
 * VECTOR : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "capacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int capacity) throw (const char *)
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
   catch (std::bad_alloc)
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
 * VECTOR :: PUSH_BACK
 * Insert an item on the end of the container
 **************************************************/
template <class T>
void Vector <T> :: push_back(const T & t) throw (const char *)
{
   // do we have space?
	if (cap == 0 || cap == numItems)
		resize(); // Resize the array.
   
   // add an item to the end
   data[numItems++] = t;
}

/***************************************************
* VECTOR :: ASSIGNMENT OPERATOR
* ASSIGN LEFT HAND TO RIGHT HAND.
**************************************************/
template<class T>
inline Vector<T>& Vector<T>::operator=(Vector<T>& rhs)
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
* VECTOR :: INDEX
* Access values through index.
**************************************************/
template<class T>
inline T & Vector<T>::operator[](int index) throw (const char *)
{
	if(index > size() || index < 0 || size() == 0)
	{
		throw "ERROR: Invalid index";
	}
	else
	{
		return data[index];
	}
}

/***************************************************
* VECTOR :: INDEX
* Access values through index.
**************************************************/
template<class T>
inline T & Vector<T>::operator[](const int & index) const throw (const char *)
{
	if (index > size() || index < 0 || size() == 0)
	{
		throw "ERROR: Invalid index";
	}
	else
	{
		return data[index];
	}
}

#endif // CONTAINER_H

/***************************************************
* VECTOR :: RESIZE
* RESIZE THE ARRAY
**************************************************/
template <class T>
void Vector <T> ::resize() throw (const char *)
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
		catch (std::bad_alloc)
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
		catch (std::bad_alloc)
		{
			throw "ERROR: Unable to allocate buffer";
		}

		data = newData;
	}
}