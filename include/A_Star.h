/*!
 * A_Star.h
 * \author Rick Boshae
 * \version 2.0
 * \date 2019-01-11
 * \bug code requires testing.
 *
 * \brief A_Star.h provides an abstraction for A* search algorithm.
 *
 */
#include "Board.h"
#include "Node.h"
#include <set>

class A_Star {
public:
  A_Star();
  ~A_Star();

  bool uniformCostSearch(Board* _board);
  bool misplacedTile(Board* _board);
  bool manhattanDistance(Board* _board);

  void printSolution();
  void getNumberOfNodesExpanded();
  void getMaxNodesInQueue();
  void getGoalDepth();

private:
  set<Board*>            m_exploredSet;                  // Set of boards that have already been expanded.
  priority_queue<Node*>  m_frontier;                     // PQ ordered by the Node with the lowest cost.

  // Search stats.
  int m_nodesExpanded;                                   // Track number of nodes expanded.
  int m_maxNodesInQueue;                                 // Track the maximum number of
                                                         // nodes in the priority queue.
  int m_goalDepth;                                       // Track the depth of the goal state.

};
