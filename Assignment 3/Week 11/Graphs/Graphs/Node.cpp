#include "Node.h"



Node::Node(int nodeValue)
{
	this->nodeValue = nodeValue;
	elderNode = nullptr;
	neighbourNode = nullptr;
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

Node * Node::GetElderNode() const
{
	return elderNode;
}

void Node::SetElderNode(Node * elderNode)
{
	this->elderNode = elderNode;
}

Node * Node::GetNeighbourNode() const
{
	return neighbourNode;
}

void Node::SetNeighbourNode(Node * neighbourNode)
{
	this->neighbourNode = neighbourNode;
}

bool Node::GetIsDiscovered() const
{
	return isDiscovered;
}

void Node::SetIsDiscovered(bool isDiscovered)
{
	this->isDiscovered = isDiscovered;
}
