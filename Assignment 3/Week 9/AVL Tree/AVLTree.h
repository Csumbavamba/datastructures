#ifndef _AVLTREE_H__
#define _AVLTREE_H__

#include <vector>

class Node;

enum UnbalanceType
{
	Balanced,
	LeftLeft,
	RightRight,
	LeftRight,
	RightLeft
};

class AVLTree
{
private:
	Node * root;
	std::vector<Node*> unbalancedNodes;
	UnbalanceType unbalanceType;
public:
	AVLTree();
	~AVLTree();

	Node * GetRoot();
	

	void InsertNode(int nodeValue);
	void DeleteNode(int nodeValue);
	Node * FindNode(int nodeValue);

	void DisplayPreOrder(Node * currentNode);
	void DisplayInOrder(Node * currentNode);
	void DisplayPostOrder(Node * currentNode);

	/// AVL functions

	UnbalanceType GetUnbalanceType() const;
	void SetUnbalanceType(UnbalanceType unbalanceType);

	void BalanceTree();
	void BalanceLeftLeft();
	void BalanceRightRight();
	void BalanceLeftRight();
	void BalanceRightLeft();

	UnbalanceType DetermineBalancingMethod(Node * unbalancedNode);
	int GetLeftHeight(Node * inspectedNode);
	int GetRightHeight(Node * inspectedNode);

	

	Node * GetUnbalancedNode();
	void FindUnbalancedNodes(Node  * currentNode);
	bool CalculateBalanceFactor(Node * inspectedNode);
	int CalculateNodeHeight(Node * inspectedNode);
	

};

#endif
