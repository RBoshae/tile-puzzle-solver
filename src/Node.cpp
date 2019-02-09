#include "../include/Node.h"



Node::Node()
{
	f_of_n = 0;
	h_of_n = 0;
	node_depth = 0;
	path_cost = 0;
	move_applied = "initial state";
	parent = NULL;
}


Node::~Node()
{
}

int Node::getCost()
{
	return f_of_n;
}

//set current node to point to parent. node_depth is modified here since we must know the depth of our parent to get the depth of the child
void Node::setParentNode(Node *passed_parent)
{
	parent = passed_parent;
	node_depth = passed_parent->getNodeDepth() + 1;
	f_of_n = node_depth + h_of_n;
	//board_history.push_back(passed_parent->getBoard());
}

Node* Node::getParentNode() {
	return parent;
}

Node Node::previous_state(Node current_state)
{
	// if (current_state.move_applied == "blank tile right") current_state.getBoard().move(3); return current_state;
	return current_state; // TODO: Remove line.
}

Board Node::getBoard()
{
	return node_board;
}

void Node::printNodeBoard()
{
	// node_board.printBoard();
}

int Node::getNodeDepth(){
	return node_depth;
}

int Node::getFofN() {
	//possibly redundant
	f_of_n = node_depth + h_of_n;
	return f_of_n;
}
