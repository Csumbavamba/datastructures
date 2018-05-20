#include "Node.h"
#include <vector>
#include <algorithm>



Node::Node(int nodeValue)
{
	this->nodeValue = nodeValue;
	isDiscovered = false;
}


Node::~Node()
{
	for (int i = 0; i < neighbours.size(); i++)
	{
		neighbours.pop_back();
	}
	
}

int Node::GetNodeValue() const
{
	return nodeValue;
}

void Node::SetNodeValue(int nodeValue)
{
	this->nodeValue = nodeValue;
}


void Node::AddNeighbour(Node * node)
{
	// If the node is a nullptr, then get out of here
	if (node == nullptr) { return; }

	neighbours.push_back(node);
}

void Node::RemoveNeighbour(Node * node)
{
	std::vector<Node*>::iterator iterator;

	// Increment the iterator as long as it reaches the value (if it's not in do nothing)
	for (iterator = neighbours.begin(); iterator != neighbours.end(); iterator++)
	{
		if (node->GetNodeValue() == (*iterator)->GetNodeValue())
		{
			// Erase the right node from the vector
			neighbours.erase(iterator);
			// neighbours.pop_back();
			return;
		}
	}
}

Node * Node::GetNeighbour(int position) const
{
	if (position < neighbours.size())
		return neighbours.at(position);
	return nullptr;
}

int Node::GetNumberOfNeighbours() const
{
	return neighbours.size();
}




bool Node::GetIsDiscovered() const
{
	return isDiscovered;
}

void Node::SetIsDiscovered(bool isDiscovered)
{
	this->isDiscovered = isDiscovered;
}
