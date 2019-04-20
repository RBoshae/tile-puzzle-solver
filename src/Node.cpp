#include "../include/Node.h"


Node::Node()
:
  m_parent(nullptr),
  m_actionDesc(""),
  m_pathCost(0),
  m_heuristicCost(0),
  m_totalCost(0)
{
}


Node::Node(Board const &_board, int _heuristicCost)
:
  m_board(_board),
  m_parent(nullptr),
  m_actionDesc(""),
  m_pathCost(0),
  m_heuristicCost(_heuristicCost),
  m_totalCost(_heuristicCost)
{
}

Node::~Node()
{
}

void Node::setParent(Node *_parent) {
  m_parent = _parent;
}

Node* Node::getParent() const {
	return m_parent;
}

int Node::getPathCost() const {
	return m_pathCost;
}

int Node::getHeuristicCost() const {
	return m_heuristicCost;
}

int Node::getTotalCost() const
{
	return m_totalCost;
}


Board Node::getBoard() const {
	return m_board;
}


bool Node::result(MOVE _action) {
  bool validMove = m_board.move(_action);

  // Update move description.
  if (validMove) {
    switch (_action) {
      case MOVE::UP: {
        m_actionDesc = "Move Up.";
        break;
      }
      case MOVE::DOWN: {
        m_actionDesc = "Move Down.";
        break;
      }
      case MOVE::LEFT: {
        m_actionDesc = "Move Left.";
        break;
      }
      case MOVE::RIGHT: {
        m_actionDesc = "Move Right.";
        break;
      }
      default: {
        break;
      }
    }
  }

  return validMove;
}

// overloaded < operator
bool Node::operator <(const Node& _rhsNode) {
   if(m_totalCost < _rhsNode.getTotalCost()) {
      return true;
   }
   return false;
}
