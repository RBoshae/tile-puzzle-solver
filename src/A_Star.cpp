//
// A_Star.cpp
// author Rick Boshae
// version 1.0
// date 2018-08-08
// brief Function definitions for A_Star
//

#include "../include/A_Star.h"
#include "../include/Node.h"

A_Star::A_Star()
:
m_heuristic{HEURISTIC::UNIFORM_COST_SEARCH},
m_nodesExpanded{0},
m_maxNodesInQueue{0},
m_goalDepth{0}
{
}

A_Star::~A_Star() {
  while(!m_frontierPQueue.empty()) {
    Node* pNode = m_frontierPQueue.top();
    m_frontierPQueue.pop();
    delete pNode;
  }
}

void A_Star::setHeuristic(HEURISTIC _choice) {
  m_heuristic = _choice;
}

Node* A_Star::graphSearch(Board const &_boardProblem) {

  // Initialize the frontier using the initial state of the problem.
  cout << "Initializing...";
  initializeExploredSet();
  initializeFrontier(_boardProblem);

  cout << "Starting seach." << endl << endl;

  // Start processing the frontier using the graph search algorithm.
  while(!m_frontierPQueue.empty()) {

    // Update max nodes in queue.
    if(m_maxNodesInQueue < m_frontierPQueue.size())
    {
      m_maxNodesInQueue = m_frontierPQueue.size();
    }

    // Choose the shallowest node in the frontier.
    Node* pChosenNode = m_frontierPQueue.top();
    m_frontierPQueue.pop();

    // If the node contains a goal state then return the corresponding solution.
    if(containsGoalState(pChosenNode)) {
      m_goalDepth = pChosenNode->getPathCost();
      return m_goalNode = pChosenNode;
    }

    ///
    // Goal test failed. Continue searching...
    ///

    // Add the node's board to the explored set.
    m_frontierOrExploredSet.insert(pChosenNode->getBoard());

    // Expand the chose node, adding the resulting nodes to the frontier
    // only if not in the frontier or explored set.
    cout << "Expanding node with total cost " <<  pChosenNode->getTotalCost() << ":" << endl;
    pChosenNode->getBoard().print();
    expandAndAddToFrontier(pChosenNode);
  }

  return nullptr;
}

unsigned int A_Star::getNumberOfNodesExpanded() {
  return m_nodesExpanded;
}


unsigned int A_Star::getMaxNodesInQueue() {
  return m_maxNodesInQueue;
}


unsigned int A_Star::getGoalDepth() {
  return m_goalDepth;
}


void A_Star::printSolution(){
  
  // Get solution information.
  const Node* pCurrentNode = m_goalNode;
  vector<const Node*> solution;
  while (pCurrentNode->getParent() != nullptr)
  {
    solution.push_back(pCurrentNode);
    pCurrentNode = pCurrentNode->getParent();
  }

  solution.push_back(pCurrentNode);

  for(int index = solution.size()-1; index >= 0; --index) {
    cout << solution.at(index)->getActionApplied() << endl;
    solution.at(index)->getBoard().print();
    cout << endl; 
  }

  cout << "Solution reached." << endl;
}


void A_Star::initializeFrontier(Board const &_initialBoard) {

  // Empty the priority queue.
  while(!m_frontierPQueue.empty()) {
    Node* topNode = m_frontierPQueue.top();
    m_frontierPQueue.pop();
    delete topNode;
  }

  Node* pInitialNode = new Node(_initialBoard, 0);

  m_frontierPQueue.push(pInitialNode);
}


void A_Star::initializeExploredSet() {
  m_frontierOrExploredSet.clear();
}


bool A_Star::containsGoalState(const Node* const _node) {
  int goalConfiguration[9] = {1,2,3,4,5,6,7,8,0};
  Board goalState(goalConfiguration);

  if(_node->getBoard() == goalState) {
    return true;
  }
  return false;
}


void A_Star::expandAndAddToFrontier(const Node* const _node) {

  const MOVE MOVE_LIST[] = {MOVE::UP, MOVE::DOWN, MOVE::LEFT, MOVE::RIGHT};

  // Generate child nodes.
  for(unsigned int move = 0; move < 4; ++move) {

    Node *pChildNode = createChildNode(_node, MOVE_LIST[move]);

    // Do not add the child node to the fronteir if the child is already
    //  in the frontier or in the explored set.
    Board board = pChildNode->getBoard();
    if(m_frontierOrExploredSet.find(board) == m_frontierOrExploredSet.end()) 
    {
      m_frontierOrExploredSet.insert(board);
      m_frontierPQueue.push(pChildNode);
    } else {
      delete pChildNode;
    }
  } // End of for loop.

  // Update nodes expanded
  ++m_nodesExpanded;
}


Node* A_Star::createChildNode(const Node* const _parentNode, MOVE _move)
{
  Node* childNode = new Node(_parentNode->getBoard());
  childNode->setParent(_parentNode);
  childNode->setPathCost(1 + _parentNode->getPathCost());
  childNode->result(_move);
  
  // Set heauristic cost.
  switch (m_heuristic)
  {
  case HEURISTIC::UNIFORM_COST_SEARCH:
    childNode->setHeuristcCost(0);
    break;
  case HEURISTIC::MISPLACED_TILE:
    /* code */
    break;
  case HEURISTIC::MANHATTAN_DISTANCE:
    /* code */
    break;
  case HEURISTIC::ALL:
    /* code */
    break;
  
  default:
    cerr << "Something went wrong with heuristic choice. Exiting" << endl;
    exit(1);
    break;
  }

  return childNode;
}