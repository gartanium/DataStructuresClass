/***********************************************************************
* Class: QueueIterator
* Author:
*    Matthew Brown
* Summary:
*    Internal iterator for the queue, to handle wrapping around in
*    circle queue format. NOTE: This iterator IS NOT PUBLIC.
************************************************************************/
#include "queueIterator.h"

/**********************************************************************
* QUEUEITERATOR :: Default constructor
*
***********************************************************************/
QueueIterator::QueueIterator()
{
	size = 0;
	cursor = 0;
}

/**********************************************************************
* QUEUEITERATOR :: Non Default constructor
*
***********************************************************************/
QueueIterator::QueueIterator(int newSize)
{
	size = newSize;
	cursor = 0;
}

/**********************************************************************
* QUEUEITERATOR :: Copy Constructor
*
***********************************************************************/
QueueIterator::QueueIterator(const QueueIterator & obj)
{
	size = obj.size;
	cursor = obj.cursor;
}

/**********************************************************************
* QUEUEITERATOR :: de-constructor
*
***********************************************************************/
QueueIterator::~QueueIterator()
{
}

/**********************************************************************
* QUEUEITERATOR :: left of
* Returns left index.
***********************************************************************/
int QueueIterator::leftOf()
{
	try
	{
		if (size > 1)
		{
			if (cursor - 1 >= 0)
			{
				return cursor - 1;
			}
			else
			{
				return size - 1;
			}
		}
		else
			throw "ERROR: There aren't enough elements in the iterator!";
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUEITERATOR :: right of
* Returns right of index.
***********************************************************************/
int QueueIterator::rightOf()
{
	try
	{
		// Do we even have anything?
		if (size > 1)
		{
			if (cursor + 1 < size)
			{
				return cursor + 1;
			}
			else
			{
				return 0;
			}
		}
		else
			throw "ERROR: There aren't enough elements in the iterator!";
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUEITERATOR :: Current index
* Returns the Current Index
***********************************************************************/
int QueueIterator::currentIndex()
{
	try
	{
		if (size > 0)
		{
			return cursor;
		}
		else
			throw "ERROR: There arent any elements in the iterator!";
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUEITERATOR :: Incriment operator.
* Incriments the iterator.
***********************************************************************/
QueueIterator & QueueIterator::operator++(int)
{
	// TODO: If the cursor reaches the end, set it to 0.
	try
	{
		if (size != 0)
		{
			if (cursor + 1 < size)
			{
				cursor++;
				return *this;
			}
			else
			{
				cursor = 0;
				return *this;
			}
		}
		else
			throw "ERROR: Size is 0!";
	}
	catch (char * msg)
	{
		throw msg;
	}
}

/**********************************************************************
* QUEUEITERATOR :: decriment operator.
* decriments the iterator.
***********************************************************************/
QueueIterator & QueueIterator::operator--(int)
{
	// C x x x x
	// TODO: If the cursor reaches the end, set it to 0.
	try
	{
		if (size != 0)
		{
			if (cursor != 0)
			{
				cursor--;
				return *this;
			}
			else
			{
				cursor = size - 1;
				return *this;
			}
		}
		else
			throw "ERROR: Size is 0!";
	}
	catch (char * msg)
	{
		throw msg;
	}


}

/**********************************************************************
* QUEUEITERATOR :: Assignment operator
* Assigns the iterator's values.
***********************************************************************/
QueueIterator & QueueIterator::operator=(const QueueIterator & rhs)
{
	cursor = rhs.cursor;
	size = rhs.size;
	return *this;
}

QueueIterator & QueueIterator::operator=(const int & rhs)
{
	if (size > 0)
	{
		if (rhs < size && rhs >= 0)
		{
			cursor = rhs;
		}
		else
			throw "Error, argument out of range!";
	}
	else
		throw "Error, argument out of range!";
}

