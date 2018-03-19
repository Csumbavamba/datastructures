#include <iostream>
#include <windows.h>
#include <time.h>

#include "LinkedList.h"




LinkedList::LinkedList()
{
	// Set every element to 0
	for (int i = 0; i < 10; i++)
	{
		SetData(0, i);
	}
}

LinkedList::~LinkedList()
{
}

int LinkedList::GetData(int position)
{
	return list[position];
}

void LinkedList::SetData(int data, int position)
{
	list[position] = data;
}


void LinkedList::SwapData(int position1, int position2)
{
	int temp = list[position1];
	list[position1] = list[position2];
	list[position2] = temp;

	return;

}

bool LinkedList::IsListAscending()
{
	for (int i = 0; i < 9; i++)
	{
		// if the list is ascending
		if (list[i] > list[i + 1])
		{
			return false;
		}
	}
	return true;
}



void LinkedList::BubbleSort()
{
	while (!IsListAscending())
	{
		// iterate through the list
		for (int element = 0; element < 9; element++)
		{
			// if the one on the right is smaller - swap them
			if (list[element] > list[element + 1])
			{
				SwapData(element, element + 1);
				system("cls");
				DisplayData();
			}
		}
	}
}

void LinkedList::SelectionSort()
{
	int unsortedData = 10; // TODO, get list length instead of using magic number
	int currentLargest = 0;


	while (!IsListAscending())
	{
		currentLargest = 0;

		// Find the largest element
		for (int listElement = 1; listElement < unsortedData; listElement++)
		{
			// if left side is smaller (right is larger)
			if ((list[currentLargest] <= list[listElement]))
			{
				// set right side to be the largest
				currentLargest = listElement;
			}	
		}

		// Move largest data, to the end of the list (if it's not already there)
		if (currentLargest != unsortedData)
		{
			SwapData(currentLargest, unsortedData - 1);
		}
		unsortedData--;
		
		
		system("cls"); // TODO, Remove after testing
		DisplayData(); // TODO, Remove after testing
	}
}

void LinkedList::InsertionSort()
{
	bool isElementInserted;
	int inspectedElement;
	int lastSortedElement;
	int elementsSorted = 0;

	while (!IsListAscending())
	{
		isElementInserted = false;

		inspectedElement = elementsSorted + 1;
		lastSortedElement = elementsSorted;

		// until the inspected element is inserted at the right position
		while (!isElementInserted)
		{
			// If the element is being inserted at the first position 
			// OR the element has been sorted
			if (list[inspectedElement] > list[lastSortedElement] || inspectedElement == 0)
			{
				isElementInserted = true;
				elementsSorted++;
				system("cls"); // TODO, Remove after testing
				DisplayData(); // TODO, Remove after testing
			}

			// If the inspected element is larger than the last sorted
			else
			{
				// move the inspected element to the left
				SwapData(inspectedElement, lastSortedElement);
				inspectedElement--;
				lastSortedElement--;
			}
		}
		
	}
}


void LinkedList::DisplayData()
{
	// print out the elements of the array
	for (int i = 0; i < 10; i++)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
	Sleep(200);

}

void LinkedList::GenerateRandomArray()
{
	int randomNumber;

	for (int i = 0; i < 10; i++)
	{
		randomNumber = rand() % 50 + 1;
		SetData(randomNumber, i);
	}
}

void LinkedList::SlowDisplay()
{
	// print out the elements of the array
	for (int i = 0; i < 10; i++)
	{
		std::cout << list[i] << " ";
		Sleep(200);
	}
	std::cout << std::endl;
}

void LinkedList::TestHarness()
{
	srand(time(NULL));
	LinkedList bubbleTest;
	LinkedList selectionTest;
	LinkedList insertionTest;

	bubbleTest.GenerateRandomArray();
	selectionTest.GenerateRandomArray();
	insertionTest.GenerateRandomArray();

	std::cout << "Welcome to Sorting TestHarness!" << std::endl;
	std::cout << std::endl;
	system("pause");
	system("cls");


	// Test BubbleSort

	std::cout << "Generating array for testing..." << std::endl;
	std::cout << std::endl;
	Sleep(2000);

	std::cout << "Testing for Bubble Sort ready!" << std::endl;
	system("pause");
	system("cls");

	bubbleTest.SlowDisplay();
	Sleep(2000);
	bubbleTest.BubbleSort();

	std::cout << std::endl;
	std::cout << "Bubble Sorting ready!";
	std::cout << std::endl;
	system("pause");
	system("cls");


	// Test SelectionSort

	std::cout << "Generating array for testing..." << std::endl;
	std::cout << std::endl;
	Sleep(2000);

	std::cout << "Testing for Selection Sort ready!" << std::endl;
	system("pause");
	system("cls");

	selectionTest.SlowDisplay();
	Sleep(2000);
	selectionTest.SelectionSort();

	std::cout << std::endl;
	std::cout << "Selection Sorting ready!";
	std::cout << std::endl;
	system("pause");
	system("cls");


	// Test InsertionSort

	std::cout << "Generating array for testing..." << std::endl;
	std::cout << std::endl;
	Sleep(2000);

	std::cout << "Testing for Insertion Sort ready!" << std::endl;
	system("pause");
	system("cls");

	insertionTest.SlowDisplay();
	Sleep(2000);
	insertionTest.InsertionSort();

	std::cout << std::endl;
	std::cout << "Insertion Sorting ready!";
	std::cout << std::endl;
	system("pause");
}
