/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Matthew Brown
 ************************************************************************/
#include "stdafx.h"
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
	Node<T> * head = NULL;
	cout << "   aaaaaaa        HI " << endl; << endl;
	// Cycle through. Start with the last inserted item.
	for (int i = 0; i < num; i++)
	{
		cerr << "Here" << endl;
		T nextItem = array[i];
		if (head == NULL)
		{

			insert(nextItem, head);
			continue;
		}
		else if (nextItem >= head->data)
		{

			insert(nextItem, head);
		}
		else
		{

			// Now figure out where it belongs in the linked list.
			//If it's bigger, add at the end!
			Node<T> * current = head;

			while (current->data < nextItem)
			{

				current = current->pNext;
			}

			insert(nextItem, current);
		}
		
	}

	Node<T> * current = head;

	for (int i = 0; i < num; i++)
	{
		cerr << "Here" << endl;
		array[i] = current->data;
		current = current->pNext;
		
	}

	freeData(head);
}

#endif // INSERTION_SORT_H

