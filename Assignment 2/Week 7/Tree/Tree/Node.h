#ifndef _NODE_H__
#define _NODE_H__

class Node{
private:
	int nodeValue;
	Node *parent;
	Node *leftNode;
	Node *rightNode;
public:
	Node();
	void SetNodeValue(int nodeValue);
	int GetNodeValue() const;
	void SetLeftNode(Node *leftNode);
	void SetRightNode(Node *rightNode);
	void SetParentNode(Node *parent);
	Node* GetLeftNode() const;
	Node* GetRightNode() const;
	Node* GetParentNode() const;
	
};

#endif