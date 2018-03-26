#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void PrintInt(int number)
{
	cout << number << ", ";
}

bool IsOdd(int number)
{
	return ((number % 2) == 1); // return true if odd
}

int main()
{
	list <int> myList;
	myList.push_back(10);
	myList.push_back(50);
	myList.push_back(53); 
	myList.push_back(20); 
	myList.push_back(50); 
	myList.push_back(25); 
	myList.push_back(35); 
	myList.push_back(40); 
	myList.push_back(40); 
	myList.push_back(35); 
	myList.push_back(50); 
	myList.push_back(31); 
	myList.push_back(50);

	cout << "Container elements: ";

	// Test for_each
	for_each(myList.begin(), myList.end(), PrintInt);

	cout << endl;

	// Test find, with element in container
	list<int>::iterator iterator = find(myList.begin(), myList.end(), 20);

	if (iterator == myList.end())
	{
		cout << "20 not found" << endl;
	}
	else
	{
		cout << "Found: " << *iterator << endl;
	}

	// Test find, with element not in container:
	iterator = find(myList.begin(), myList.end(), 47);

	if (iterator == myList.end())
	{
		cout << "47 not found" << endl;
	}
	else
	{
		cout << "Found: " << *iterator << endl;
	}

	// Test count, how many times is 50 in the container? 
	int Count = static_cast<int>(count(myList.begin(), myList.end(), 50));

	cout << "50 is in the container " << Count << " times!" << endl;

	// Test count_if, how many items are odd? 
	Count = static_cast<int> (count_if(myList.begin(), myList.end(), IsOdd));

	cout << Count << " odd numbers in the container!" << endl;

	// Remove all the items of value 50
	iterator = remove(myList.begin(), myList.end(), 50);

	/*
		Remove moves the items in the container to be     
		removed to the end, and then returns an iterator   
		for the first item that is to be removed.    
		erase must then be called to remove the items! 
	*/
	myList.erase(iterator, myList.end());

	// Check the container
	cout << "Container elements: ";
	for_each(myList.begin(), myList.end(), PrintInt);
	cout << endl;

	// Test Sort
	myList.sort();

	// Check the container
	cout << "Sorted Container elements: ";
	for_each(myList.begin(), myList.end(), PrintInt);
	cout << endl;

	// Test reverse
	myList.reverse();

	// Check the container
	cout << "Reversed Container elements: ";
	for_each(myList.begin(), myList.end(), PrintInt);
	cout << endl;

	system("pause");

	return 0;
}