//Amanda Kaufman
//CISS350A
//Programming Assignment 4
//This test driver demonstrates the unsorted CircularType ADT.

#include <iostream>
#include <fstream>
#include "CircularType.h"
using namespace std;

//Function prototype
void displayList(CircularType<int> &, ofstream &);

int main()
{
	//Open an output file for writing.
	ofstream outFile;
	outFile.open("test.out");

	cout << "Begin test driver for the CircularType ADT.\n\n";
	outFile << "Begin test driver for the CircularType ADT.\n\n";

	//Create a CircularType object named List1 to hold integers.
	cout << "Now creating a circular linked list of integers...\n";
	outFile << "Now creating a circular linked list of integers...\n";
	CircularType<int> List1;
	cout << "Done.\n\n";
	outFile << "Done.\n\n";

	//Test inserting an item into the empty list.
	cout << "Now inserting 2 into the list...\n";
	outFile << "Now inserting 2 into the list...\n";
	List1.insertItem(2);
	cout << "Done.\n\n";
	outFile << "Done.\n\n";

	//Output the contents of the list.
	displayList(List1, outFile);

	//Test inserting random items into the list that already contains items.
	cout << "Now inserting 5, 8, 1, and 7 into the list...\n";
	outFile << "Now inserting 5, 8, 1, and 7 into the list...\n";
	List1.insertItem(5);
	List1.insertItem(8);
	List1.insertItem(1);
	List1.insertItem(7);
	cout << "Done.\n\n";
	outFile << "Done.\n\n";

	//Output the contents of the list.
	displayList(List1, outFile);

	//Test the copy constructor by making another list named List2.
	cout << "Now copying List1 into a new List2 using the copy constructor...\n";
	outFile << "Now copying List1 into a new List2 using the copy constructor...\n";
	CircularType<int> List2(List1);
	cout << "Done.\n\n";
	outFile << "Done.\n\n";

	//Output the contents of List1.
	cout << "List1:\n";
	outFile << "List1:\n";
	displayList(List1, outFile);

	//Output the contents of List2.
	cout << "List2:\n";
	outFile << "List2:\n";
	displayList(List2, outFile);

	//Test the makeEmpty() function on List2.
	cout << "Now emptying List2...\n";
	outFile << "Now emptying List2...\n";
	List2.makeEmpty();
	cout << "Done.\n\n";
	outFile << "Done.\n\n";

	//Output the contents of List2.
	cout << "List2:\n";
	outFile << "List2:\n";
	displayList(List2, outFile);

	//Attempt to retrieve an item not in the list, using List1.
	bool foundInt = false;
	int testInt = 4;
	cout << "Attempting to find 4 in List1...\n";
	outFile << "Attempting to find 4 in List1...\n";
	List1.retrieveItem(testInt, foundInt);
	if (foundInt)
	{
		cout << testInt << " was found in the list.\n\n";
		outFile << testInt << " was found in the list.\n\n";
	}
	else
	{
		cout << "404! Item not found.\n\n";
		outFile << "404! Item not found.\n\n";
	}
	system("pause");
	cout << endl;

	//Attempt to retrieve an item that is in List1.
	foundInt = false;
	testInt = 5;
	cout << "Attempting to find 5 in List1...\n";
	outFile << "Attempting to find 5 in List1...\n";
	List1.retrieveItem(testInt, foundInt);
	if (foundInt)
	{
		cout << testInt << " was found in the list.\n\n";
		outFile << testInt << " was found in the list.\n\n";
	}
	else
	{
		cout << "404! Item not found.\n\n";
		outFile << "404! Item not found.\n\n";
	}
	system("pause");
	cout << endl;

	//Test the isEmpty() function on List1 while it contains items.
	cout << "Now testing whether List1 is empty...\n";
	outFile << "Now testing whether List1 is empty...\n";
	bool emptyList = List1.isEmpty();
	cout << "Done.\n";
	outFile << "Done.\n";
	if (emptyList)
	{
		cout << "List1 is empty.\n\n";
		outFile << "List1 is empty.\n\n";
	}
	else if (!emptyList)
	{
		cout << "List1 has items.\n\n";
		outFile << "List1 has items.\n\n";
	}
	system("pause");
	cout << endl;

	//Test the isFull() function on List1.
	cout << "Now testing whether List1 is full...\n";
	outFile << "Now testing whether List1 is full...\n";
	bool fullList = List1.isFull();
	cout << "Done.\n";
	outFile << "Done.\n";
	if (fullList)
	{
		cout << "No more memory available to add to List1.\n\n";
		outFile << "No more memory available to add to List1.\n\n";
	}
	else if (!fullList)
	{
		cout << "There is still memory available to add to List1.\n\n";
		outFile << "There is still memory available to add to List1.\n\n";
	}
	system("pause");
	cout << endl;

	//Test deleteItem() on the item at the end of List1.
	cout << "Now deleting the last item (7) in List1...\n";
	outFile << "Now deleting the last item (7) in List1...\n";
	List1.deleteItem(7);
	cout << "Done.\n\n";
	outFile << "Done.\n\n";

	//Output the contents of List1.
	cout << "List1:\n";
	outFile << "List1:\n";
	displayList(List1, outFile);

	//Delete the remaining items in List1.
	cout << "Now deleting the remaining items in List1...\n";
	outFile << "Now deleting the remaining items in List1...\n";
	List1.deleteItem(1);
	List1.deleteItem(2);
	List1.deleteItem(5);
	List1.deleteItem(8);
	cout << "Done.\n\n";
	outFile << "Done.\n\n";

	//Output the contents of List1.
	cout << "List1:\n";
	outFile << "List1:\n";
	displayList(List1, outFile);

	//Test the isEmpty() function on the now-empty List1.
	cout << "Now testing whether List1 is empty...\n";
	outFile << "Now testing whether List1 is empty...\n";
	emptyList = List1.isEmpty();
	cout << "Done.\n";
	outFile << "Done.\n";
	if (emptyList)
	{
		cout << "List1 is empty.\n\n";
		outFile << "List1 is empty.\n\n";
	}
	else if (!emptyList)
	{
		cout << "List1 has items.\n\n";
		outFile << "List1 has items.\n\n";
	}
	system("pause");
	cout << endl;

	//Test the getLength() function on the newly empty List1.
	cout << "List1 now contains " << List1.getLength() << " items.\n\n";
	outFile << "List1 now contains " << List1.getLength() << " items.\n\n";

	cout << "End test driver for the CircularType ADT.\n\n";
	outFile << "End test driver for the CircularType ADT.\n\n";

	outFile.close();

	system("pause");
}

//Displays the contents of the current list twice using the getNextItem() function.
//Also outputs the length of the list.
void displayList(CircularType<int> &list, ofstream &outFile)
{
	//Reset the list.
	list.resetList();

	//Create a temporary display variable.
	int displayInt;

	cout << "The current list (repeated twice) is: ";
	outFile << "The current list (repeated twice) is: ";


	//Loop through the list twice, displaying each item.
	for (int index = 0; index < (list.getLength() * 2); index++)
	{
		displayInt = list.getNextItem();
		cout << displayInt << " ";
		outFile << displayInt << " ";
	}

	//Display the length of the list.
	cout << "\nList length is " << list.getLength() << "." << endl << endl;
	outFile << "\nList length is " << list.getLength() << "." << endl << endl;

	system("pause");

	cout << endl;
}