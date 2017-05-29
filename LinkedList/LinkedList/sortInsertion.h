/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Matthew Brown
 ************************************************************************/
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
	// Cycle through. Start with the last inserted item.
	for (int i = 0; i < num; i++)
	{
		
		T nextItem = array[i];
		if (head == NULL)
		{
			insert(nextItem, head);
		}
		else if (nextItem < head->data)
		{
			insert(nextItem, head, true);
		}
		else
		{

			// Now figure out where it belongs in the linked list.
			//If it's bigger, add at the end!
			Node<T> * current = head;

			while (current->pNext != NULL && current->pNext->data < nextItem)
			{
				current = current->pNext;
			}

			insert(nextItem, current);
		}
		
	}

	Node<T> * current = head;

	for (int i = 0; i < num; i++)
	{
		
		array[i] = current->data;
		current = current->pNext;
		
	}

	freeData(head);
}

#endif // INSERTION_SORT_H

