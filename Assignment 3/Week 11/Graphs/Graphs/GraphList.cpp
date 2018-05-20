#include <iostream>
#include <Windows.h>
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

void GraphList::ConnectNodes(int node1Value, int node2Value)
{
	Node * node1 = GetNodeByValue(node1Value);
	Node * node2 = GetNodeByValue(node2Value);

	node1->AddNeighbour(node2);
	node2->AddNeighbour(node1);
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
}


void GraphList::WalkThroughDepth()
{

}

void GraphList::WalkTrhoughBreadth()
{

}