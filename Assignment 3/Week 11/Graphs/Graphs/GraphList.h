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
	void SetNodeConnections(Node * mainNode);
	int GetNodePositionToConnect() const;

	void WalkThroughDepth();
	void WalkTrhoughBreadth();
};

