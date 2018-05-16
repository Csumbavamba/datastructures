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
	void ConnectNodes(int node1Value, int node2Value);
	void DisconnectNodes(int node1Value, int node2Value);

	void WalkThroughDepth();
	void WalkTrhoughBreadth();
};

