/*!
 * A_Star.cpp
 * \author Rick Boshae
 * \version 1.0
 * \date 2018-08-08
 * \brief Function definitions for A_Star
 */

#include "../include/Board.h"

A_Star::A_Star(){
  // Stub
}

A_Star::~A_Star(){
  // Stub
}

bool A_Star::uniformCostSearch(Board _board){
  // Stub
}
bool A_Star::misplacedTile(Board _board){
  // Stub
}
bool A_Star::manhattanDistance(Board _board){
  // Stub
}

class Compare {
public:
  bool operator()(Node _leftNode, Node _rightNode)
  {
    if (_leftNode.getCost() < __rightNode.getCost())
    {
      return true;
    }
  }
}
// template <class DataType>
// A_Star<DataType>::A_Star(int (*hf)(const DataType &), <DataType> &gs)
// :  nodes_expanded(0), max_nodes_in_queue(0), goal_depth(0)
// {
//   heuristicFunction = hf;           // Assign client provided heuristic.
//   goal_state = gs;                  // Assign client provided goal state.
// }
// template <class DataType>
// bool A_Star<DataType>::uniformCostSearch(const DataType & newObject)
// {
//   Node* initial_node = new Node();  // Allocate space for initial node.
//   initial_node->obj = newObject;
//   current_node = initial_node;      // set current_node to initial_node

//   frontier.push(current);

//   // Keep expanding nodes until found goal state or frontier is empty.
//   while (!frontier.empty()) {

// 		current = frontier.top();       // Set current to the lowest-cost
//                                     // node in frontier
// 		frontier.pop();                 // Pop frontier

// 		// Remove popped board from in_q
//     auto search = in_q.find(current->obj);  // Check if current object is
//                                             // in in_q
// 		if (search != in_q.end()) {
// 			in_q.erase(search);
// 		}

// 		// Perform goal test on current node
// 		if (current->obj == goal_state) {
// 			goal_depth = current->getNodeDepth();
//       return true;           // Uniform Cost Search is complete.
//     }

//     // Goal test failed. Continue search
//     explored.insert(current->getBoard());         // Add current node to
//                                                   // explored set.

// 		// Conditional output that will differ the first
//     // expansion from all others.
// 		if (current->nodeDepth() == 0) {
// 			cout << "Expanding state" << endl;
// 			current->printObj();
// 		}
// 		else {
// 			cout << "The best state to expand with g(n) = "
//            << current->nodeDepth() << " is..." << endl;
// 			current->printObj();
// 		}

// 		nodes_expanded++;                   // Increment number of nodes expanded.

//     // Expand node / Generate children
//     // For each legal action, create a child node. If child node is not yet
//     // in the explored or frontier add to frontier.
//     for (int action = 0; action < action_count - 1; i++) {

//       <DataType> childObj = applyAction(current, i);  // applyAction
//                                                       // transforms current
//                                                       // obj to child obj.


//       auto search = explored.find(childObj); // Check if child_node is
//                                              // already in explored_set.
//       if (search != explored.end()) {        // If child exists, skip insert.
//         continue;
//       }

//       search = in_q.find(childObj);          // Check if child_node is
//                                              // already in explored_set
// 				if (search != in_q.end() ) {
// 						continue;                        // If child exists, skip insert.
// 				}


//       // Child not in explored_set or in_q. Wrap childObj in a node and
//       // insert into frontier.
//       Node* child_node = new Node;          // Create new childe node.
//       child_node->obj = childObj;           // Wrap childObj in node.
//       in_q.insert(child_node);              // Add node to in_q
//       frontier.push(child_node);            // Add node to frontier.


// 		} // End of for loop.

//     // Parent node expanded. Check/Record maximum number of nodes in frontier.
//     if (frontier.size() > max_nodes_in_q)
//       max_nodes_in_q = frontier.size();

//   } // End of While loop

//   // Frontier is empty. Thus, no solution.
//   return false;
// }
