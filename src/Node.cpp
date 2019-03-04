#include "../include/Node.h"


Node::Node()
:
  m_board(),
  m_parent(nullptr),
  m_moveDesc(""),
  m_pathCost(0),
  m_heuristicCost(),
  m_totalCost()
{
}


Node::Node(Board const &_board, int _heuristicCost)
:
  m_board(_board),
  m_parent(nullptr),
  m_moveDesc(""),
  m_pathCost(0),
  m_heuristicCost(_heuristicCost),
  m_totalCost(_heuristicCost)
{
}

Node::Node(Board const &_board, int _heuristicCost, Node const &_parent,  string const _moveApplied)
:
  m_board(_board),
  m_parent(_parent),
  m_moveDesc(_moveApplied),
  m_pathCost(_parent->getPathCost+1),
  m_heuristicCost(_heuristicCost),
  m_totalCost(m_pathCost+m_heuristicCost)
{
}

Node::~Node()
{
}

Node* Node::getParentNode() {
	return m_parent;
}

int Node::getPathCost()
{
	return m_pathCost;
}

int Node::getHeuristicCost()
{
	return m_heuristicCost;
}

int Node::getTotalCost()
{
	return m_totalCost;
}


Board Node::getBoard()
{
	return node_board;
}

// overloaded < operator
bool Node::operator <(const Node& _node) {
   if(m_totalCost < _node.getTotalCost()) {
      return true;
   }
   return false;
}
