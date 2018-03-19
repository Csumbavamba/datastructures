#include <iostream>

#include "Deque.h"



Deque::Deque()
{
	end = nullptr;
	front = nullptr;
}


Deque::~Deque()
{
}

void Deque::EnqueueAtFront(int data)
{
	CNode * currentNode = front;

	// Create node for insertion
	CNode * newNode = new CNode();
	newNode->SetData(data);

	newNode->SetPreviousNode(currentNode);

	// If this is the first item to join the queue
	if (currentNode == nullptr)
	{
		end = newNode;
	}

	newNode->SetNextNode(nullptr);
	front = newNode;
}

void Deque::EnqueueAtEnd(int data)
{
	CNode * currentNode = end;

	// Create node for insertion
	CNode * newNode = new CNode();
	newNode->SetData(data);

	// Insert node at the end of the queue
	newNode->SetNextNode(currentNode);

	// If this is the first item to join the queue
	if (currentNode == nullptr)
	{
		front = newNode;
	}

	newNode->SetPreviousNode(nullptr);
	end = newNode;
}

void Deque::DequeueAtFront()
{
	// If list has members
	if (!IsEmpty())
	{
		CNode * currentNode = front;

		front = currentNode->GetPreviousNode();
		end->SetNextNode(nullptr);

		delete currentNode;
	}
	// If there is nothing in the list
	return;
}

void Deque::DequeueAtEnd()
{
	// If list has members
	if (!IsEmpty())
	{
		CNode * currentNode = end;

		end = currentNode->GetNextNode();
		end->SetPreviousNode(nullptr);

		delete currentNode;
	}
	// If there is nothing in the list
	return;
}

int Deque::PeekAtFront()
{
	// If the list has members
	if (!IsEmpty())
	{
		return front->GetData();
	}

	return -1;
}

int Deque::PeekAtEnd()
{
	// If the list has members
	if (!IsEmpty())
	{
		return end->GetData();
	}

	return -1;
}

bool Deque::IsEmpty()
{
	if (end == nullptr && front == nullptr)
	{
		std::cout << "The queue is empty" << std::endl;
		return true;
	}
	return false;
}

void Deque::PrintDequeMembers()
{
	CNode * currentNode = front;
	int memberCounter = 1;

	// iterate through the list members and write them on the screen
	while (currentNode != nullptr)
	{
		std::cout << memberCounter << ". in queue: " << currentNode->GetData() << std::endl;

		currentNode = currentNode->GetPreviousNode();
		memberCounter++;
	}
}

void Deque::TestHarness()
{
	Deque deque;

	std::cout << "Welcome to Deque Tests" << std::endl;
	std::cout << std::endl;


	deque.EnqueueAtEnd(1);
	deque.EnqueueAtEnd(2);
	deque.EnqueueAtEnd(3);
	deque.EnqueueAtFront(4);

	std::cout << "Enqueueing - 1, 2, 3 at the end - 4 at front" << std::endl;
	system("pause");
	std::cout << std::endl;

	deque.PrintDequeMembers();
	std::cout << std::endl;

	std::cout << "Peeking part:" << std::endl;
	system("pause");
	std::cout << std::endl;

	int peek = deque.PeekAtEnd();
	std::cout << "Peek at End: " << peek << std::endl;

	peek = deque.PeekAtFront();
	std::cout << "Peek at Front: " << peek << std::endl;

	system("pause");
	std::cout << std::endl;

	deque.DequeueAtEnd();
	std::cout << "Dequeue at End." << std::endl;
	deque.PrintDequeMembers();

	system("pause");
	std::cout << std::endl;

	deque.DequeueAtFront();
	std::cout << "Dequeue at Front." << std::endl;
	deque.PrintDequeMembers();

	system("pause");
}
