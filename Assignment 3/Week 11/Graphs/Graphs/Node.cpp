#include "Node.h"



Node::Node(int nodeValue)
{
	this->nodeValue = nodeValue;
	nextNeighbour = nullptr;
	isDiscovered = false;
}


Node::~Node()
{
}

int Node::GetNodeValue() const
{
	return nodeValue;
}

void Node::SetNodeValue(int nodeValue)
{
	this->nodeValue = nodeValue;
}


Node * Node::GetNeighbour() const
{
	return nextNeighbour;
}

void Node::SetNeighbour(Node * nextNeighbour)
{
	this->nextNeighbour = nextNeighbour;
}



bool Node::GetIsDiscovered() const
{
	return isDiscovered;
}

void Node::SetIsDiscovered(bool isDiscovered)
{
	this->isDiscovered = isDiscovered;
}
