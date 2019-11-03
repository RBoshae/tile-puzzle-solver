#include "../include/Node.h"


Node::Node()
:
  m_parent{nullptr},
  m_actionDesc{""},
  m_pathCost{0},
  m_heuristicCost{0}
{
}


Node::Node(const Board& _board, int _heuristicCost)
:
  m_board{_board},
  m_parent{nullptr},
  m_actionDesc{"Initial State."},
  m_pathCost{0},
  m_heuristicCost{_heuristicCost}
{
}


Node::~Node()
{
}


void Node::setParent(const Node* const _parent) {
  m_parent = _parent;
}


void Node::setChild(Node * _child) {
  m_children.push_back(_child);
}


void Node::setPathCost(unsigned int _pathCost)
{
  m_pathCost = _pathCost;
}

void Node::setHeuristcCost(unsigned int _heauristicCost)
{
  m_heuristicCost = _heauristicCost;
}


const Node* Node::getParent() const {
	return m_parent;
}


vector<Node*> Node::getChildren() const {
	return m_children;
}


int Node::getPathCost() const {
	return m_pathCost;
}
 

int Node::getHeuristicCost() const {
	return m_heuristicCost;
}

int Node::getTotalCost() const
{
	return m_pathCost + m_heuristicCost;
}


Board Node::getBoard() const {
	return m_board;
}

string Node::getActionApplied() const {
  return m_actionDesc;
}


bool Node::result(MOVE _action) {
  bool isValidMove = m_board.move(_action);

  // Update move description.
  if(isValidMove) {
    switch (_action) {
      case MOVE::UP: {
        m_actionDesc = "Move blank up.";
        break;
      }
      case MOVE::DOWN: {
        m_actionDesc = "Move blank down.";
        break;
      }
      case MOVE::LEFT: {
        m_actionDesc = "Move blank left.";
        break;
      }
      case MOVE::RIGHT: {
        m_actionDesc = "Move blank right.";
        break;
      }
      default: {
        break;
      }
    }
  }
  else {
    m_actionDesc = "Illegal move";
  }

  return isValidMove;
}

// overloaded < operator
bool Node::operator <(const Node& _rhsNode) {
   if((m_pathCost + m_heuristicCost) < _rhsNode.getTotalCost()) {
      return true;
   }
   return false;
}
