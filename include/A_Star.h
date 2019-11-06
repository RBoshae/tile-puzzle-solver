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

struct customCompare
{
    bool operator()(const Node* lhs, const Node* rhs)
    {
        return lhs->getTotalCost() > rhs->getTotalCost();
    }
};




class A_Star {
public:
	A_Star();
	~A_Star();

	void setHeuristic(HEURISTIC _choice);

	// Returns the solution to the problem.
	Node* graphSearch(const Board& _boardProblem);

	void printSolution();

	unsigned int getNumberOfNodesExpanded();
	unsigned int getMaxNodesInQueue();
	unsigned int getGoalDepth();

private:

	HEURISTIC m_heuristic;
	// PQ ordered by the Node with the lowest cost.
	priority_queue<Node*, vector<Node *>, customCompare > m_frontierPQueue;

	// Tracks states that have already been expanded or in the frontier.
	set<Board> m_frontierOrExploredSet;

	// Pointer to goal node containing the goal state.
	Node* m_goalNode;

	// Search stats.
	unsigned int m_nodesExpanded;
	unsigned int m_maxNodesInQueue;
	unsigned int m_goalDepth;


	void   initializeFrontier(const Board& _initialBoard);
	void   initializeExploredSet();
	bool   containsGoalState(const Node* const _node);
	void   expandAndAddToFrontier(const Node* const _node);
	Node*  createChildNode(const Node* const _parentNode, MOVE action);

};
