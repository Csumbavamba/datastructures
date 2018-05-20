#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <queue>
#include <stack>

#include "GraphList.h"
#include "Node.h"


GraphList::GraphList()
{
}


GraphList::~GraphList()
{
	for (int i = 0; i < graph.size(); i++)
	{
		delete graph.at(i);
	}
}

void GraphList::AddNodeToGraph(int nodeValue)
{
	Node * nodeToAdd = new Node(nodeValue);

	graph.push_back(nodeToAdd);
}

void GraphList::ConnectNodes(int node1Value, int node2Value)
{
	Node * node1 = GetNodeByValue(node1Value);
	Node * node2 = GetNodeByValue(node2Value);

	node1->AddNeighbour(node2);
	node2->AddNeighbour(node1);

	std::cout << node1Value << " is connected to " << node2Value << std::endl;
}

Node * GraphList::GetNodeByValue(int nodeValue) const
{
	// Search through the graph, if the value is the same as the graph value, then return the node
	for (int i = 0; i < graph.size(); i++)
	{
		if (nodeValue == graph.at(i)->GetNodeValue())
		{
			return graph.at(i);
		}
	}

	return nullptr;
}

void GraphList::DisconnectNodes(int node1Value, int node2Value)
{
	Node * node1 = GetNodeByValue(node1Value);
	Node * node2 = GetNodeByValue(node2Value);

	node1->RemoveNeighbour(node2);
	node2->RemoveNeighbour(node1);

	std::cout << node1Value << " and " << node2Value << " are now disconnected." << std::endl;
}


void GraphList::WalkThroughDepth()
{
	// Create output graph
	std::vector<Node*> outputGraph;
	std::stack<Node*> stack;
	Node * currentElement = nullptr;

	// Move first element to output
	currentElement = graph.at(0);
	currentElement->SetIsDiscovered(true);


	while (true)
	{
		// Add neighbours to queue
		for (int neighbour = 0; neighbour < currentElement->GetNumberOfNeighbours(); neighbour++)
		{
			// if the neighbour has not been discovered yet
			if (currentElement->GetNeighbour(neighbour)->GetIsDiscovered() == false)
			{
				// Add it to the queue and set it to be discovered
				stack.push(currentElement->GetNeighbour(neighbour));
				currentElement->GetNeighbour(neighbour)->SetIsDiscovered(true);
			}

		}

		// Dequeue
		outputGraph.push_back(currentElement);

		// When the queue is empty, break
		if (stack.empty())
		{
			break;
		}

		currentElement = stack.top();
		stack.pop();
	}

	// Display output
	for (int i = 0; i < outputGraph.size(); i++)
	{
		std::cout << outputGraph.at(i)->GetNodeValue() << std::endl;
		outputGraph.at(i)->SetIsDiscovered(false);
	}
}

void GraphList::WalkTrhoughBreadth()
{
	// Create output graph
	std::vector<Node*> outputGraph;
	std::queue<Node*> queue;
	Node * currentElement = nullptr;

	// Move first element to output
	currentElement = graph.at(0);
	currentElement->SetIsDiscovered(true);


	while (true)
	{
		// Add neighbours to queue
		for (int neighbour = 0; neighbour < currentElement->GetNumberOfNeighbours(); neighbour++)
		{
			// if the neighbour has not been discovered yet
			if (currentElement->GetNeighbour(neighbour)->GetIsDiscovered() == false)
			{
				// Add it to the queue and set it to be discovered
				queue.push(currentElement->GetNeighbour(neighbour));
				currentElement->GetNeighbour(neighbour)->SetIsDiscovered(true);
			}

		}

		// Dequeue
		outputGraph.push_back(currentElement);

		// When the queue is empty, break
		if (queue.empty())
		{
			break;
		}

		currentElement = queue.front();
		queue.pop();
	}

	// Display output
	for (int i = 0; i < outputGraph.size(); i++)
	{
		std::cout << outputGraph.at(i)->GetNodeValue() << std::endl;
		outputGraph.at(i)->SetIsDiscovered(false);
	}
	
	
}