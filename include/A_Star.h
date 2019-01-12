/*!
 * A_Star.h
 * \author Rick Boshae
 * \version 2.0
 * \date 2019-01-11
 * \bug code requires testing.
 *
 * \brief A_Star.h provides an abstraction for A* search algorithm.
 *
 * client must provide a heuristic function with the following characteristics:
 *            1 input parameter of DataType (see below), passed by const
 *            reference
 *            returns an unsigned int value representing the cost.
 *            the name of the function is passed as the first parameter to
 *            A_Star constructor.
 *            client may make as many heuristic functions for as many A_Star
 *            searches as desired.
 * client must also provide a goal state or target state for the algorithm.
 * Each A_Star algorithm is equipped with uniformCostSearch
 * function, however, you can achieve the same effect by
 * unconditionally returning 0 for you heuristic.
 * If an object of a struct is used for DataType, the ==operator
 * must be overloaded for it; the left and right operands are
 * both DataType objects the == comparision is used for finding
 * the goal state
 */

template <class DataType>
class A_Star {
public:
  A_Star(int (*hf)(const DataType &));
  bool uniformCostSearch();

private:
  <DataType> goal_state;
  // Variabels for storing search stats
  int nodes_expanded;           // Track number of nodes expanded.
  int max_nodes_in_queue;       // Track the maximum number of
                                // nodes in the priority queue.
  int goal_depth;               // Track the depth of the goal state.

  // Variables used for interfacing with graph.
  Node* current_node;           // Points to current node.
  priority_queue<Node*, vector<Node*>, Comp> frontier;  // a priority queue
                                                        // ordered by
                                                        // Path-Cost, with
                                                        // node as the only
                                                        // element
                                                        // TODO: fix Comp para
  set<DataType> explored;                // Set of expanded nodes.
  set<DataType> in_q;                    // Mimics nodes priority q. Prevents
                                         // new unexplored children that are // already in priority queue from
                                         // being added redundantly
                                         // TODO: Find a way to remove in_q by
                                         // using frontier.
};

#include "A_Star.cpp"
