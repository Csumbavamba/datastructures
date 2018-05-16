#pragma once
#include <vector>

class NeighbourList;

class Node
{
private:
	int nodeValue;
	std::vector<Node*> neighbours;
	bool isDiscovered;
public:
	Node(int nodeValue);
	~Node();

	int GetNodeValue() const;
	void SetNodeValue(int nodeValue);

	void AddNeighbour(Node * node);
	void RemoveNeighbour(Node * node);
	Node* GetNeighbour(int position) const;

	bool GetIsDiscovered() const;
	void SetIsDiscovered(bool isDiscovered);

	
};

