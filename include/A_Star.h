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

class A_Star {
public:
  A_Star();
  ~A_Star();

  bool uniformCostSearch(Board _board);
  bool misplacedTile(Board _board);
  bool manhattanDistance(Board _board);

  void print_solution();
  void getNumberOfNodesExpanded();
  void getMaxNodesInQueue();
  void getGoalDepth();
private:


  Board goal_state;

  // Variables for storing search stats
  int m_nodesExpanded;                                   // Track number of nodes expanded.
  int m_maxNodesInQueue;                                 // Track the maximum number of
                                                         // nodes in the priority queue.
  int m_goalDepth;                                       // Track the depth of the goal state.

  // Variables used for interfacing with graph.
  Node* m_currentNode;                                   // Points to current node.
  priority_queue<Node*, vector<Node*>, Comp> m_frontier; // a priority queue
                                                         // ordered by
                                                         // Path-Cost, with
                                                         // node as the only
                                                         // element
                                                         // TODO: fix Comp para
  set<DataType> m_explored;                              // Set of expanded nodes.
  set<DataType> M_inQueue;                               // Mimics nodes priority q. Prevents
                                                         // new unexplored children that are // already in priority queue from
                                                         // being added redundantly
                                                         // TODO: Find a way to remove in_q by
                                                         // using frontier.
};
