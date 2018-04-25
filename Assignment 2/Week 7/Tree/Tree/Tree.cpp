#include "Tree.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include <algorithm>


Tree::Tree()
{
	root = nullptr;
}


Tree::~Tree()
{
}

Node * Tree::GetRoot()
{
	return root;
}

void Tree::InsertNode(int nodeValue)
{
	// Create iterator node pointing at the root
	Node * iterator = root;
	// Create new node + assign nodeValue
	Node * nodeToInsert = new Node();
	nodeToInsert->SetNodeValue(nodeValue);
	
	// If it is the first node to be inserted
	if (iterator == nullptr)
	{
		root = nodeToInsert;
		return;
	}

	// Keep looping through the code until it inserts
	while (true)
	{
		// if the new nodes NodeValue is <= to the current Node
		if (nodeToInsert->GetNodeValue() <= iterator->GetNodeValue())
		{
			// if the left Value is a null ptr
			if (iterator->GetLeftNode() == nullptr)
			{
				// set new Node to be the left Node
				iterator->SetLeftNode(nodeToInsert);
				return;
			}
			else
			{
				// Otherwise Point iterator to the left Node 
				if (iterator->GetLeftNode() == nullptr) //--> Pointer protection
				{
					std::cout << "LeftNode is a nullptr and you are trying to get it" << std::endl;
					return;
				}
				iterator = iterator->GetLeftNode();
			}
		}
		// If value is higher get the right node or insert
		else
		{
			if (iterator->GetRightNode() == nullptr)
			{
				// insert new node as the right node
				iterator->SetRightNode(nodeToInsert);
				return;
			}
			else
			{
				// Otherwise Point iterator to the right Node
				if (iterator->GetRightNode() == nullptr) //--> Pointer protection
				{
					std::cout << "RightNode is a nullptr and you are trying to get it" << std::endl;
					return;
				}
				iterator = iterator->GetRightNode();
			}

		}
	}
}

void Tree::DeleteNode(int value)
{
	Node * nodeToDelete = FindNode(value);
	if (nodeToDelete == nullptr)
	{
		std::cout << "The value isn't in the tree." << std::endl;
		return;
	}

	// Point at current Node
	Node * currentNode = nodeToDelete;
	int counter = 0;

	// Check if there is a right node
	if (currentNode->GetRightNode() != nullptr)
	{
		currentNode = currentNode->GetRightNode();
		while (currentNode->GetLeftNode() != nullptr)
		{
			// Get Left Node until you reach nullptr
			currentNode = currentNode->GetLeftNode();
			counter++;
		}
		// If there is no left node
		if (currentNode->GetLeftNode() == nullptr)
		{
			// Swap the currentNode with the Node I want to delete
			int tempValue = nodeToDelete->GetNodeValue();
			nodeToDelete->SetNodeValue(currentNode->GetNodeValue());
			currentNode->SetNodeValue(tempValue);

			if (currentNode == currentNode->GetParentNode()->GetLeftNode())
			{
				currentNode->GetParentNode()->SetLeftNode(nullptr);
			}

			if (currentNode->GetRightNode() == nullptr && nodeToDelete->GetRightNode()->GetLeftNode() == nullptr)
			{
				nodeToDelete->SetRightNode(nullptr);
			}
			

			delete currentNode;
			return;
		}
		// if there is a right node
		else
		{
			if (counter > 0)
			{
				currentNode->GetParentNode()->SetLeftNode(currentNode->GetRightNode());
			}

			// Disconnect the node to be deleted
			currentNode->SetLeftNode(nodeToDelete->GetLeftNode());	
			nodeToDelete->GetParentNode()->SetLeftNode(currentNode);

			delete nodeToDelete;
			return;
		}
		
		

		
	}
	// If there is no right node
	else
	{
		// Check if there is a Left node
		if (currentNode->GetLeftNode() != nullptr)
		{
			// Point to left node
			currentNode = currentNode->GetLeftNode();
			
			// Check if this node is the right node of the parent Node
			// If so set right node
			if (nodeToDelete->GetParentNode()->GetRightNode() == nodeToDelete)
			{
				// Disconnect the node that I want to delete
				nodeToDelete->GetParentNode()->SetRightNode(currentNode);
				delete nodeToDelete;
				return;
			}
				
			// Otherwise set left node
			nodeToDelete->GetParentNode()->SetLeftNode(currentNode);
			delete nodeToDelete;
			return;

		}

		// If there is no left node or right node either
		// Check if this node is the right node of the parent Node
		if (nodeToDelete->GetParentNode()->GetRightNode() == nodeToDelete)
		{
			nodeToDelete->GetParentNode()->SetRightNode(nullptr);
			delete nodeToDelete;
			return;			
		}

		// Otherwise set left node
		nodeToDelete->GetParentNode()->SetLeftNode(nullptr);
		delete nodeToDelete;
		return;		
	}
}

Node* Tree::FindNode(int value)
{
	// Compare value with the current node that is being pointed at
	Node * currentNode = root;
		// If the current node is a nullptr
	if (currentNode == nullptr)
	{
		return nullptr;
	}

	while (true)
	{
		if (value == currentNode->GetNodeValue())
		{
			return currentNode;
		}
		else if (value < currentNode->GetNodeValue())
		{
			if (currentNode->GetLeftNode() == nullptr)
			{
				// value isn't there
				return nullptr;
			}
			currentNode = currentNode->GetLeftNode();
		}
		// If the value is larger than the currentNode
		else
		{
			if (currentNode->GetRightNode() == nullptr)
			{
				// value isn't there
				return nullptr;
			}
			currentNode = currentNode->GetRightNode();
		}
	}
	
}

void Tree::DisplayPreOrder(Node * currentNode)
{
	if (currentNode == nullptr)
		return;

	std::cout << currentNode->GetNodeValue() << " " << std::endl;

	// recurr on left subtree
	DisplayPreOrder(currentNode->GetLeftNode());

	// recurr on right subtree
	DisplayPreOrder(currentNode->GetRightNode());

}

void Tree::DisplayInOrder(Node * currentNode)
{
	if (currentNode == nullptr)
		return;

	// recurr on left subtree
	DisplayPreOrder(currentNode->GetLeftNode());

	std::cout << currentNode->GetNodeValue() << " " << std::endl;

	// recurr on right subtree
	DisplayPreOrder(currentNode->GetRightNode());
}

void Tree::DisplayPostOrder(Node * currentNode)
{
	if (currentNode == nullptr)
		return;

	// recurr on left subtree
	DisplayPreOrder(currentNode->GetLeftNode());

	// recurr on right subtree
	DisplayPreOrder(currentNode->GetRightNode());

	std::cout << currentNode->GetNodeValue() << " " << std::endl;

}



