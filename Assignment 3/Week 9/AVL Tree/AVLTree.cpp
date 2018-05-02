#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

#include "AVLTree.h"
#include "Node.h"


AVLTree::AVLTree()
{
	root = nullptr;
	unbalanceType = Balanced;
}


AVLTree::~AVLTree()
{
}

Node * AVLTree::GetRoot()
{
	return root;
}



void AVLTree::InsertNode(int nodeValue)
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

void AVLTree::DeleteNode(int nodeValue)
{
	Node * nodeToDelete = FindNode(nodeValue);
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

Node * AVLTree::FindNode(int nodeValue)
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
		if (nodeValue == currentNode->GetNodeValue())
		{
			return currentNode;
		}
		else if (nodeValue < currentNode->GetNodeValue())
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


void AVLTree::DisplayPreOrder(Node * currentNode)
{
	if (currentNode == nullptr)
		return;

	std::cout << currentNode->GetNodeValue() << " " << std::endl;

	// recurr on left subtree
	DisplayPreOrder(currentNode->GetLeftNode());

	// recurr on right subtree
	DisplayPreOrder(currentNode->GetRightNode());

}

void AVLTree::DisplayInOrder(Node * currentNode)
{
	if (currentNode == nullptr)
		return;

	// recurr on left subtree
	DisplayInOrder(currentNode->GetLeftNode());

	std::cout << currentNode->GetNodeValue() << " " << std::endl;

	// recurr on right subtree
	DisplayInOrder(currentNode->GetRightNode());
}

void AVLTree::DisplayPostOrder(Node * currentNode)
{
	if (currentNode == nullptr)
		return;

	// recurr on left subtree
	DisplayPostOrder(currentNode->GetLeftNode());

	// recurr on right subtree
	DisplayPostOrder(currentNode->GetRightNode());

	std::cout << currentNode->GetNodeValue() << " " << std::endl;

}



UnbalanceType AVLTree::GetUnbalanceType() const
{
	return unbalanceType;
}

void AVLTree::SetUnbalanceType(UnbalanceType unbalanceType)
{
	this->unbalanceType = unbalanceType;
}

UnbalanceType AVLTree::DetermineBalancingMethod(Node * unbalancedNode)
{
	// First step --> Determine if left or right has higher height
	if (unbalancedNode == nullptr)
	{
		return Balanced;
	}
	else
	{
		// If Left height is higher
		if (GetLeftHeight(unbalancedNode) >= GetRightHeight(unbalancedNode))
		{
			unbalancedNode = unbalancedNode->GetLeftNode();

			// Second step
			// If left height is higher
			if (GetLeftHeight(unbalancedNode) >= GetRightHeight(unbalancedNode))
			{
				return LeftLeft;
			}
			return LeftRight;
		}
		// If Right height is higher
		else
		{
			unbalancedNode = unbalancedNode->GetRightNode();

			// Second step
			// If left height is higher
			if (GetLeftHeight(unbalancedNode) >= GetRightHeight(unbalancedNode))
			{
				return RightLeft;
			}
			return RightRight;
		}
	}
	return Balanced;
}

int AVLTree::GetLeftHeight(Node * inspectedNode)
{
	if (inspectedNode->GetLeftNode() == nullptr)
	{
		return -1;
	}
	else
	{
		return CalculateNodeHeight(inspectedNode->GetLeftNode());
	}
}

int AVLTree::GetRightHeight(Node * inspectedNode)
{
	if (inspectedNode->GetRightNode() == nullptr)
	{
		return -1;
	}
	else
	{
		return CalculateNodeHeight(inspectedNode->GetRightNode());
	}
}

void AVLTree::BalanceTree()
{
	UnbalanceType balancingMethod = DetermineBalancingMethod(GetUnbalancedNode());

	switch (balancingMethod)
	{
	case LeftLeft:
	{
		BalanceLeftLeft();
		std::cout << "LeftLeft" << std::endl;
		return;
	}
	case RightRight:
	{
		return;
	}
	case LeftRight:
	{
		return;
	}
	case RightLeft:
	{
		return;
	}
	default:
	{
		// Do nothing
		std::cout << "Tree is balanced" << std::endl;
		return;
	}
	}
}

void AVLTree::BalanceLeftLeft()
{
	Node * unbalancedNode = GetUnbalancedNode();

	// When the root is unbalanced
	/*
				7					5											(8)					
			5			-->		4		7									5		  7		-->			  
		4																3		6					
																	2
	*/
	// When the unbalanced Node is the root
	if (unbalancedNode == root)
	{
		// If there is no right node
		if (unbalancedNode->GetRightNode() == nullptr)
		{
			root = unbalancedNode->GetLeftNode();
			root->SetRightNode(unbalancedNode);
			unbalancedNode->SetLeftNode(nullptr);

			return;
		}
		// If there is a right node
		else
		{
			Node * lostNode = unbalancedNode->GetLeftNode()->GetRightNode();
			// left node setRight (unbalancedNode)
			unbalancedNode->GetLeftNode()->SetRightNode(unbalancedNode); // left node loses right node
			// left node is the new root
			root = unbalancedNode->GetLeftNode();
			// UnbalancedNode setLeft(lost Node)
			unbalancedNode->SetLeftNode(lostNode); // UnbalancedNode loses left node

			return;
			
		}
	}
	// When the unbalanced is not the root
	/*
					7					7	
				(6)		8	-->		5		 8	
			5					4		6			
		4														
	*/
	else
	{
			// unbalanaced's parent --> SetLeft(left)
			unbalancedNode->GetParentNode()->SetLeftNode(unbalancedNode->GetLeftNode());
			// left SetRight(unbalanced)
			unbalancedNode->GetLeftNode()->SetRightNode(unbalancedNode);
			// unbalanced SetLeft(nullptr)
			unbalancedNode->SetLeftNode(nullptr);

			return;
	}

}

Node * AVLTree::GetUnbalancedNode()
{
	Node * currentNode = root;

	Node * unbalancedNode = nullptr;
	
	
	// Walk through the tree and calculate balance factors
	CalculateNodeHeight(currentNode);
	FindUnbalancedNodes(currentNode);

	if (!unbalancedNodes.empty())
	{
		// loop through the unbalancedNodes
		for (unsigned int i = 0; i < unbalancedNodes.size(); i++)
		{
			// Get the one with the smallest height
			if (i == 0)
				unbalancedNode = unbalancedNodes[i];

			if (unbalancedNodes[i]->Height < unbalancedNode->Height)
				unbalancedNode = unbalancedNodes[i];
		}
		// Return the Node with the smallest height and smallest balance factor
		unbalancedNodes.clear();
		return unbalancedNode;
	}
	else
	{
		return nullptr;
	}	
}

void AVLTree::FindUnbalancedNodes(Node * currentNode)
{
	if (currentNode == nullptr)
		return;

	CalculateBalanceFactor(currentNode);

	// if the balance factor is larger than 1, then the node is unbalanced (add it to the storing vector)
	if (currentNode->GetBalanceFactor() > 1)
	{
		unbalancedNodes.push_back(currentNode);
	}

	FindUnbalancedNodes(currentNode->GetLeftNode());

	FindUnbalancedNodes(currentNode->GetRightNode());

}

// Returns false if the node is a nullptr
bool AVLTree::CalculateBalanceFactor(Node * inspectedNode)
{
	if (inspectedNode == nullptr)
	{
		return false;
	}


	int leftHeight = CalculateNodeHeight(inspectedNode->GetLeftNode()) - 1;
	int rightHeight = CalculateNodeHeight(inspectedNode->GetRightNode()) - 1;

	if (inspectedNode->GetLeftNode() == nullptr)
	{
		leftHeight = -1;
	}
	if (inspectedNode->GetRightNode() == nullptr)
	{
		rightHeight = -1;
	}
	// Set the balance factor of the node
	inspectedNode->SetBalanceFactor( std::abs(leftHeight - rightHeight));
	return true;
}

int AVLTree::CalculateNodeHeight(Node * currentNode)
{
	if (currentNode == nullptr)
		return 0;

	int leftDepth = CalculateNodeHeight(currentNode->GetLeftNode());
	int rightDepth = CalculateNodeHeight(currentNode->GetRightNode());

	if (leftDepth > rightDepth)
	{
		currentNode->Height = leftDepth + 1;
		return leftDepth + 1;
	}
	else
	{
		currentNode->Height = rightDepth + 1;
		return rightDepth + 1;
	}
		
	
}





