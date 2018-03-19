#ifndef _NODE_H__
#define _NODE_H__

class CNode{
private:
	int data;
	CNode *nextNode;
	CNode *previousNode;
public:
	CNode();
	void SetData(int data);
	int GetData() const;
	void SetPreviousNode(CNode *previousNode);
	void SetNextNode(CNode *nextNode);
	CNode* GetPreviousNode() const;
	CNode* GetNextNode() const;
	
};

#endif