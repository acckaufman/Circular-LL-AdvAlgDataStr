//Amanda Kaufman
//CISS350A
//Programming Assignment 4
//This class implements UnsortedType as a circular linked list named CircularType.
//Assumption: ItemType is a type for which the operators "<" and "==" are defined - either as an appropriate built-in
//type or a class that overloads these operators.

#pragma once
#include <cstddef>	//For NULL
#include <new>		//For bad_alloc

template <class ItemType>
struct NodeType
{
	ItemType info;
	NodeType *next;
};

template <class ItemType>
class CircularType
{
private:
	//Variables
	NodeType<ItemType> *listData;
	int length;
	NodeType<ItemType> *currentPos;

	//Auxiliary function that finds an item in the list for use in other functions.
	//Pre: List is not empty.
	//Post: If there is an element someItem whose key matches item's key, then
	//      found = true; otherwise, found = false.  If found, location contains
	//      the address of someItem's predecessor; otherwise, location contains
	//      the address of item's logical successor and predLoc contains the
	//      address of item's logical predecessor.
	void findItem(NodeType<ItemType> *listData, ItemType item, NodeType<ItemType> *&location,
		NodeType<ItemType> *&predLoc, bool &found)
	{
		bool moreToSearch = true;

		location = listData->next;		//Set location to the first item in the list.
		predLoc = listData;				//Set predLoc to the last item in the list.
		found = false;					//Found item flag.
		while (moreToSearch && !found)
		{
			//Note: this block of code was modified for the unsorted implementation of the CircularType ADT.
			if (item == location->info)			//If the search item equals the info in location
			{
				moreToSearch = false;			//we have found a location to put a new item.
				found = true;					//and we have found the item to be retrieved or deleted.
			}
			else
			{
				predLoc = location;
				location = location->next;						//If location is not the front of the list, 
				moreToSearch = (location != listData->next);	//there is still more to search.
			}
		}
	}

public:
	//Class constructor
	CircularType()
	{
		listData = NULL;
		length = 0;
		currentPos = NULL;
	}

	//Class copy constructor.  Parameter passed is 
	CircularType(const CircularType<ItemType>& anotherList)
	{
		NodeType<ItemType> *ptr1;
		NodeType<ItemType> *ptr2;

		//If the list being copied from is empty, make this list empty.
		if (anotherList.listData == NULL)
			listData == NULL;

		//Otherwise, copy items.
		else
		{
			listData = new NodeType<ItemType>;
			listData->info = anotherList.listData->info;
			ptr1 = anotherList.listData->next;
			ptr2 = listData;
			while (ptr1 != anotherList.listData)
			{
				ptr2->next = new NodeType<ItemType>;
				ptr2 = ptr2->next;
				ptr2->info = ptr1->info;
				ptr1 = ptr1->next;
			}
			ptr2->next = listData;
		}

		//Set the length to the length of the list being copied.
		length = anotherList.getLength();
	}

	//Class destructor
	~CircularType()
	{
		makeEmpty();
	}

	void makeEmpty()
	{
		//If the list is already empty, output for debugging purposes.
		if (isEmpty())
			cout << "List is already empty.\n\n";
		//Otherwise, empty the list.
		else
		{
			NodeType<ItemType> *tempPtr;
			NodeType<ItemType> *predLoc;

			//Break the circular list and set last pointer to NULL.
			predLoc = listData;
			listData = listData->next;
			predLoc->next = NULL;

			//Conduct same operation as non-circular list to make empty.
			while (listData != NULL)
			{
				tempPtr = listData;
				listData = listData->next;
				delete tempPtr;
			}

			length = 0;
		}
	}

	//Determines whether the list is empty.
	//Post: Function value = (list is empty).
	bool isEmpty() const
	{
		return (listData == NULL);
	}

	//Determines whether list is full.
	//Post: Function value = (list is full).
	bool isFull() const
	{
		NodeType<ItemType> *location;
		try
		{
			location = new NodeType<ItemType>;
			delete location;
			return false;
		}
		catch (std::bad_alloc exception)
		{
			return true;
		}
	}

	//Determines the number of elements in list.
	//Post: Function value = number of elements in list.
	int getLength() const
	{
		return length;
	}

	//Retrieves list element whose key matches item's key (if present).
	//Pre: Key member of item is initialized.
	//Post: If there is an element someItem whose key matches item's key,
	//      then found = true and item is a copy of someItem; otherwise
	//      found = false and item is unchanged.
	//      List is unchanged.
	void retrieveItem(ItemType &item, bool &found)
	{
		//Placeholder variables for findItem() function.
		NodeType<ItemType> *location;
		NodeType<ItemType> *predLoc;

		//Attempt to find the item in the list.
		findItem(listData, item, location, predLoc, found);
	}

	//Adds item to list.
	//Pre: List is not full.  Item is not in list.
	//Post: Item is in list.
	void insertItem(ItemType item)
	{
		NodeType<ItemType> *newNode;			//Create a pointer to the new node
		newNode = new NodeType<ItemType>;		//Allocate a new node
		newNode->info = item;					//Store item in the new node

		/*Note: This block of code inserts a new item in sorted order.
		        Use this implementation to create a sorted list.
				If sorted implementation is used, findItem() function must be modified.

		NodeType<ItemType> *predLoc;
		NodeType<ItemType> *location;
		bool found;										

		//If the list is not empty, find where the item should go.
		if (listData != NULL)
		{
			findItem(listData, item, location, predLoc, found);
			newNode->next = predLoc->next;		//Insert the item into the list.
			predLoc->next = newNode;

			//If this is the last node in the list, reassign listData (special case).
			if (listData->info < item)
				listData = newNode;
		}

		//Otherwise, insert into an empty list.
		else
		{
		listData = newNode;
		newNode->next = newNode;
		}

		length++;		//Increment the length of the list.

		*/

		//Note: This block of code always inserts a new item at the end of the list.
		//      Use this implementation to create an unsorted list.

		if (listData != NULL)
		{
			newNode->next = listData->next;
			listData->next = newNode;
			listData = newNode;
		}

		//Otherwise, insert into an empty list.
		else
		{
			listData = newNode;
			newNode->next = newNode;
		}

		length++;		//Increment the length of the list.
	}

	//Deletes the element whose key matches item's key.
	//Pre: Key member of item is initialized. One and only one element in list
	//     has a key matching item's key.
	//Post: No element in list has a key matching item's key.
	void deleteItem(ItemType item)
	{
		NodeType<ItemType> *location;
		NodeType<ItemType> *predLoc;
		bool found = false;

		findItem(listData, item, location, predLoc, found);
		if (predLoc == location)	//Only node in the list.
			listData = NULL;		//Make the list empty.
		else
		{
			predLoc->next = location->next;
			if (location == listData)	//Deleting last item in the list (special case).
				listData = predLoc;		//Reassign listData to previous node.
		}
		delete location;	//Delete the node found.
		length--;	//Decrement the length of the list.
	}

	//Initializes current position for an iteration through the list.
	//Post: Current position is prior to start of list.
	void resetList()
	{
		currentPos = listData;
	}

	//Gets the next element in the list.
	//Pre: Current position is defined.  Element at current position is not last in list.
	//Post: Current position is updated to next position.  Item is a copy of element
	//      at current position.
	ItemType getNextItem()
	{
		currentPos = currentPos->next;
		return currentPos->info;
	}
};

