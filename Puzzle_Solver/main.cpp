/*
 * File: main.cpp
 * ----------------
 * Created by Rick Boshae on 1/29/17.
 *
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "Board.h"
#include "Node.h"
#include <map>
#include <set>
#include <ctime>
#include <algorithm>


//#include "Problem.h" - removing because it feels unecessary

using namespace std;

//Used to make object comparison in priorty queue 
struct Comp {
	bool operator () (Node lhs, Node rhs) {
		if (lhs.getFofN() == rhs.getFofN()) {

			return lhs.getNodeDepth() > rhs.getNodeDepth();

		}
		return lhs.getFofN() > rhs.getFofN();
	}
	
	bool operator () (Node* lhs, Node* rhs) {
		if (lhs->getFofN() == rhs->getFofN()) {
			
			return lhs->getNodeDepth() > rhs->getNodeDepth();
			
		} else
		return lhs->getFofN() > rhs->getFofN();
	}
};

bool graph_search(Board b, int heuristic_decision);
bool uniform_cost_search(Board b);
Node* createChildNode(Node *parent, int action, int h);
Board random_board();

//Global Vaiables used to collect data on heuristics	
double Uniform_Cost_Search_Avg_Expansions;
double Uniform_Cost_Search_Avg_PQ;

double Manhattan_Avg_Expansions;
double Manhattan_Avg_PQ;

double Misplaced_Tile_Avg_Expansions;
double Misplaced_Tile_Avg_PQ;

int main() {

	int menu_selection = 0;
	bool valid = false;                        //used to verify user input during prompts is valid
	Board testBoard = random_board();
	int heuristic_choice;
	
	//Prompt #1
	cout << "Welcome to Rick's 8-puzzle solver." << endl;
	cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;

	//while loop validates user input
	while (!valid) {

		valid = true; //Assume the cin will be an integer

		cin >> menu_selection;

		if (cin.fail()) {                                          //cin.fail() checks to see if the value in the cin stream is the correct type, if not returns true, otherwise false.
			cin.clear();                                           //This corrects the stream
			cin.ignore();                                          // This skips the left over stream data
			cout << "Please enter an integer value only." << endl;
			valid = false;                                         //The cin was not an integer so try again.
		} 
	}

	valid = false;                                                 //valid will be resused so we set it back to false


	switch (menu_selection)
	{

		case 1: cout << "default puzzle selected:" << endl; 
			testBoard.printBoard();
				cout << endl;
			break;
		case 2: cout << "custom puzzle selected." << endl;
			
			cout << "This is your Board:" << endl;
			testBoard.setBoard();                                //declare new board object
			break;
		default: cout << "Invalid Input. Please be sure to enter \"1\" or \"2.\"" << endl;
			break;
	} 




	//Prompt #2
	cout << endl;
	cout << "Enter your choice of algorithm" << endl;
	cout << "\t1. Uniform Cost Search" << endl;
	cout << "\t2. A* with the Misplaced Tile heuristic." << endl;
	cout << "\t3. A* with the Manhattan distance heuristic." << endl;
	cout << "\t";

	while (!valid) {

		valid = true;                          //Assume the cin will be an integer

		cin >> heuristic_choice;

		if (cin.fail()) {                      //cin.fail() checks to see if the value in the cin stream is the correct type, if not returns true, otherwise false.
			cin.clear();                       //This corrects the stream
			cin.ignore();                      // This skips the left over stream data
			cout << "Please enter an integer value only." << endl;
			valid = false;                     //The cin was not an integer so try again.
		}
	}



	switch (heuristic_choice)
	{

	case 1: cout << "Uniform Cost Search selected" << endl; uniform_cost_search(testBoard);
		break;
	case 2: cout << "A* with the Misplaced Tile heuristic selected." << endl; graph_search(testBoard, 1);
		break;
	case 3: cout << "A* with the Manhattan distance heuristic selected." << endl; graph_search(testBoard, 2);
		break;
	//Secret Option Used to compare heuristics.
	case 4: cout << "All tests selected" << endl; 
			cout << "Puzzle:" << endl;
			testBoard.printBoard();
			cout << "Uniform Cost Search test " << endl;
			uniform_cost_search(testBoard);
			cout << "Misplaced Tile test "  << endl;
			graph_search(testBoard, 1); 
			cout << "Manhattan Distance test "  << endl <<endl;
			graph_search(testBoard, 2); 

			//displays statistical information
			cout << "Uniform_Cost_Search_Avg_Expansions: " << Uniform_Cost_Search_Avg_Expansions << endl;
			cout << "Uniform_Cost_Search_Avg_PQ: " << Uniform_Cost_Search_Avg_PQ << endl << endl;

			cout << "Manhattan_Avg_Expansions: " << Manhattan_Avg_Expansions << endl;
			cout << "Manhattan_Avg_PQ: " << Manhattan_Avg_PQ << endl << endl;

			cout << "Misplaced_Tile_Avg_Expansions: " << Misplaced_Tile_Avg_Expansions << endl;
			cout << "Misplaced_Tile_Avg_PQ:" << Misplaced_Tile_Avg_PQ << endl << endl;
		break;
	default: cout << "Invalid Input. Please be sure to enter \"1\" , \"2.\", or \"3.\"" << endl;
		break;
	}
	
	return 0;
}




/*
 * Function: uniform_cost_search
 * Usage: uniform_cost_search(b);
 * --------------------------------
 * This function performs a uniform cost search on the board passed by the user.
 * Uniform Cost Search expands the node n with the lowest path cost g(n). This is
 * done by stroring the frontier as a priority queue orded by g.
 */
bool uniform_cost_search(Board b) {

	int nodes_expanded = 0;             // Track number of nodes expanded.
	int max_nodes_in_q = 0;             // Track the maximum number of nodes in the priority queue.
	int goal_depth = 0;	                // Track the depth of the goal state.

	Node* current = new Node();         // Stores current node of interest.
	current->setBoard(b);               // current contains initial state of the passed in Board b. By definition path cost = 0
	Board goal;                         // Board goal will be used to compare arbitrary boards to the desired goal state.
	goal.setToGoalState();              // set Board goal to the goal state.

	priority_queue<Node*, vector<Node*>, Comp> frontier;     //a priority queue ordered by Path-Cost, with node as the only element
	frontier.push(current);

	set<Board> explored;                // An empty set.
	set<Board> in_q;                    // Mimics nodes priority q. Prevents new unexplored children that are already in priority queue from being added redundantly

	while (true) {

		// Returns false if there are no nodes to expand. In other words there exists no solution.
		if (frontier.empty()) {
			cout << "frontier is empty" << endl;
			return false;
		}

		current = frontier.top();       // Set current to the lowest-cost node in frontier
		frontier.pop();                 // Pop frontier
		
	   
		// Remove popped board from in_q
		if (in_q.find(current->getBoard()) != in_q.end()) {
			in_q.erase(in_q.find(current->getBoard()));
		}


		// Perform goal test on current node
		if (current->getBoard() == goal) {
			cout << "Goal State reached!" << endl;
			goal_depth = current->getNodeDepth();
			
			cout << "To solve this problem the search algorithm expanded a total of " << nodes_expanded << " nodes." << endl;
			cout << "The maximum number of nodes in queue at any one time was " << max_nodes_in_q << "." << endl;
			cout << "The depth of the goal node was " << goal_depth << "." <<endl;


			// Used for statisical analysis. Unimportant to the search algorithm.
			if (Uniform_Cost_Search_Avg_Expansions != 0) {
				Uniform_Cost_Search_Avg_Expansions += nodes_expanded;
				Uniform_Cost_Search_Avg_Expansions = Uniform_Cost_Search_Avg_Expansions / 2;
			}
			else {
				Uniform_Cost_Search_Avg_Expansions = nodes_expanded;
			}
			if (Uniform_Cost_Search_Avg_PQ != 0) {
				Uniform_Cost_Search_Avg_PQ += max_nodes_in_q;
				Uniform_Cost_Search_Avg_PQ = Uniform_Cost_Search_Avg_PQ / 2;
			}
			else {
				Uniform_Cost_Search_Avg_PQ = max_nodes_in_q;
			}

			// Prompt User if they would like the solution.
			cout << "would you like the solution(y/n)?" << endl;
			
			string user_input;
			cin >> user_input;
			
			if (user_input == "y") {
				
				cout << "Goal Path: " << endl;
				
				vector<Node*> goal_path;
				
				// Stores goal path to vector goal_path.
				while(current != NULL)
				{
					goal_path.push_back(current);
					current = current->getParentNode();
				}
				
				// Prints contents of goal_path
				for (int i = goal_path.size() - 1; i >= 0; i--) {
					cout << "move applied: " << goal_path.at(i)->move_applied << endl;
					goal_path.at(i)->printNodeBoard();
				}
			}

			
			return true;                                        // Uniform Cost Search is complete.
		}
		
		
		
		//Should the goal test fail we continue with the following code.
		
		explored.insert(current->getBoard());                  // Add current node's board to explored set.

		// Conditional output that will differ the first expansion from all others.
		if (current->getNodeDepth() == 0) {
			cout << "Expanding state" << endl;
			current->printNodeBoard();
		}
		else {
			cout << "The best state to expand with g(n) = " << current->getNodeDepth() << " is..." << endl;
			current->printNodeBoard();
		}
		
		nodes_expanded++;                                     //Increment number of nodes expanded.

		// For each action, create a child node. If child node is not in explored or frontier add to priority queue.
		Node* child_node = new Node;
		bool already_explored = false;                            // Assume that generated children set has not been explored
		
		// Generate children
		for (int i = 1; i <= 4; i++) {
			already_explored = false;

			child_node = createChildNode(current, i, 0);            // Create child node from parent node.
			

			// If child_node has been previously explored. Set already explored to true.
			if (explored.find(child_node->getBoard()) != explored.end()) {
				already_explored = true;
			}

		
			// If child_node with the same board is in queue. Set already explored to true, so that it is not redundantly added.
			if (!already_explored) {
				if (in_q.find(child_node->getBoard()) != in_q.end() ) {
						already_explored = true;
				}
			}

			// If child set is not in explored_set or in_q, add child to priority queue and in_q
			if (!already_explored) {
				frontier.push(child_node);
				in_q.insert(child_node->getBoard());
				
				// Record maximum number of nodes in queue
				if (frontier.size() > max_nodes_in_q) { 
					max_nodes_in_q = frontier.size(); 
				}     
			}
		}
	}

	//Should we hit this, something went wrong.
	cout << "No Solution, potential error with algorithm." << endl;
		return false;
}

/*
* Function: graph_search
* Usage: graph_search(b, heuristic_decision);
* --------------------------------
* This function performs a Graph-Search on the board passed by the user.
* Graph-Search Search expands the node n with the lowest evaluation function value f(n). The evaluation
* function is determined by the nodes depth g(n) added to the heuristic function h(n). There are two hearistic function
* options. The first, Misplaced Tile, determined by the number of misplaced tiles in a given board. The second, Manhattan Distance
* determined by the aggregate distances of a each tiles positon to their goal position. The nodes are strored the frontier as a priority queue orded by f(n).
*/
bool graph_search(Board b, int heuristic_decision) {

	int nodes_expanded = 0;             // Track number of nodes expanded.
	int max_nodes_in_q = 0;             // Track the maximum number of nodes in the priority queue.
	int goal_depth = 0;	                // Track the depth of the goal state.

	Node* current = new Node();
	current->setBoard(b);               // Node contains initial state of Board b and path cost = 0

	Board goal;
	goal.setToGoalState();

	priority_queue<Node*, vector<Node*>, Comp> frontier;     // A priority queue ordered by the Evaluation Function, with node as the only element
	frontier.push(current);

	set<Board> explored;            //an empty set
	set<Board> in_q;                //mimics priority q, used to compare to child node

	while (true) {

		//returns false if there are no nodes to expand
		if (frontier.empty()) {
			cout << "frontier is empty" << endl;
			return false;
		}

		current = frontier.top();    // Chooses the lowerst-cost node in frontier
		frontier.pop();              // Pop frontier
									 // Remove popped board from in_q

	
		if (in_q.find(current->getBoard()) != in_q.end()) {
			in_q.erase(in_q.find(current->getBoard()));
		}

		// Perform goal test on current node
		if (current->getBoard() == goal) {
			cout << "Goal State reached!" << endl;
			goal_depth = current->getNodeDepth();

			cout << "To solve this problem the search algorithm expanded a total of " << nodes_expanded << " nodes." << endl;
			cout << "The maximum number of nodes in queue at any one time was " << max_nodes_in_q << "." << endl;
			cout << "The depth of the goal node was " << goal_depth << "." << endl;

			// Used for statisical analysis. Unimportant to the search algorithm.
			if (heuristic_decision == 1 && Misplaced_Tile_Avg_Expansions != 0) {
				Misplaced_Tile_Avg_Expansions += nodes_expanded;
				Misplaced_Tile_Avg_Expansions = Misplaced_Tile_Avg_Expansions / 2;
			}
			if (heuristic_decision == 1 && Misplaced_Tile_Avg_Expansions == 0) {
				Misplaced_Tile_Avg_Expansions = nodes_expanded;
			}
			if (heuristic_decision == 1 && Misplaced_Tile_Avg_PQ != 0) {
				Misplaced_Tile_Avg_PQ += max_nodes_in_q;
				Misplaced_Tile_Avg_PQ = Misplaced_Tile_Avg_PQ / 2;
			}
			if (heuristic_decision == 1 && Misplaced_Tile_Avg_PQ == 0) {
				Misplaced_Tile_Avg_PQ = max_nodes_in_q;
			}





			// Used for statisical analysis. Unimportant to the search algorithm.
			if (heuristic_decision == 2 && Manhattan_Avg_Expansions != 0) {
				Manhattan_Avg_Expansions += nodes_expanded;
				Manhattan_Avg_Expansions = Manhattan_Avg_Expansions / 2;
			}
			if (heuristic_decision == 2 && Manhattan_Avg_Expansions == 0) {
				Manhattan_Avg_Expansions = nodes_expanded;
			}
			if (heuristic_decision == 2 && Manhattan_Avg_PQ != 0) {
				Manhattan_Avg_PQ += max_nodes_in_q;
				Manhattan_Avg_PQ = Manhattan_Avg_PQ / 2;
			}
			if (heuristic_decision == 2 && Manhattan_Avg_PQ == 0) {
				Manhattan_Avg_PQ = max_nodes_in_q;
			}

			
			cout << "would you like the solution(y/n)?" << endl;
			string user_input;
			cin >> user_input;
			if (user_input == "y") {
				cout << "Goal Path" << endl;

				vector<Node*> goal_path;
				while (current != NULL)
				{
					goal_path.push_back(current);
					current = current->getParentNode();
				}
				for (int i = goal_path.size() - 1; i >= 0; i--) {
					cout << "move applied: " << goal_path.at(i)->move_applied << endl;
					goal_path.at(i)->printNodeBoard();
				}
			}
			
			return true;
		}
		explored.insert(current->getBoard());                     // Add board to explored set

	
		// Conditional output that will differ the first expansion from all others.
		if (current->getNodeDepth() == 0)
		{
			cout << "Expanding state" << endl;
			current->printNodeBoard();
		}
		else {
			cout << "The best state to expand with g(n) = " << current->getNodeDepth() << ", h(n) = " << current->h_of_n << " and f(n) = " <<current->getFofN() <<" is..." << endl;
			current->printNodeBoard();
		}
	

		nodes_expanded++;                                         // Increment number of nodes expanded.

		// For each action, create a child node. If child node is not in explored or frontier add to priority queue
		Node* child_node = new Node;
		bool already_explored = false;                            // Assume that generated set has not been explored

																  // Generate children
		for (int i = 1; i <= 4; i++) {
			already_explored = false;

			child_node = createChildNode(current, i, heuristic_decision);            // Create child node from parent node


			//check if child_node has been previously explored
			//check explored set
			if (explored.find(child_node->getBoard()) != explored.end()) {
				already_explored = true;
			}
					
				if (!already_explored) {
					

					if (in_q.find(child_node->getBoard()) != in_q.end()) {
						already_explored = true;
						
					}
				

				}

				// After checking explored_set and in_q add child to priority queue and in_q
				if (!already_explored) {
					frontier.push(child_node);
					in_q.insert(child_node->getBoard());
					if (frontier.size() > max_nodes_in_q) max_nodes_in_q = frontier.size(); //sets max nodes of queue
				}
			}
		}

		cout << "No Solution, something may be wrong with the algorithm." << endl;
		return false;
	}



//createChildNode takes a pointer to the parent Node, creates a copy of the parent and applies the appropriate move to it. 
Node* createChildNode(Node *parent, int action) {
	
	Node* child = new Node;
	*child = *parent;                                 //create a copy of the parent node called child.   
	Board child_board = parent->getBoard();			  //create a copy of the parent nodes board
	child->move_applied = child_board.move(action);   //apply move action to child board
	child->setBoard(child_board);				      // save child board to child node
	child->setParentNode(parent);			          // child nodes points to parent node
	
	return child;
}

//createChildNode takes a pointer to the parent Node, creates a copy of the parent and applies the appropriate move to it. 
Node* createChildNode(Node *parent, int action, int h) {

	Node* child = new Node;
	*child = *parent;                                 //create a copy of the parent node called child.   
	Board child_board = parent->getBoard();			  //create a copy of the parent nodes board
	child->move_applied = child_board.move(action);   //apply move action to child board
	child->setBoard(child_board);				      // save child board to child node
	
	if (h == 0) child->h_of_n = 0;
	if (h == 1) child->h_of_n = child->getBoard().getMisplacedTileDistance();
	if (h == 2) child->h_of_n = child->getBoard().getManhattanDistance();
	child->setParentNode(parent);			          // child nodes points to parent node
	return child;
}


// Used in testing to generate random boards.
Board random_board() {
	
	Board b;
	int n[9];
	int index = 0;
	int random = 0;
	int inv_count = 0;
	bool already_has = false;
	bool is_solvable = false; //not solvable until proven to be solvable

	srand(time(NULL));
	

	
	//generate an array of unique random numbers to be used in random board.
	while (!is_solvable)
	{
		fill_n(n, 9, -1); //initialize entire array to -1. Uses algorithm library
		for (int i = 0; i < 9; i++) {

			random = rand() % 9;        /* generate a number from 0 - 8 */

			for (int j = 0; j < 9; j++)
			{
				if (n[j] == random)
				{
					i--;
					already_has = true;
				}
			}

			if (!already_has) {
				n[i] = random;
			}
			else
			{
				already_has = false;
			}
		}
	
		//Inversion Test
		for (int i = 0; i < 9 - 1; i++)
		{
			for (int j = i + 1; j < 9; j++)
			{
				// Value 0 is used for empty space
				if (n[j] && n[i] && n[i] > n[j])
				{
					inv_count++;
				}
			}
		}

		if (inv_count % 2 == 0) {
			is_solvable = true;
		}
		else
		{
			inv_count = 0;
		}

	} 
	
	
	index = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			b.board_configuration[i][j] = n[index];
			if (n[index] == 0) {
				b.blank_row_pos = i;
				b.blank_col_pos = j;
			}
			index++;
		}
	}


	return b;
}
