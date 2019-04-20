//
 // A_Star.cpp
 // author Rick Boshae
 // version 1.0
 // date 2018-08-08
 // brief Function definitions for A_Star
 //

#include "../include/A_Star.h"
#include "../include/Node.h"

A_Star::A_Star(){

}

A_Star::~A_Star(){
  // Stub
}

Node* A_Star::startGraphSearch(Board &_board) {

  Node* ptrChosenNode;

  // Initialize the frontier using the initial state of the problem.
  initializeFrontier(_board);
  initializeExploredSet();

  // Start processing the frontier using the graph search algorithm.
  while(!m_frontierPQueue.empty()) {

    // Take a node from the front of the frontier priority queue.
    ptrChosenNode = m_frontierPQueue.top();
    m_frontierPQueue.pop();

    // If the node contains a goal state then return the corresponding solution.
    if (goalTest(chosenNode)) {
      return chosenNode;
    }

    // Add the node's board to the explored set.
    m_frontierOrExploredSet.insert(chosenNode->getBoard());

    // Expand the chose node, adding the resulting nodes to the frontier
    // only if not in the frontier or explored set.
    expandAndAddToFrontier(chosenNode);

  }

  return nullptr;
}

void A_Star::printSolution(){
  // Stub
}

void A_Star::initializeFrontier(Board &_startingBoard) {

  // Empty the priority queue.
  while(!m_frontierPQueue.empty()) {
    m_frontierPQueue.pop();
  }

  Node initialNode(_startingBoard);
  Node* ptrInitailNode = initialNode;

  m_graph.push_back(initialNode);
  m_frontierPQueue.push(ptrInitailNode);
}


void A_Star::initializeExploredSet() {
  m_frontierOrExploredSet.clear();
}


bool A_Star::goalTest(const Node * const _node) {
  int goalConfiguration[9] = {1,2,3,4,5,6,7,8,0};
  Board goalState(goalConfiguration);

  if(_node->getBoard() == goalState) {
    return true;
  }
  return false;
}

void A_Star::expandAndAddToFrontier(Node* _node) {
  Node child;

  child = childNode(_node, MOVE::UP);
  if (!m_frontierOrExploredSet.find(child)) {
    m_frontierOrExploredSet.insert(child);
    m_frontierPQueue.insert(child);
  }

  child = childNode(_node, MOVE::DOWN);
  if (!m_frontierOrExploredSet.find(child)) {
    m_frontierOrExploredSet.insert(child);
    m_frontierPQueue.insert(child);
  }

  child = childNode(_node, MOVE::LEFT);
  if (!m_frontierOrExploredSet.find(child)) {
    m_frontierOrExploredSet.insert(child);
    m_frontierPQueue.insert(child);
  }

  child = childNode(_node, MOVE::RIGHT);
  if (!m_frontierOrExploredSet.find(child)) {
    m_frontierOrExploredSet.insert(child);
    m_frontierPQueue.insert(child);
  }
}

Node A_Star::childNode(Node* _parentNode, MOVE action)
{
  Node child;
  return child;
}


// class Compare {
// public:
//   bool operator()(Node _leftNode, Node _rightNode)
//   {
//     if (_leftNode.getCost() < _rightNode.getCost())
//     {
//       return true;
//     }
//   }
// };
