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
}

CNode * CNode::GetPreviousNode() const
{
	return previousNode;
}

CNode * CNode::GetNextNode() const
{
	return nextNode;
}



