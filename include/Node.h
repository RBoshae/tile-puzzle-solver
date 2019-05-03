/*
* File: Node.h
* ---------------------
*
* Created by Rick Boshae on 2/11/17.
*
*/

#ifndef __NODE_H__
#define __NODE_H__

#include "Board.h"
#include <string>
#include <vector>

class Node
{
public:
  Node();
	Node(Board const &_board, int _heuristicCost = 0);
  Node(Board const &_board, int const hearisticCost, Node const &_parent);

	~Node();

  void  setParent(Node* _parent);

  Node* getParent() const;

  int	  getPathCost() const;
  int   getHeuristicCost() const;
  int	  getTotalCost() const;
  Board getBoard() const;

  // Applies move to board state. Returns true if action is valid.
  // Returns false if the action is invalid.
  bool result(MOVE _action);

  // overloaded < operator
  bool operator <(const Node& _rhsNode);

private:
  Board   m_board;      	      // Contains copy of Board
  Node*   m_parent;          	  // Pointer to parent node.
  string  m_actionDesc;         // Description of move applied to parent to
                                // reach current state.
  int     m_pathCost;           // Also known as g(n).
  int     m_heuristicCost;      // Also known as h(n).
	int     m_totalCost;		   	  // Contains value of f(n)


};

#endif  //__NODE_H__
