#include "Node.h"



Node::Node()
{
	f_of_n = 0;
	h_of_n = 0;
	node_depth = 0;
	move_applied = "initial state";
	parent = NULL;
}


Node::~Node()
{
}

//set current node to point to parent. node_depth is modified here since we must know the depth of our parent to get the depth of the child
void Node::setParentNode(Node  passed_parent)
{
	parent = &passed_parent;
	node_depth = passed_parent.node_depth + 1;
	f_of_n += node_depth;
}

Node* Node::getParentNode() {
	return parent;
}

void Node::setBoard(Board b)
{
	node_board = b;
}

Board Node::getBoard()
{
	return node_board;
}

void Node::printNodeBoard()
{
	node_board.printBoard();
}

int Node::getNodeDepth(){
	return node_depth;
}

int Node::getFofN() {
	return f_of_n;
}