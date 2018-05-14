#pragma once
#include <vector>

class Node;

class GraphList
{
private:
	std::vector<Node*> graph;
public:
	GraphList();
	~GraphList();

	void AddNodeToGraph(int nodeValue); 
	void AddTestNode(Node * node); // Just for testing
	void SetupGraph();

	void ConnectNodes(Node * node1, Node * node2); // Experimentall

	void ConnectNodesOld(Node * mainNode);

	void WalkThroughDepth();
	void WalkTrhoughBreadth();
};

