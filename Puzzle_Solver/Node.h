/*
* File: Node.h
* ---------------------
*
* Created by Rick Boshae on 2/11/17.
*
*/

#include "Board.h"
#include <string>

#ifndef NODE_H
#define NODE_H
class Node
{
public:
	Node();
	~Node();

	void setParentNode(Node *passed_parent);
	Node* getParentNode();
	Node previous_state(Node current_state);
	
	void setBoard(Board b);
	Board getBoard();
	void printNodeBoard();


	int getNodeDepth();

	int getFofN();
	string  move_applied;  //Keeps track of move applied to node



private:
	int f_of_n;			   //Contains value of f(n)
	int h_of_n;            //Contains value of h(n)
	int node_depth;		   //Keeps track of node depth. Later used to compute g(n)
	Node* parent;          //Points to parent node in tree.
	Board node_board;      // Contains copy of Board

};

#endif
