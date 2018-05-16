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

void GraphList::ConnectNodes(int node1Value, int node2Value)
{
}

void GraphList::DisconnectNodes(int node1Value, int node2Value)
{
}


void GraphList::WalkThroughDepth()
{

}

void GraphList::WalkTrhoughBreadth()
{

}

	
	

	
	
		
			
			
		
}
