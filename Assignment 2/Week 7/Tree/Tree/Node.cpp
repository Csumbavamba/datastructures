#include "Node.h"
#include <Windows.h>

Node::Node()
{
	leftNode = nullptr;
	rightNode = nullptr;
}

void Node::SetNodeValue(int nodeValue)
{
	this->nodeValue = nodeValue;
}

int Node::GetNodeValue() const
{
	return nodeValue;
}

void Node::SetLeftNode(Node * leftNode)
{
	this->leftNode = leftNode;
	if (leftNode != nullptr)
	{
		leftNode->SetParentNode(this);
	}
}


void Node::SetRightNode(Node * rightNode)
{
	this->rightNode = rightNode;
	if (rightNode != nullptr)
	{
		rightNode->SetParentNode(this);
	}
	
		
}

void Node::SetParentNode(Node * parent)
{
	this->parent = parent;
}


Node * Node::GetLeftNode() const
{
	return leftNode;
}

Node * Node::GetRightNode() const
{
	return rightNode;
}

Node * Node::GetParentNode() const
{
	return parent;
}



