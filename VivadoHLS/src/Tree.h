#ifndef __BDT_TREE_H__
#define __BDT_TREE_H__

#include "BaseTree.h"
#include "Node.h"

class Node;

class Tree{
public:
	Tree(BaseTree baseTree);

	int decisionFunction(int x[]);
	void constructTree();
	std::vector<Node*> leaves();

	BaseTree baseTree(){ return _baseTree; }
	std::vector<Node*> nodes(){ return _nodes; }
	std::vector<int> leafValues(){ return _leafValues; }
private:
	BaseTree _baseTree;
	std::vector<Node*> _nodes;
	double learningRate = 1.;
	std::vector<int> _leafValues;
};

#endif
