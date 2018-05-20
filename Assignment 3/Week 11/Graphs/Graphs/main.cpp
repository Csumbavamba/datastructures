#include <iostream>
#include "GraphList.h"
#include "Node.h"


int main()
{
	GraphList graph;

	graph.AddNodeToGraph(0);
	graph.AddNodeToGraph(1);
	graph.AddNodeToGraph(2);
	graph.AddNodeToGraph(3);
	graph.AddNodeToGraph(4);
	

	graph.ConnectNodes(0, 1);
	graph.ConnectNodes(0, 3);

	graph.ConnectNodes(1, 4);
	graph.ConnectNodes(1, 2);

	graph.ConnectNodes(2, 3);
	graph.ConnectNodes(2, 4);

	graph.DisconnectNodes(0, 3);

	system("pause");

	std::cout << "Breadth first: " << std::endl;
	graph.WalkTrhoughBreadth();

	system("pause");

	std::cout << "Depth first: " << std::endl;
	graph.WalkThroughDepth();

	system("pause");

	return 0;
}