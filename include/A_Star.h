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
#include <queue>
#include <vector>

class A_Star {
public:
  A_Star();
  ~A_Star();

  // Returns the solution to the problem.
  Node* startGraphSearch(Board &_board);

  void printSolution();

  void getNumberOfNodesExpanded();
  void getMaxNodesInQueue();
  void getGoalDepth();

private:

  // The underlying structure that will hold all nodes generted. This
  // structure is also necessary to return the solution trace.
  vector<Node> m_graph;

  // PQ ordered by the Node with the lowest cost.
  priority_queue<Node*> m_frontierPQueue;

  // Tracks boards that have already been expanded or in the frontier.
  set<Board> m_frontierOrExploredSet;

  Node* m_goalNode;

  // Search stats.
  int m_nodesExpanded;
  int m_maxNodesInQueue;
  int m_goalDepth;


  void initializeFrontier(Board &_startingBoard);
  void initializeExploredSet();
  bool goalTest(Node *_node);
  void expandAndAddToFrontier(Node* _node);
  Node childNode(Node const &_parentNode, MOVE action);

};
