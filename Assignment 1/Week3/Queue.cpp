#include <iostream>

#include "Queue.h"



Queue::Queue()
{
	front = nullptr;
	end = nullptr;
}


Queue::~Queue()
{
}

void Queue::Enqueue(int data)
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

	end = newNode;
}

void Queue::Dequeue()
{
	// If list has members
	if (!IsEmpty())
	{
		CNode * currentNode = front;

		front = currentNode->GetPreviousNode();

		delete currentNode;
	}
	// If there is nothing in the list
	return;
}

int Queue::Peek()
{
	// If the list has members
	if (!IsEmpty())
	{
		std::cout <<  "Value of first in Queue: " << front->GetData() << std::endl;
		return front->GetData();
	}

	return -1;
}

bool Queue::IsEmpty()
{
	if (end == nullptr)
	{
		std::cout << "The queue is empty" << std::endl;
		return true;
	}
	return false;
}

void Queue::PrintQueueMembers()
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

void Queue::TestHarness()
{
	Queue queue;

	std::cout << "Welcome to Queue Tests" << std::endl;
	std::cout << std::endl;


	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);

	std::cout << "Enqueueing - 1, 2, 3" << std::endl;
	system("pause");
	std::cout << std::endl;

	queue.PrintQueueMembers();
	std::cout << std::endl;

	std::cout << "Peeking at the first element in queue" << std::endl;
	system("pause");
	std::cout << std::endl;

	queue.Peek();

	system("pause");
	std::cout << std::endl;

	queue.Dequeue();
	std::cout << "Dequeueing." << std::endl;
	queue.PrintQueueMembers();

	system("pause");
}
