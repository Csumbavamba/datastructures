#pragma once

class NeighbourList;

class Node
{
private:
	int nodeValue;
	Node * nextNeighbour;
	bool isDiscovered;
public:
	Node(int nodeValue);
	~Node();

	int GetNodeValue() const;
	void SetNodeValue(int nodeValue);

	Node * GetNeighbour() const;
	void SetNeighbour(Node * nextNeighbour);

	bool GetIsDiscovered() const;
	void SetIsDiscovered(bool isDiscovered);

	
};

