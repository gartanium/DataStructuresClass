/***********************************************************************
* Header:
*    Stack
* Summary:
*    This class contains the notion of a Stack: a stack of items that
*	 can have it's contents accessed using top(), removed using pop(), or 
*	 added using push().
*
*    This will contain the class definition of:
*        Stack        : A class that holds stuff
* Author
*    Matthew Brown
************************************************************************/

#ifndef STACK_H
#define STACK_H
#define NULL 0
#include <cassert>
#include <new>

// forward declaration for ContainerIterator
template <class T>
class StackIterator;

/************************************************
 * CONTAINER
 * A class that holds stuff
 ***********************************************/
template <class T>
class Stack
{
public:
   // default constructor : empty and kinda useless
   Stack() : numItems(0), cap(0), data(NULL) {}

   // copy constructor : copy it
   Stack(const Stack & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Stack(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Stack()        { if (cap > 0) delete [] data; }
   
   // is the container currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the container
   void clear()        { numItems = 0;                 }

   int capacity()     { return cap;              }

   // how many items are currently in the container?
   int size() const    { return numItems;              }

   // add an item to the container
   void push(const T & t) throw (const char *);

   // Pop
   void pop() throw (const char *);

   T & top() throw (const char *);

   Stack<T> & operator =(Stack<T> & rhs);
   
private:
	
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Container?
   int cap;           // how many items can I put on the Container before full?

   void resize() throw (const char *);     // resizes the array.
};

/*******************************************
 * STACK :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Stack <T> :: Stack(const Stack <T> & rhs) throw (const char *)
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
   catch (std::bad_alloc & ba)
   {
      throw "ERROR: Unable to allocate a new buffer for Stack";
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
 * STACK : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "capacity"
 **********************************************/
template <class T>
Stack <T> :: Stack(int capacity) throw (const char *)
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
   catch (std::bad_alloc & ba)
   {
      throw "ERROR: Unable to allocate a new buffer for Stack";
   }

      
   // copy over the stuff
   this->cap = capacity;
   this->numItems = 0;

   // initialize the container by calling the default constructor
   for (int i = 0; i < capacity; i++)
      data[i] = T();
}

/***************************************************
 * STACK :: PUSH_BACK
 * Insert an item on the end of the container
 **************************************************/
template <class T>
void Stack <T> :: push(const T & t) throw (const char *)
{
   // do we have space?
	if (cap == 0 || cap == numItems)
		resize(); // Resize the array.
   
   // add an item to the end
   data[numItems++] = t;
}

/***************************************************
* STACK :: ASSIGNMENT OPERATOR
* ASSIGN LEFT HAND TO RIGHT HAND.
**************************************************/
template<class T>
inline Stack<T>& Stack<T>::operator=(Stack<T>& rhs)
{

	delete[] data;
	// Do we have enough room?
	try
	{
		data = new T[rhs.cap];
	}
	catch(std::bad_alloc)
	{
		throw "ERROR: Unable to allocate a new buffer for Stack";
	}
	

	cap = rhs.cap;
	numItems = rhs.numItems;

	for (int i = 0; i < rhs.size(); i++)
	{
		data[i] = rhs.data[i];
	}

	return *this;
}



/***************************************************
* STACK :: RESIZE
* RESIZE THE ARRAY
**************************************************/
template <class T>
void Stack <T> ::resize() throw (const char *)
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
			throw "ERROR: Unable to allocate a new buffer for Stack";
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


/***************************************************
* STACK :: Pop
* Pops the last item.
**************************************************/
template <class T>
void Stack <T> ::pop() throw (const char *)
{
	if (numItems < 1)
		throw "ERROR: Unable to pop from an empty Stack";
	else
		numItems--;
}

/***************************************************
* STACK :: top
* returns the top item of the stack by refrence.
**************************************************/
template<class T>
T & Stack<T>::top() throw(const char *)
{
	if(numItems > 0)
		return data[numItems - 1];
	else
		throw "ERROR: Unable to reference the element from an empty Stack";
}

#endif 
