#ifndef __NODE_H__
#define __NODE_H__

#include "Tree.h"

class Tree;

class Node{

public:

	Node(Node*, int, int, double, double);

	bool nodeOnlyCompare(int X[]);
	bool depthFirstCompare(int X[]);

	bool isLeaf();

	Node* childLeft(Node* child);
	Node* childRight(Node* child);
	Node* parent(){ return _parent; }
	Node* childLeft(){ return _childLeft; }
	Node* childRight(){ return _childRight; }

	static Node* addChildLeftFirst(Node* parent, Tree* tree);

	int i(){ return _i; }
	int feature(){ return _feature; }
	double value(){ return _value; }
	double threshold(){ return _threshold; }
	bool comparison(){ return _comparison; }
	bool Ncomparison(){ return _Ncomparison; }
	bool depthFirstComparison(){ return _depthFirstComparison; }

private:
	Node* _parent;
	Node* _childLeft;
	Node* _childRight;
	int _i;
	int _feature;
	double _threshold;
	double _value;
	bool _comparison;
	bool _Ncomparison;
	bool _depthFirstComparison;
};

#endif
