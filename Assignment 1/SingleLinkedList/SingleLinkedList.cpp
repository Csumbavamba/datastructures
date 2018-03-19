#include "SingleLinkedList.h"

#include <iostream>



SingleLinkedList::SingleLinkedList()
{
	root = nullptr;
}

SingleLinkedList::~SingleLinkedList()
{
}


void SingleLinkedList::InsertAtTheFront(int value)
{
	CNode * currentNode = root;

	CNode * newNode = new CNode();
	newNode->SetData(value);
	newNode->SetNextNode(currentNode);
	root = newNode;

}

/// Position starts from ONE
void SingleLinkedList::InsertInTheMiddle(int value, int position)
{
	// if insertion happens at the first position
	if (position == 1)
	{
		InsertAtTheFront(value);
		return;
	}

	CNode * currentNode = root;
	CNode * newNode = new CNode();
	CNode * previousNode = nullptr;
	newNode->SetData(value);

	int counter = 1;

	while (counter != position)
	{

		// If we insert at the end
		if (currentNode == nullptr)
		{
			InsertAtTheEnd(value);
			return;
		}



		if (counter + 1 == position)
		{
			previousNode = currentNode;
		}

		currentNode = currentNode->GetNextNode();
		counter++;
	}

	newNode->SetNextNode(currentNode);
	previousNode->SetNextNode(newNode);
}

void SingleLinkedList::InsertAtTheEnd(int value)
{
	CNode * currentNode = root;

	while (currentNode->GetNextNode() != nullptr)
	{
		currentNode = currentNode->GetNextNode();
	}

	CNode * newNode = new CNode();
	newNode->SetData(value);
	newNode->SetNextNode(nullptr);

	currentNode->SetNextNode(newNode);
	

}

void SingleLinkedList::Delete(int value)
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

bool SingleLinkedList::Search(int value)
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

// loop through the elements of the list
void SingleLinkedList::Display()
{
	CNode * currentNode = root;
	int memberCounter = 1;
	while (currentNode != nullptr)
	{
		std::cout << memberCounter << ". list member value: " << currentNode->GetData() << std::endl;
		currentNode = currentNode->GetNextNode();
		memberCounter++;
	}
}


void SingleLinkedList::TestHarness()
{
	SingleLinkedList testList;

	std::cout << "Welcome to SingleLinkedList TestHarness!" << std::endl;
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


