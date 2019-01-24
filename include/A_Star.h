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

enum class HEURISTIC {UNIFORM_COST_SEARCH, MISPLACED_TILE, MANHATTAN_DISTANCE, ALL}

class A_Star {
public:
  A_Star();
  ~A_Star();

  void solve(Board _board, HEURISTIC h);

  void print_solution();
  void getNumberOfNodesExpanded();
  void getMaxNodesInQueue();
void getGoalDepth();
private:
  bool uniformCostSearch();
  bool misplacedTile();
  bool manhattanDistance();

  Board goal_state;
  
  // Variables for storing search stats
  int nodes_expanded;                                   // Track number of nodes expanded.
  int max_nodes_in_queue;                               // Track the maximum number of
                                                        // nodes in the priority queue.
  int goal_depth;                                       // Track the depth of the goal state.

  // Variables used for interfacing with graph.
  Node* current_node;                                   // Points to current node.
  priority_queue<Node*, vector<Node*>, Comp> frontier;  // a priority queue
                                                        // ordered by
                                                        // Path-Cost, with
                                                        // node as the only
                                                        // element
                                                        // TODO: fix Comp para
  set<DataType> explored;                               // Set of expanded nodes.
  set<DataType> in_q;                                   // Mimics nodes priority q. Prevents
                                                        // new unexplored children that are // already in priority queue from
                                                        // being added redundantly
                                                        // TODO: Find a way to remove in_q by
                                                        // using frontier.
};
