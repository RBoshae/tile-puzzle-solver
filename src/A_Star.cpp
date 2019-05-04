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

Node* A_Star::startGraphSearch(Board const &_initialState,
                               HEURISTIC _hearisticOption) {

  Node* ptrChosenNode;

  // Initialize the frontier using the initial state of the problem.
  initializeFrontier(_initialState);
  initializeExploredSet();

  cout << "Starting seach." << endl;
  // Start processing the frontier using the graph search algorithm.
  while(!m_frontierPQueue.empty()) {

    // Take a node from the front of the frontier priority queue.
    ptrChosenNode = m_frontierPQueue.top();
    m_frontierPQueue.pop();

    // If the node contains a goal state then return the corresponding solution.
    if (goalTest(ptrChosenNode)) {
      return ptrChosenNode;
    }

    // Add the node's board to the explored set.
    m_frontierOrExploredSet.insert(ptrChosenNode->getBoard());

    // Expand the chose node, adding the resulting nodes to the frontier
    // only if not in the frontier or explored set.
    expandAndAddToFrontier(*ptrChosenNode);

  }

  return nullptr;
}

void A_Star::printSolution(){
  // TODO: Stub
}

void A_Star::initializeFrontier(Board const &_startingBoard) {

  cout << "Initializing..." << endl;
  // Empty the priority queue.
  while(!m_frontierPQueue.empty()) {
    m_frontierPQueue.pop();
  }

  Node* pInitialBoard = new Node(_startingBoard);

  m_frontierPQueue.push(pInitialBoard);
}


void A_Star::initializeExploredSet() {
  m_frontierOrExploredSet.clear();
}


bool A_Star::goalTest(Node *_node) {
  int goalConfiguration[9] = {1,2,3,4,5,6,7,8,0};
  Board goalState(goalConfiguration);

  if(_node->getBoard() == goalState) {
    return true;
  }
  return false;
}


void A_Star::expandAndAddToFrontier(Node &_node) {

  const MOVE ALL_MOVES[] = {MOVE::UP, MOVE::DOWN, MOVE::LEFT, MOVE::RIGHT};

  // Generate child nodes.
  for(unsigned int moveNumber = 0; moveNumber < 4; moveNumber++) {

    Node *ptrChildNode = createChildNode(_node, ALL_MOVES[moveNumber]);

    // Do not add the child node to the fronteir if the child is already
    //  in the frontier or in the explored set.
    m_frontierOrExploredSet.find(ptrChildNode->getBoard());
    if (true) {
      m_frontierOrExploredSet.insert(ptrChildNode->getBoard());
      m_frontierPQueue.push(ptrChildNode);
    } else {
      delete ptrChildNode;
    }

  } // End of for loop.
}

Node* A_Star::createChildNode(Node &_parentNode, MOVE _move)
{
  Node *child = new Node(_parentNode.getBoard());
  child->setParent(&_parentNode);
  child->result(_move);
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
