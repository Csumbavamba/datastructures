#include <iostream>
#include "GraphList.h"
#include "Node.h"


int main()
{
	GraphList graph;

	// graph.SetupGraph();

	// Create nodes
	Node node0(0);
	Node node1(1);
	Node node2(2);
	Node node3(3);
	Node node4(4);
	

	// Add nodes to graph
	graph.AddTestNode(&node0);
	graph.AddTestNode(&node1);
	graph.AddTestNode(&node2);
	graph.AddTestNode(&node3);
	graph.AddTestNode(&node4);
	

	// Setup Node connections
	std::cout << "How many connections does Node0 have?" << std::endl;
	graph.ConnectNodesOld(&node0);
	std::cout << "How many connections does Node1 have?" << std::endl;
	graph.ConnectNodesOld(&node1);
	std::cout << "How many connections does Node2 have?" << std::endl;
	graph.ConnectNodesOld(&node2);
	std::cout << "How many connections does Node3 have?" << std::endl;
	graph.ConnectNodesOld(&node3);
	std::cout << "How many connections does Node4 have?" << std::endl;
	graph.ConnectNodesOld(&node4);
	
	
	graph.WalkTrhoughBreadth();

	system("pause");



	return 0;
}