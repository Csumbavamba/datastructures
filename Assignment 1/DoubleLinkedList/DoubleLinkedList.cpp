#include "DoubleLinkedList.h"
#include <iostream>


DoubleLinkedList::DoubleLinkedList()
{
	root = nullptr;
}


DoubleLinkedList::~DoubleLinkedList()
{
}

void DoubleLinkedList::InsertAtTheFront(int value)
{
	CNode * currentNode = root;

	// Create node for insertion
	CNode * newNode = new CNode();
	newNode->SetData(value);

	// Insert node before the root
	newNode->SetNextNode(currentNode);
	root = newNode;
}

void DoubleLinkedList::InsertInTheMiddle(int value, int position)
{
	// if insertion happens at the first position
	if (position == 1)
	{
		InsertAtTheFront(value);
		return;
	}

	CNode * currentNode = root;
	CNode * previousNode = nullptr;

	int counter = 1;

	while (counter != position)
	{

		// If the position is at the end of the list
		if (currentNode == nullptr)
		{
			InsertAtTheEnd(value);
			return;
		}


		// When the iterator only needs to iterate one more to reach the target position
		if (counter + 1 == position)
		{
			previousNode = currentNode;
		}

		// iterate through the list members
		currentNode = currentNode->GetNextNode();
		counter++;
	}

	// Create node for insertion
	CNode * newNode = new CNode();
	newNode->SetData(value);

	// Insert the node
	newNode->SetNextNode(currentNode);
	previousNode->SetNextNode(newNode);
}

void DoubleLinkedList::InsertAtTheEnd(int value)
{
	// iterator points at root
	CNode * currentNode = root;

	// iterate through the nodes until the iterator reaches the end of the list
	while (currentNode->GetNextNode() != nullptr)
	{
		currentNode = currentNode->GetNextNode();
	}

	// create node that will be inserted
	CNode * newNode = new CNode();
	newNode->SetData(value);

	// insert the node
	newNode->SetNextNode(nullptr);
	currentNode->SetNextNode(newNode);
}

void DoubleLinkedList::Delete(int value)
{
	
	CNode * currentNode = root;
	CNode * toDelete = nullptr;
	CNode * toConnect = nullptr;

	// if the search value is in the list
	if (Search(value)) 
	{
		while (currentNode != nullptr)
		{
			// if we delete the first value
			if (value == root->GetData())
			{
				// reset the root to the next one
				toDelete = currentNode;
				root = currentNode->GetNextNode();
				root->SetPreviousNode(nullptr);

				// delete the element
				delete toDelete;
				return;
			}

			// if the iterator is pointing one before the search value
			if (currentNode->GetNextNode()->GetData() == value)
			{
				
				toDelete = currentNode->GetNextNode();
				toConnect = currentNode->GetNextNode()->GetNextNode();

				// disconnect the node we want to delete
				currentNode->SetNextNode(toConnect);

				// delete the node
				delete toDelete;
				return;
			}

			currentNode = currentNode->GetNextNode();
		}
	}
	
}

bool DoubleLinkedList::Search(int value)
{
	
	CNode * currentNode = root;

	while (currentNode != nullptr)
	{
		if (currentNode->GetData() == value)
		{
			return true;
		}
		currentNode = currentNode->GetNextNode();
	}

	return false;
	
}

void DoubleLinkedList::Display()
{
	CNode * currentNode = root;
	int memberCounter = 1;

	// iterate through the list members and write them on the screen
	while (currentNode != nullptr)
	{
		std::cout << memberCounter << ". list member value: " << currentNode->GetData() << std::endl;
		currentNode = currentNode->GetNextNode();
		memberCounter++;
	}
}

void DoubleLinkedList::TestHarness()
{
	DoubleLinkedList testList;

	std::cout << "Welcome to DoubleLinkedList TestHarness!" << std::endl;
	std::cout << std::endl;

	system("pause");
	std::cout << std::endl;


	std::cout << "Inserting 3, 2, 1 at the Front of the list" << std::endl;
	system("pause");
	std::cout << std::endl;

	testList.InsertAtTheFront(3);
	testList.InsertAtTheFront(2);
	testList.InsertAtTheFront(1);
	testList.Display();
	std::cout << std::endl;

	system("pause");
	std::cout << std::endl;

	std::cout << "Inserting 5 at the end of the list" << std::endl;
	system("pause");
	std::cout << std::endl;

	testList.InsertAtTheEnd(5);
	testList.Display();
	std::cout << std::endl;

	system("pause");
	std::cout << std::endl;

	std::cout << "Inserting 4 at position 4" << std::endl;
	system("pause");
	std::cout << std::endl;

	testList.InsertInTheMiddle(4, 4);
	testList.Display();
	std::cout << std::endl;

	system("pause");
	std::cout << std::endl;

	std::cout << "Deleting value 1" << std::endl;
	testList.Delete(1);
	testList.Display();
	std::cout << std::endl;

	system("pause");
}