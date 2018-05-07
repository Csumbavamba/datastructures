#include <iostream>

#include "BinaryHeap.h"
#include "Node.h"



BinaryHeap::BinaryHeap()
{
	heapSize = 0;
	root = nullptr;
	heap.push_back(nullptr);
}


BinaryHeap::~BinaryHeap()
{
}


void BinaryHeap::Insert(int nodeValue)
{
	Node * nodeToInsert = new Node(nodeValue);

	// Increase heap size
	heapSize++;
	// Add Node to heap (size number)
	if (heapSize == 1)
		root = nodeToInsert;

	heap.push_back(nodeToInsert);

	// Sort heap if it's not sorted
	SortInsertion();

}


void BinaryHeap::SortInsertion()
{
	Node * lastInsertedNode = heap.at(heapSize);
	int nodePosition = heapSize;

	if (lastInsertedNode == root) { return; }

	// While the lastInsertedNode's value is smaller than it's parent value
	while (lastInsertedNode != root && heap.at(nodePosition / 2)->GetNodeValue() > heap.at(nodePosition)->GetNodeValue())
	{
		// Swap the child with the parent
		SwapNodeValue(heap.at(nodePosition / 2), lastInsertedNode);

		lastInsertedNode = heap.at(nodePosition / 2);
		nodePosition = nodePosition / 2;
	}
	
}

void BinaryHeap::SwapNodeValue(Node * parent, Node * child)
{
	int swap = parent->GetNodeValue();
	parent->SetNodeValue(child->GetNodeValue());
	child->SetNodeValue(swap);
}

void BinaryHeap::RemoveFirst()
{
	// Replace first node value with the last inserted Node's node Value
	SwapNodeValue(heap.at(1), heap.at(heapSize));
	// Remove last Node from heap
	delete heap.back();
	heap.pop_back();
	heapSize--;
	
	int nodePosition = 1;

	ChildrenState state = Default;

	while (true)
	{
		// Define children state
		state = DefineChildrenState(nodePosition);

		switch (state)
		{
		case NoChildren:
		{
			std::cout << "No Children" << std::endl;
			return;
		}
		break;

		// Left Child
		case OneChild:
		{
			std::cout << "One Child" << std::endl;
			// Compare parent with Left
			if (heap.at(nodePosition)->GetNodeValue() > heap.at(nodePosition * 2)->GetNodeValue())
				SwapNodeValue(heap.at(nodePosition), heap.at(nodePosition * 2));
			return;
		}
		break;

		case TwoChildren:
		{
			std::cout << "Two Children" << std::endl;
			// Find the smaller child
			int smallerChildPosition;

			int leftValue = heap.at(nodePosition * 2)->GetNodeValue();
			int rightValue = heap.at((nodePosition * 2) + 1)->GetNodeValue();

			// If left is smaller than right
			if (leftValue < rightValue)
			{
				smallerChildPosition = nodePosition * 2;
			}
			// If right is smaller
			else
			{
				smallerChildPosition = (nodePosition * 2) + 1;
			}


			if (heap.at(nodePosition)->GetNodeValue() > heap.at(smallerChildPosition)->GetNodeValue())
			{
				SwapNodeValue(heap.at(nodePosition), heap.at(smallerChildPosition));
				nodePosition = smallerChildPosition;
				break;
			}
			// The node is at the right place, so return;
			else
			{
				return;
			}
		}
		default:
			return;
		}
	}
}

ChildrenState BinaryHeap::DefineChildrenState(int nodePosition)
{
	// No Children
	if (nodePosition * 2 > heapSize)
	{
		return NoChildren;
	}
	// One Child
	else if (nodePosition * 2 == heapSize)
	{
		return OneChild;
	}

	return TwoChildren;
}

void BinaryHeap::PrintHeap()
{
	int tempHeapSize = 1;

	while (tempHeapSize != heapSize + 1)
	{
		std::cout << heap.at(tempHeapSize)->GetNodeValue() << std::endl;
		tempHeapSize++;
	}
}

