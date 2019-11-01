// A_Star.h
// Author Rick Boshae
// Version 2.0
// Date 2019-01-11
// Bug code requires testing.
//
// brief A_Star.h provides an abstraction for A* search algorithm.

#include <set>
#include <queue>
#include <vector>

#include "Node.h"
#include "Board.h"

enum class HEURISTIC {
	MISPLACED_TILE, 
	MANHATTAN_DISTANCE, 
	UNIFORM_COST_SEARCH, 
	ALL};

class A_Star {
public:
	A_Star();
	~A_Star();

	// Returns the solution to the problem.
	Node* graphSearch(
		const Board& _boardProblem,
		HEURISTIC   _hearisticChoice 
	);

	void printSolution();

	void getNumberOfNodesExpanded();
	void getMaxNodesInQueue();
	void getGoalDepth();

private:
	// PQ ordered by the Node with the lowest cost.
	priority_queue<Node*> m_frontierPQueue;

	// Tracks states that have already been expanded or in the frontier.
	set<Board> m_frontierOrExploredSet;

	// Pointer to goal node containing the goal state.
	Node* m_goalNode;

  // Search stats.
  int m_nodesExpanded;
  int m_maxNodesInQueue;
  int m_goalDepth;


  void   initializeFrontier(const Board& _initialBoard);
  void   initializeExploredSet();
  bool   containsGoalState(const Node* const _node);
  void   expandAndAddToFrontier(const Node* const _node);
  Node*  createChildNode(const Node* const _parentNode, MOVE action);

};
