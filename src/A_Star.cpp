/*!
 * A_Star.cpp
 * \author Rick Boshae
 * \version 1.0
 * \date 2018-08-08
 * \brief Function definitions for A_Star
 */

#include "../include/A_Star.h"
#include "../include/Node.h"

A_Star::A_Star(){

}

A_Star::~A_Star(){
  // Stub
}

Node* A_Star::graphSearch(Board const &_board) {

  Node* chosenNode;

  initializeFrontier(_board);                                 // Initialize the frontier using the inital state of the problem.
  initializeExploredSet();                                    // Initialize the explored set to be empty.

  while(!m_frontierQueue.empty()) {                           // If the frontier is empty return failure.
    chosenNode = m_frontierQueue.top();                       // Choose a leaf node.
    m_frontierQueue.pop();                                    // Remove leaf node from the frontier.

    if (containsGoalState(chosenNode)) {                      // If the node contains a goal state then return the corresponding solution.
      return chosenNode;
    }

    m_frontierOrExploredSet.insert(&chosenNode.getBoard());   // Add the node to the explored set.

    expandAndAddToFrontier(&chosenNode)                       // expand the chose node, adding the resulting nodes to the frontier
                                                              // only if not in the frontier or explored set.

  }

  return nullptr;
}

void A_Star::printSolution(){
  // Stub
}

void A_Star::initializeFrontier(Board const &_startingBoard) {
  while(!m_frontierQueue.empty()) {
    m_frontierQueue.pop();
  }

  Node initialNode(_startingBoard, 0);                          // Instantiate initial node.
  m_frontierQueue.push(initialNode);
}


void A_Star::initializeExploredSet() {
  m_exploredSet.clear();
}


bool A_Star::containsGoalState(Node const &_node) {
  Board goalState({1,2,3,4,5,6,7,8,0});

  if(_node.getBoard() == goalState) {
    return true;
  }
  return false;
}

bool A_Star::expandAndAddToFrontier(Node const &_node) {

}

Node A_Star::childNode(Node const &_parentNode, MOVE action)
{
  Node childNode()
  retrun childNode;
}


class Compare {
public:
  bool operator()(Node _leftNode, Node _rightNode)
  {
    if (_leftNode.getCost() < _rightNode.getCost())
    {
      return true;
    }
  }
};
