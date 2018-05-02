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
				BalanceTree();
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
				BalanceTree();
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
			BalanceTree();
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
			BalanceTree();
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
				BalanceTree();
				return;
			}

			// Otherwise set left node
			nodeToDelete->GetParentNode()->SetLeftNode(currentNode);
			delete nodeToDelete;
			BalanceTree();
			return;

		}

		// If there is no left node or right node either
		// Check if this node is the right node of the parent Node
		if (nodeToDelete->GetParentNode()->GetRightNode() == nodeToDelete)
		{
			nodeToDelete->GetParentNode()->SetRightNode(nullptr);
			delete nodeToDelete;
			BalanceTree();
			return;
		}

		// Otherwise set left node
		nodeToDelete->GetParentNode()->SetLeftNode(nullptr);
		delete nodeToDelete;
		BalanceTree();
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
		BalanceRightRight();
		std::cout << "RightRight" << std::endl;
		return;
	}
	case LeftRight:
	{
		BalanceLeftRight();
		std::cout << "LeftRight" << std::endl;
		return;
	}
	case RightLeft:
	{
		BalanceRightLeft();
		std::cout << "RightLeft" << std::endl;
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
	// When the root is unbalanced
	/*
				(7)					5											(8)						5
			5			-->		4		7									5		  9		-->		3		 8
		4																3		6				2		  6		 9
																	2
	*/
	Node * unbalancedNode = GetUnbalancedNode();
	Node * middleNode = unbalancedNode->GetLeftNode();
	Node * bottomNode = middleNode->GetLeftNode();
	Node * lostNode = nullptr;

	// When the unbalanced Node is the root
	if (unbalancedNode == root)
	{
		// If there is no right node
		if (unbalancedNode->GetRightNode() == nullptr)
		{
			root = middleNode;
			middleNode->SetRightNode(unbalancedNode);
			unbalancedNode->SetLeftNode(nullptr);

			return;
		}
		// If there is a right node
		else
		{
			lostNode = middleNode->GetRightNode();
			// left node setRight (unbalancedNode)
			middleNode->SetRightNode(unbalancedNode); // left node loses right node
			// left node is the new root
			root = middleNode;
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
		// If the unbalanced Node is the parent's left Node
		if (unbalancedNode->GetParentNode()->GetLeftNode() == unbalancedNode)
		{
			unbalancedNode->GetParentNode()->SetLeftNode(middleNode);
		}
		// If it's the parent's right node
		else
		{
			unbalancedNode->GetParentNode()->SetRightNode(middleNode);
		}
		// Check if there is a node to be lost
		if (unbalancedNode->GetLeftNode()->GetRightNode() != nullptr)
		{
			lostNode = middleNode->GetRightNode();
		}
		middleNode->SetRightNode(unbalancedNode);
		unbalancedNode->SetLeftNode(lostNode);

		return;
	}

}

void AVLTree::BalanceRightRight()
{
	// When the root is unbalanced
	/*
	(4)							5											(3)							5
		5			-->		4		7									2		 5		-->			3		6
			7																   4	6			2	   4		8		 
																						8							
	*/

	Node * unbalancedNode = GetUnbalancedNode();
	Node * middleNode = unbalancedNode->GetRightNode();
	Node * bottomNode = middleNode->GetRightNode();
	Node * lostNode = nullptr;

	if (unbalancedNode == root)
	{
		// If there is no left node
		if (unbalancedNode->GetLeftNode() == nullptr)
		{
			root = middleNode;
			root->SetLeftNode(unbalancedNode);
			unbalancedNode->SetRightNode(nullptr);

			return;
		}
		// If there is a left node
		else
		{
			lostNode = middleNode->GetLeftNode();
			// right node setRight (unbalancedNode)
			middleNode->SetLeftNode(unbalancedNode); // right node loses left node
			// right node is the new root
			root = middleNode;
			// UnbalancedNode setRight(lost Node)
			unbalancedNode->SetRightNode(lostNode); // UnbalancedNode loses right node

			return;

		}
	}
	// When the unbalanced is not the root
	/*
		  3						  3
		2	(5)			-->		2		6
	  			6					 5		7	
					7
	*/
	else
	{
		// If the unbalanced Node is the parent's left Node
		if (unbalancedNode->GetParentNode()->GetLeftNode() == unbalancedNode)
		{
			unbalancedNode->GetParentNode()->SetLeftNode(middleNode);
		}
		// If it's the parent's right node
		else
		{
			unbalancedNode->GetParentNode()->SetRightNode(middleNode);
		}
		// Check if there is a node to be lost
		if (middleNode->GetRightNode() != nullptr)
		{
			lostNode = middleNode->GetLeftNode();
		}

		middleNode->SetLeftNode(unbalancedNode);
		unbalancedNode->SetRightNode(lostNode);

		return;
	}
	

}

void AVLTree::BalanceLeftRight()
{
	Node * unbalancedNode = GetUnbalancedNode();
	Node * middleNode = unbalancedNode->GetLeftNode();
	Node * bottomNode = middleNode->GetRightNode();
	Node * lostNode = nullptr;

	
	// If the root is unbalanced
	if (unbalancedNode == root)
	{
		// If there is no Right Node
		/*
					(7)					7					6
				5			-->		6			-->		5		7
					6			5
		*/
		if (unbalancedNode->GetRightNode() == nullptr)
		{
			unbalancedNode->SetLeftNode(bottomNode);
			bottomNode->SetLeftNode(middleNode);
			middleNode->SetRightNode(nullptr);

			BalanceLeftLeft();

			return;
		}
		// If there is a right node
		else 
		{
			// Step One
			unbalancedNode->SetLeftNode(bottomNode);
			bottomNode->SetLeftNode(middleNode);

			// If there is a right node and BottomNode has a Left Node
			/*

						(9)						9						7
					5		10	-->			7		10		-->		5		9
				4	   7				5						4	   6		10
					|6|				4	 |6|
			*/
			if (bottomNode->GetLeftNode() != nullptr)
			{

				lostNode = bottomNode->GetLeftNode();
				middleNode->SetRightNode(lostNode);
			}
			// If there is a right node and BottomNode has no Left Node
			/*

						(9)						(9)						7
					5		10	-->			7		10		-->		5		(9)
				4	   7				5	  |8|				4		 |8|	10
						|8|			4	 
			*/
			else
			{
				lostNode = bottomNode->GetRightNode();
				unbalancedNode->SetLeftNode(lostNode);
			}

			// Step Two
			root = bottomNode;
			bottomNode->SetRightNode(unbalancedNode);

			return;
			
		}
	}
	// If we are not dealing with the root
	else
	{
		// If there is a node to be lost
		if (bottomNode->GetRightNode() != nullptr)
		{
			lostNode = bottomNode->GetRightNode();
		}
		else if (bottomNode->GetLeftNode() != nullptr)
		{
			lostNode = bottomNode->GetLeftNode();
		}

		// Step 1
		unbalancedNode->SetLeftNode(bottomNode);
		bottomNode->SetLeftNode(middleNode);
		middleNode->SetRightNode(nullptr);

		
		// If the unbalanced node is a LeftNode
		if (unbalancedNode->GetParentNode()->GetLeftNode() == unbalancedNode)
		{
			unbalancedNode->GetParentNode()->SetLeftNode(bottomNode);
		}
		// If the unbalanced node is a RightNode
		else
		{
			unbalancedNode->GetParentNode()->SetRightNode(bottomNode);
		}

		// Step 2
		bottomNode->SetRightNode(unbalancedNode);
		unbalancedNode->SetLeftNode(lostNode);

		return;

	}
	

}

void AVLTree::BalanceRightLeft()
{
	Node * unbalancedNode = GetUnbalancedNode();
	Node * middleNode = unbalancedNode->GetRightNode();
	Node * bottomNode = middleNode->GetLeftNode();
	Node * lostNode = nullptr;

	// If the root is unbalanced
	if (unbalancedNode == root)
	{
		// If there is no left node
		if (unbalancedNode->GetLeftNode() == nullptr)
		{
			unbalancedNode->SetRightNode(bottomNode);
			bottomNode->SetRightNode(middleNode);
			middleNode->SetLeftNode(nullptr);

			BalanceRightRight();

			return;
		}
		// If there is left node
		else
		{
			// Step One
			unbalancedNode->SetRightNode(bottomNode);
			bottomNode->SetRightNode(middleNode);

			// If there is a left node and BottomNode has a Right Node
			if (bottomNode->GetRightNode() != nullptr)
			{

				lostNode = bottomNode->GetRightNode();
				middleNode->SetLeftNode(lostNode);
			}
			// If there is a left node and BottomNode has no Right Node
			else
			{
				lostNode = bottomNode->GetLeftNode();
				unbalancedNode->SetRightNode(lostNode);
			}

			// Step Two
			root = bottomNode;
			bottomNode->SetLeftNode(unbalancedNode);

			return;
		}
	}
	// If we are not dealing with the root
	else
	{
		
		// If there is a node to be lost
		if (bottomNode->GetRightNode() != nullptr)
		{
			lostNode = bottomNode->GetRightNode();
		}
		else if (bottomNode->GetLeftNode() != nullptr)
		{
			lostNode = bottomNode->GetLeftNode();
		}

		// Step 1
		unbalancedNode->SetRightNode(bottomNode);
		bottomNode->SetRightNode(middleNode);
		middleNode->SetLeftNode(nullptr);

		

		// If the unbalanced node is a LeftNode
		if (unbalancedNode->GetParentNode()->GetLeftNode() == unbalancedNode)
		{
			unbalancedNode->GetParentNode()->SetLeftNode(bottomNode);
		}
		// If the unbalanced node is a RightNode
		else
		{
			unbalancedNode->GetParentNode()->SetRightNode(bottomNode);
		}

		// Step 2
		bottomNode->SetLeftNode(unbalancedNode);
		unbalancedNode->SetRightNode(lostNode);

		return;

	}


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





