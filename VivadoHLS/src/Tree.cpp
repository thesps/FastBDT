#include "Tree.h"
#include "Node.h"

Tree::Tree(BaseTree baseTree) : _baseTree(baseTree){}

int Tree::decisionFunction(int x[]){
	int scores[leaves().size()];
	bool leafDecision[leaves().size()];
	int iLeaf = 0;
	int score;
	for(Node* leaf : leaves()){
		if(leaf->depthFirstCompare(x))
			score = leaf->value();
	}
	return score;
}

/**
 * Return all of the leaf nodes
 */
std::vector<Node*> Tree::leaves(){
	std::vector<Node*> leaves;
	for(Node* node : _nodes){
		if(node->isLeaf())
			leaves.push_back(node);
	}
	return leaves;
}

/**
 * Construct the tree structure from the base tree
 */
void Tree::constructTree(){
	int iN = 0;
	std::vector<Node*> nodes(sizeof(_baseTree.childrenLeft())/sizeof(*_baseTree.childrenLeft()));
	Node* null;
	Node* n= new Node(null, iN, _baseTree.features()[iN], _baseTree.thresholds()[iN], _baseTree.values()[iN]);
	nodes.push_back(n);
	bool done = false;
	while(!done){
		if((n->i() == 0) && n->childLeft() && n->childRight()){
			// At the root node with both children, so done
			done = true;
			break;
		}
		if((_baseTree.childrenLeft()[n->i()] == -1) | (n->childLeft() && n->childRight())){
			// Need to ascend
			n = n->parent();
		}
		Node* lastN = n;
		n = Node::addChildLeftFirst(n, this);
		if(n != lastN){ // A new node was added
			nodes.push_back(n);
		}
	}
	this->_nodes = nodes;
}
