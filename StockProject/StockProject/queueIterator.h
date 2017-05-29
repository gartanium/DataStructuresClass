/***********************************************************************
* Class: QueueIterator
* Author:
*    Matthew Brown
* Summary:
*    Internal iterator for the queue, to handle wrapping around in
*    circle queue format. NOTE: This iterator IS NOT PUBLIC.
************************************************************************/
#pragma once
#ifndef QUEUEITERATOR_H
#define QUEUEITERATOR_H

using namespace std;

class QueueIterator
{
private:
	int size;
	int cursor;

public:
	QueueIterator();
	QueueIterator(int size);
	QueueIterator(const QueueIterator &obj);
	~QueueIterator();

	int leftOf();						// Returns the left index.
	int rightOf();						// Returns the right index.
	int currentIndex();					// Returns the current index.
	QueueIterator& operator++(int);
	QueueIterator& operator =(const QueueIterator & rhs);

	void reset() { cursor = 0; }

	int getSize() { return size; }

};



#endif

