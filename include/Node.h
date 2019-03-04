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

#ifndef __NODE_H__
#define __NODE_H__
class Node
{
public:
  Node();
	Node(Board const &_board, int _heuristicCost);
  Node(Board const &_board, int const hearisticCost, Node const &_parent);

	~Node();

  Node* getParentNode();

  int 	getPathCost();
  int   getHeuristicCost();
  int 	getTotalCost();

	Board getBoard();

  // overloaded < operator
  bool operator <(const Node& _node);


private:
  Board   m_boardState;      	  // Contains copy of Board
  Node*   m_parent;          	  // Pointer to parent node.
  string  m_action;             // Description of move applied to parent to reach current state.
  int     m_pathCost;           // Also known as g(n).
  int     m_heuristicCost;      // Also known as h(n).
	int     m_totalCost;		   	  // Contains value of f(n)


};

#endif  //__NODE_H__
