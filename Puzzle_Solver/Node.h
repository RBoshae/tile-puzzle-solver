/*
* File: Node.h
* ---------------------
*
* Created by Rick Boshae on 2/11/17.
*
*/

#include "Board.h"
#include <string>
#include <vector>

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
	vector<Board> board_history;

	int h_of_n;            //Contains value of h(n). Will create setter for this and make private.

private:
	int f_of_n;			   //Contains value of f(n)
	int path_cost;         //Path Cost of Node
	int node_depth;		   //Keeps track of node depth. Later used to compute g(n)
	int manhattan_distance;
	int misplaced_tile;
	Node* parent;          //Points to parent node in tree.
	Board node_board;      // Contains copy of Board

};

#endif
