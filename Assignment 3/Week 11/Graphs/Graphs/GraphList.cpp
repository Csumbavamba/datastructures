#include <iostream>
#include <Windows.h>
#include <queue>
#include <algorithm>

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

// Just for Initial testing
void GraphList::AddTestNode(Node * node)
{
	graph.push_back(node);
}


void GraphList::SetupGraph()
{
	// Generate Graph elements
	for (int i = 0; i < 8; i++)
	{
		AddNodeToGraph(i);
		std::cout << "Node " << i << " created." << std::endl;
	}
	
	// Connect all 8 nodes
	for (int i = 0; i < 8; i++)
	{
		std::cout << "How many connections does" << " Node " << i << ". have?." << std::endl;
		ConnectNodesOld(graph.at(i));
		std::cout << "Node " << i << ". connections set." << std::endl;
		Sleep(100);
		system("cls");
	}
}

void GraphList::ConnectNodes(Node * node1, Node * node2)
{

}

void GraphList::ConnectNodesOld(Node * currentNode)
{
	int numberOfConnections = 0;
	int neighbourPosition = -1;

	Node * mainNode = currentNode;

	// Get the number of connections
	std::cin >> numberOfConnections;

	// Get NodeNumber to Connect (as long as there is a new number)
	for (int i = 0; i < numberOfConnections; i++)
	{
		// Get user input for neighbour to connect to
		while (true)
		{
			std::cout << "Node is connected to: " << std::endl;
			std::cin >> neighbourPosition;

			if (neighbourPosition >= graph.size() || neighbourPosition < 0)
			{
				std::cout << "Invalid number" << std::endl;
				// Repeat
			}
			else if (graph.at(neighbourPosition) == mainNode)
			{
				std::cout << "The Node cannot be connected to itself." << std::endl;
				// Repeat
			}
			else
			{
				break;
				// Right number
			}
		}
		currentNode->SetNeighbour(graph.at(neighbourPosition));
		currentNode = currentNode->GetNeighbour();
	}
	
}


void GraphList::WalkThroughDepth()
{

}

void GraphList::WalkTrhoughBreadth()
{
	Node * output [5];
	std::queue<Node*> walkQueue;
	Node * inspectedNode = nullptr;
	Node * mainNode = nullptr;


	// Move first element of vector into output array
	inspectedNode = graph.at(0);
	output[0] = inspectedNode;
	inspectedNode->SetIsDiscovered(true);

	

	for (int i = 1; i < 5; i++)
	{
		// mainNode = inspectedNode;
		// Enqueue connections that are not discovered to queue
		while (inspectedNode != nullptr)
		{
			if (!inspectedNode->GetIsDiscovered())
			{
				walkQueue.push(inspectedNode);
				// Set connections to discovered
				inspectedNode->SetIsDiscovered(true);
			}

			inspectedNode = inspectedNode->GetNeighbour();
		}

		// When no more connections are there Dequeue
		inspectedNode = walkQueue.front();
		walkQueue.pop();

		// Move first element from queue to output array
		output[i] = inspectedNode;
	}

	
	

	
	
		
			
			
		
}
