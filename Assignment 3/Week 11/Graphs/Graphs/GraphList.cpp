#include <iostream>

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

	SetNodeConnections(nodeToAdd);
}

void GraphList::SetNodeConnections(Node * currentNode)
{
	int numberOfConnections;
	int nextNeighbourPosition = -1;

	Node * mainNode = currentNode;

	// Get the number of connections
	std::cout << "How many connections does your node have?" << std::endl;
	std::cin >> numberOfConnections;

	// Get NodeNumber to Connect (as long as there is a new number)
	for (int i = 0; i < numberOfConnections; i++)
	{
		// Get a valid neighbour Position
		while (nextNeighbourPosition == -1 || graph.at(nextNeighbourPosition) == mainNode)
		{
			nextNeighbourPosition = GetNodePositionToConnect();
		}
		
		currentNode->SetNeighbourNode(graph.at(nextNeighbourPosition));
		currentNode = currentNode->GetNeighbourNode();
	}
	
}

int GraphList::GetNodePositionToConnect() const
{
	int nextNeighbourPosition;

	while (true)
	{
		std::cout << "Please write the number of the Node that should be connected to your node eg   1     (= 1st)" << std::endl;
		std::cin >> nextNeighbourPosition;

		if (graph.at(nextNeighbourPosition) == nullptr)
		{
			return -1;
		}
		else
		{
			break;
		}
	}

	return nextNeighbourPosition;

	// return -1 if it's invalid
}

void GraphList::WalkThroughDepth()
{
}

void GraphList::WalkTrhoughBreadth()
{
}
