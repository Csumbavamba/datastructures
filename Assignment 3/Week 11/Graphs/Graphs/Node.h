#pragma once
class Node
{
private:
	int nodeValue;
	Node * elderNode;
	Node * neighbourNode;
	bool isDiscovered;
public:
	Node(int nodeValue);
	~Node();

	int GetNodeValue() const;
	void SetNodeValue(int nodeValue);
	
	Node * GetElderNode() const;
	void SetElderNode(Node * elderNode);

	Node * GetNeighbourNode() const;
	void SetNeighbourNode(Node * neighbourNode);

	bool GetIsDiscovered() const;
	void SetIsDiscovered(bool isDiscovered);

	
};

