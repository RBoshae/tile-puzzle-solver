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
	Node(Board const &_board, int _heuristicCost);
  Node(Board const &_board, int const hearisticCost, Node const &_parent);

	~Node();

  void setParent(const Node* const _parent);
  void setChild(Node* _child);
  void setPathCost(unsigned int _pathCost);
  void setHeuristcCost(unsigned int _heuristicCost);

  const Node* getParent() const;
  vector<Node*> getChildren() const;
  int	  getPathCost() const;
  int   getHeuristicCost() const;
  int	  getTotalCost() const;
  Board getBoard() const;

  // Applies move to board state. Returns true if action is valid.
  // Returns false if the action is invalid.
  bool result(MOVE _action);

  // overloaded < operator
  bool operator <(Node const &_rhsNode);

private:
  Board         m_board;      	  // Board state.
  const Node*   m_parent;         // Pointer to parent node.
  vector<Node*> m_children;       // Pointer to child node.
  string        m_actionDesc;     // Move applied to reach current state.
  int           m_pathCost;       // Also known as g(n).
  int           m_heuristicCost;  // Also known as h(n).
};

#endif  //__NODE_H__
