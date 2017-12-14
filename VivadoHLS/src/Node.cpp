#include "Node.h"

Node::Node(Node* parent, int i, int feature, double threshold, double value){
	_parent = parent;
	_i = i;
	_feature = feature;
	_threshold = threshold;
	_value = value;
}

/**
 * Execute the node comaprison
 */
bool Node::nodeOnlyCompare(int X[]){
	// TODO: check if HLS redoes the computation
	// each time this function is called
	if(!_comparison){
		_comparison = X[_feature] <= _threshold;
		_Ncomparison = !_comparison;
	}
	return _comparison;
}

/**
 * Determine if the decision path passes through this node
 */
bool Node::depthFirstCompare(int X[]){
	bool value;
	if(!this->_parent){ // root node
		value = true;
	}else{
		if(this == this->_parent->_childLeft){ // this is the left child
			value = this->_parent->_depthFirstComparison && this->_parent->_comparison;
		}else{ // this is the right child
			value = this->_parent->_depthFirstComparison && this->_parent->_Ncomparison;
		}
	}
	this->_depthFirstComparison = value;
	return value;
}

/**
 * Check if node is leaf
 */
bool Node::isLeaf(){
	return (!_childLeft && !_childRight);
}

Node* Node::childLeft(Node* child){
	if(child){
		return this->_childLeft;
	}else{
		this->_childLeft = child;
		return child;
	}
}

Node* Node::childRight(Node* child){
	if(child){
		return this->_childRight;
	}else{
		this->_childRight = child;
		return child;
	}
}

Node* Node::addChildLeftFirst(Node* parent, Tree* tree){
	int iC; // child index in basetree
	Node* newNode = parent;
	if(!parent->_childLeft){
		iC = tree->baseTree().childrenLeft()[parent->_i];
		if(iC != -1){
			newNode = new Node(parent, iC, tree->baseTree().features()[iC], tree->baseTree().thresholds()[iC], tree->baseTree().values()[iC]);
			parent->childLeft(newNode);
		}
	}else if(!parent->_childRight){
		iC = tree->baseTree().childrenRight()[parent->_i];
		if(iC != -1){
			newNode = new Node(parent, iC, tree->baseTree().features()[iC], tree->baseTree().thresholds()[iC], tree->baseTree().values()[iC]);
			parent->childRight(newNode);
		}
	}
	return newNode;
}
