#include "Node.h"

Node::Node(int nodeValue)
{
	this->nodeValue = nodeValue;
}

void Node::SetNodeValue(int nodeValue)
{
	this->nodeValue = nodeValue;
}

int Node::GetNodeValue() const
{
	return nodeValue;
}



