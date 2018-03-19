#include "CNode.h"
#include <Windows.h>

CNode::CNode()
{
	previousNode = nullptr;
	nextNode = nullptr;
}

void CNode::SetData(int data)
{
	this->data = data;
}

int CNode::GetData() const
{
	return data;
}

void CNode::SetPreviousNode(CNode * previousNode)
{
	this->previousNode = previousNode;
}


void CNode::SetNextNode(CNode * nextNode)
{
	this->nextNode = nextNode;

	// If we are at the end of the list, this code is not needed
	
	if (nextNode != nullptr)
	{
		nextNode->SetPreviousNode(this);
	}
	
	
	
}


CNode * CNode::GetPreviousNode() const
{
	return previousNode;
}

CNode * CNode::GetNextNode() const
{
	return nextNode;
}



