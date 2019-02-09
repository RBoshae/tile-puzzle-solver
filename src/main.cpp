/*
 * File: main.cpp
 * ----------------
 * Created by Rick Boshae on 1/29/17.
 * Updated: 08/07/2018
 *
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include "../include/Board.h"
#include "../include/A_Star.h"
// #include "../include/A_Star.h"
// #include "../include/Node.h" // TODO Refactor

using namespace std;

//Used to make object comparison in priority queue
// struct Comp {
// 	bool operator () (Node lhs, Node rhs) {
// 		if (lhs.getFofN() == rhs.getFofN()) {
// 			return lhs.getNodeDepth() > rhs.getNodeDepth();
// 		}
// 		return lhs.getFofN() > rhs.getFofN();
// 	}
//
// 	bool operator () (Node* lhs, Node* rhs) {
// 		if (lhs->getFofN() == rhs->getFofN()) {
// 			return lhs->getNodeDepth() > rhs->getNodeDepth();
// 		} else
// 		return lhs->getFofN() > rhs->getFofN();
// 	}
// };

enum class HEURISTIC {MISPLACED_TILE, MANHATTAN_DISTANCE, UNIFORM_COST_SEARCH, ALL};

// Forward Function Declarations.
void startMenu();
void chooseBoard(Board *_board);						// calls interface for user to interact with program.
void setBoardFromUserInput(Board *_board);				// prompts user for input to set board. returns set board.
HEURISTIC chooseHeuristic();

// bool graph_search(Board b, int heuristic_decision);
// bool uniform_cost_search(Board b);
// Node* createChildNode(Node *parent, int action, int h);
// Board random_board();
//
// //Global Vaiables used to collect data on heuristics
// double Uniform_Cost_Search_Avg_Expansions;
// double Uniform_Cost_Search_Avg_PQ;
//
// double Manhattan_Avg_Expansions;
// double Manhattan_Avg_PQ;
//
// double Misplaced_Tile_Avg_Expansions;
// double Misplaced_Tile_Avg_PQ;

int main() {
	Board userBoard;									// The board the program will solve.
	A_Star astar;
	string userInput;

	startMenu();											// Provide program information to user.
	chooseBoard(&userBoard);					// Set up board.
	HEURISTIC heuristicChoice = chooseHeuristic();	// Pick hearistic to use.

	switch (heuristicChoice) {
		case HEURISTIC::MISPLACED_TILE:
			astar.misplacedTile(userBoard);
		break;

		case HEURISTIC::MANHATTAN_DISTANCE:
			astar.manhattanDistance(userBoard);
		break;

		case HEURISTIC::UNIFORM_COST_SEARCH:
			astar.uniformCostSearch(userBoard);
		break;

		case HEURISTIC::ALL:
			astar.misplacedTile(userBoard);
			astar.manhattanDistance(userBoard);
			astar.uniformCostSearch(userBoard);
		break;

		default:
			cout << "Something went wrong." << endl;
		break;
	}

	cout << "Goal State Reached. Would you like to see the solution?(y/n): ";
	cin >> userInput;
	if (userInput == "y")
	{
			astar.printSolution();
	}

	cout << "End of Program." << endl;
	return 0;
}

/*
 * Function: main_menu
 * Usage: 	 main_menu();
 * --------------------------------
 * main_menu is the interface provided to the user to interact with the program.
 * The user is greeted and given three options: Default Puzzle, Custom Puzzle, or Quit.
 * The Default Puzzle option uses a computer-generated board. The Custom Puzzle option
 * allows the user to input their own board. Quit exits the program.
 *
 * The following menu prompts the user to choose a heuristic to use for A* search.
 * At present there are three options: Uniform Cost Search (the slowest), Misplaced Tile,
 * or Manhattan Distance. There is also a secret fourth option to test all heuristics.
 *
 * After the user has chosen their desired heuristic the program proceeds to solve the
 * the 8-tile puzzle. Each best state board is outputted to the terminal before it is expanded.
 * Stats are also shown to indicate the g(n), h(n), and f(n) values ate each state.
 *
 * When a goal state is reached the program outputs the total number of nodes expanded. The
 * maximum number of nodes in queue at any one time. The depth of the goal node. Finally the
 * user if asked if they would like to view the solution trace.
 */

void startMenu() {
 // Prompt #1
	cout <<	" _____   _        _     _                                                       " 				<< endl;
	cout << "|  __ \\ (_)      | |   ( )                                                     " 				<< endl;
	cout << "| |__) | _   ___ | | __|/ ___                                                   " 				<< endl;
	cout << "|  _  / | | / __|| |/ /  / __|                                                  " 				<< endl;
	cout << "| | \\ \\ | || (__ |   <   \\__ \\                                              " 				<< endl;
	cout << "|_|  \\ \\|_| \\___||_|\\_\\  |___/                                             " 				<< endl;
	cout <<	"  ___      _____                   _          _____         _                   " 				<< endl;
	cout <<	" / _ \\    |  __ \\                 | |        / ____|       | |                " 				<< endl;
	cout << "| (_) |__ | |__) |_   _  ____ ____| |  ___  | (___    ___  | |__   __ ___  _ __ " 				<< endl;
	cout <<	" > _ <|__||  ___/| | | ||_  /|_  /| | / _ \\  \\___ \\  / _ \\ | |\\ \\ / // _ \\| '__|" << endl;
	cout << "| (_) |   | |    | |_| | / /  / / | ||  __/  ____) || (_) || | \\ V / | __/| |   " 			<< endl;
	cout <<	" \\___/    |_|     \\__,_|/___|/___||_| \\___| |_____/  \\___/ |_|  \\_/  \\___||_|   " 	<< endl;
	cout << "================================================================================" 				<< endl;
	cout << endl;
	cout << "Welcome to Rick's 8-puzzle solver. This program features the famous A* search   "     		<< endl;
	cout << "to solve any 3x3 sliding tile puzzle (assuming a solution exists). To start,    "				<< endl;
	cout << "choose between entering a custom puzzle, a default puzzle, or randomly          "				<< endl;
	cout << "generating a puzzle. Next, choose which heuristic to use in the A* algorithm.   "        << endl;
	cout << "Once the puzzle is solved you may choose to view the solution trace or search   "        << endl;
	cout << "analytics."                                                                      << endl << endl;
	cout << "Press Enter to continue.";
	cin.ignore();
	cout << endl;
	cout << "--------------------------------------------------------------------------------"<< endl << endl;
} // End of startMenu.

void chooseBoard(Board* _board){

	const int NUMBER_OF_TILES = 9;
	int userInput;		 	        					// stores menu option inputted by user.
	char userInput_c;							// stores alpha input from user.
	int tempBoardConfig[NUMBER_OF_TILES];	// Stores user defined board.

	cout << endl;
	cout << "What type of puzzle would you like to use?"       	                                   	  << endl;
	cout << endl;
	cout << "Choose from the following:"								       	                              << endl << endl;
	cout << "  1 \tEnter a custom puzzle."      			                                               	<< endl;
	cout << "  2 \tGenerate a random puzzle."                                                       	<< endl;
	cout << "  3 \tUse the default puzzle"                                                    << endl << endl;
	cout << "What'll it be: ";
	cin >> userInput;


 	// Validate user input. If userInput is invalid try again, otherwise continue.
 	while (cin.fail() || userInput > 3 || userInput < -1) {		 // cin.fail() checks to see if the value in the
 																														 // cin stream is the correct type, if not returns
 																														 // true, otherwise false. Additional or statament
 																														 // validates the user seleceted an available
 																														 // option.

 			cin.clear();                                           // cin.clear() corrects the stream
 			cin.ignore();                                          // cin.ignore() skips the left over stream data
 			cout << "Please be sure to enter 1, 2, or 3 only." << endl;
 			cout << "So, what'll it be: ";
 			cin >> userInput;
 	} // end while loop

 	cout << "--------------------------------------------------------------------------------"	<< endl << endl;


 	// Confirm userInput. If userInput selected Default Puzzle option print the puzzle to the display.
 	// If user selected custom puzzle call .setBoard() to input custom puzzle. If selected quit, exit program.
 	switch (userInput)
 	{
 		case 1: {
 			cout << "Great! You chose to enter your own puzzle." << endl << endl;

 			cout << "To set your board start by entering one digit at a time. Once you've      " << endl;
 			cout << "entered the digit press enter. Continue entering digits until the board is" << endl;
 			cout << "is filled. Be sure you enter a digit between 0-9 and do not enter the same" << endl;
 			cout << "digit twice. Use 0 to represent the blank tile."									   << endl << endl;
 			cout << "Set your board: "																									 				 << endl;

			do {
				setBoardFromUserInput(_board);

				_board->set(tempBoardConfig);

				cout << "Your board has been set. Here is what it looks like: " << endl << endl;
				_board->print();
				cout << endl;
				cout << "Is this board okay? (Enter n to reset. Enter any other key to continue.): ";
				cin >> userInput_c;
				if (userInput_c == 'n' || userInput_c == 'N') {
					cout << "Okay, lets try again." << endl <<endl;
					cout << "set your board: " << endl << endl;
				}
			} while (userInput_c == 'n' || userInput_c == 'N');

 			break;
 		}
 		case 2: {
 			cout << "You got it. Generating a random puzzle now." << endl << endl;
			_board->randomize();                                // declare new board object
 			cout << "Here it is:" << endl;
 			_board->print();
 			cout << endl;
 			break;
 		}
 		case 3: {
 			cout << "Default selected." << endl << endl;
 			cout << "Here's what your default board looks like:" 		<< endl;
 			_board->print();
 			break;
 		}
 		default: {
 			cout << "Error, Invalid input. Quitting program." << endl;
 			exit(1);
 			break;
 		}
 	}
} // End of choose board


// Helper Functions
void setBoardFromUserInput(Board *_board) {
	int tempBoardConfig[NUMBER_OF_TILES];
	for (int i = 0; i < NUMBER_OF_TILES; i++) {

		cout << "Enter value: ";
		cin >> tempBoardConfig[i];
		cout << endl;

		cout << "Your board:" << endl;
		// Reprint board.
		for (int j = 0; j < NUMBER_OF_TILES; j++) {
			if (j <= i){
				if (tempBoardConfig[j] == 0) {
					cout << "b ";
				} else {
				cout << tempBoardConfig[j] << " ";
				}
			} else {
					cout << "X ";
			}
			if ((j+1)%3 == 0) {
				cout << endl;
			}
		}
		cout << endl;

		// Ensure user did not input the same digit twice
		for(int j = 0; j < i; j++) {
			if (tempBoardConfig[j] == tempBoardConfig[i]) {
				cout << "You already picked number " << tempBoardConfig[i] << ". Please ";
				cout << "pick a different number." << endl << endl;
				//
				// // Reprint board.
				// for (int j = 0; j < i; j++) {
				// 	cout << tempBoardConfig[j] << " ";
				// 	if (i%3 == 0 && j !=0) {
				// 		cout << endl;
				// 	}
				i--; // Let user reenter value.
				break;
			} else if (tempBoardConfig[i] < 0 || tempBoardConfig[i]>(NUMBER_OF_TILES-1)) {
				cout << "Be sure to pick a number between 0-8" << endl;
				//
				// // Reprint board.
				// for (int j = 0; j < i; j++) {
				// 	cout << tempBoardConfig[j] << " ";
				// 	if (i%3 == 0 && j !=0) {
				// 		cout << endl;
				// 	}
				i--;
				break;
			}
		}
	}
	if(!_board->set(tempBoardConfig)){ // Assign values to passed in board.
		cerr << "Invalid board" << endl;
	}
	return;
}

HEURISTIC chooseHeuristic(){
	HEURISTIC heuristic_choice;
	int userInput;

	cout << "================================================================================" 			<< endl;
	cout << "Pick an algorithm to solve your puzzle." 		 << endl;
	cout << endl;
	cout << "  1 - Uniform Cost Search. (Warning: Likely to be VERY slow)" << endl;
	cout << "  2 - A* with Misplaced Tile heuristic."     		<< endl;
	cout << "  3 - A* with Manhattan Distance heuristic." 		<< endl;
	cout << "--------------------------------------------------------------------------------" 			<< endl;
	cout << "  choice: ";

	cin >> userInput;														// Store user choice in heuristic_choice variable.

	while (cin.fail() || userInput < 0 || userInput > 3){					// cin.fail() checks to see if the value in the
																			// cin stream is the correct type, if not returns
																			// true, otherwise false.
		cin.clear();              											// cin.clear() corrects the stream
		cin.ignore();             											// cin.ignore() skips the left over stream data
		cout << "  Please pick either 1, 2, or 3." << endl;
		cout << "  "; 														// whitespace buffer.
		cin >> userInput;
	}

	// Confirm userInput. If userInput selected Default Puzzle option print the puzzle to the display.
	// If user selected custom puzzle call .setBoard() to input custom puzzle. If selected quit, exit program.
	switch (userInput) {
		case 1: {
			cout << "Uniform Cost Search selected" << endl;
			heuristic_choice = HEURISTIC::UNIFORM_COST_SEARCH;
			break;
		}
		case 2: {
			cout << "  A* with Misplaced Tile heuristic selected." << endl;
			heuristic_choice = HEURISTIC::MISPLACED_TILE;
			break;
		}
		case 3: {
			cout << "  A* with Manhattan Distance heuristic selected." << endl;
			heuristic_choice = HEURISTIC::MANHATTAN_DISTANCE;
			break;
		}
		case 4: {	// Secret Option Used to compare heuristics.
			cout << "  All tests selected" 	<< endl;
			heuristic_choice = HEURISTIC::ALL;
			break;
		}
		default: {
			cout << "  Invalid Input. Please be sure to enter \"1\" , \"2.\", or \"3.\"" << endl;
			break;
		}
	}

	return heuristic_choice;
}
// void main_menu() {


//  int heuristic_choice;								// Alternative to using userInput. Allows for easier to read code.
// 	//Prompt #2

//

// }
//
//
//
// /*
//  * Function: uniform_cost_search
//  * Usage: uniform_cost_search(b);
//  * --------------------------------
//  * This function performs a uniform cost search on the board passed by the user.
//  * Uniform Cost Search expands the node n with the lowest path cost g(n). This is
//  * done by stroring the frontier as a priority queue orded by g.
//  */
// bool uniform_cost_search(Board b) {
//
// 	int nodes_expanded = 0;             // Track number of nodes expanded.
// 	int max_nodes_in_q = 0;             // Track the maximum number of nodes in the priority queue.
// 	int goal_depth = 0;	                // Track the depth of the goal state.
//
// 	Node* current = new Node();         // Stores current node of interest.
// 	current->setBoard(b);               // current contains initial state of the passed in Board b. By definition path cost = 0
// 	Board goal;                         // Board goal will be used to compare arbitrary boards to the desired goal state.
// 	goal.setToGoalState();              // set Board goal to the goal state.
//
// 	priority_queue<Node*, vector<Node*>, Comp> frontier;     //a priority queue ordered by Path-Cost, with node as the only element
// 	frontier.push(current);
//
// 	set<Board> explored;                // An empty set.
// 	set<Board> in_q;                    // Mimics nodes priority q. Prevents new unexplored children that are already in priority queue from being added redundantly
//
// 	while (true) {
//
// 		// Returns false if there are no nodes to expand. In other words there exists no solution.
// 		if (frontier.empty()) {
// 			cout << "frontier is empty" << endl;
// 			return false;
// 		}
//
// 		current = frontier.top();       // Set current to the lowest-cost node in frontier
// 		frontier.pop();                 // Pop frontier
//
//
// 		// Remove popped board from in_q
// 		if (in_q.find(current->getBoard()) != in_q.end()) {
// 			in_q.erase(in_q.find(current->getBoard()));
// 		}
//
//
// 		// Perform goal test on current node
// 		if (current->getBoard() == goal) {
// 			cout << "Goal State reached!" << endl;
// 			goal_depth = current->getNodeDepth();
//
// 			cout << "To solve this problem the search algorithm expanded a total of " << nodes_expanded << " nodes." << endl;
// 			cout << "The maximum number of nodes in queue at any one time was " << max_nodes_in_q << "." << endl;
// 			cout << "The depth of the goal node was " << goal_depth << "." <<endl;
//
//
// 			// Used for statisical analysis. Unimportant to the search algorithm.
// 			if (Uniform_Cost_Search_Avg_Expansions != 0) {
// 				Uniform_Cost_Search_Avg_Expansions += nodes_expanded;
// 				Uniform_Cost_Search_Avg_Expansions = Uniform_Cost_Search_Avg_Expansions / 2;
// 			}
// 			else {
// 				Uniform_Cost_Search_Avg_Expansions = nodes_expanded;
// 			}
// 			if (Uniform_Cost_Search_Avg_PQ != 0) {
// 				Uniform_Cost_Search_Avg_PQ += max_nodes_in_q;
// 				Uniform_Cost_Search_Avg_PQ = Uniform_Cost_Search_Avg_PQ / 2;
// 			}
// 			else {
// 				Uniform_Cost_Search_Avg_PQ = max_nodes_in_q;
// 			}
//
// 			// Prompt User if they would like the solution.
// 			cout << "would you like the solution(y/n)?" << endl;
//
// 			string user_input;
// 			cin >> user_input;
//
// 			if (user_input == "y") {
//
// 				cout << "Goal Path: " << endl;
//
// 				vector<Node*> goal_path;
//
// 				// Stores goal path to vector goal_path.
// 				while(current != NULL)
// 				{
// 					goal_path.push_back(current);
// 					current = current->getParentNode();
// 				}
//
// 				// Prints contents of goal_path
// 				for (int i = goal_path.size() - 1; i >= 0; i--) {
// 					cout << "move applied: " << goal_path.at(i)->move_applied << endl;
// 					goal_path.at(i)->printNodeBoard();
// 				}
// 			}
//
//
// 			return true;                                        // Uniform Cost Search is complete.
// 		}
//
//
//
// 		//Should the goal test fail we continue with the following code.
//
// 		explored.insert(current->getBoard());                  // Add current node's board to explored set.
//
// 		// Conditional output that will differ the first expansion from all others.
// 		if (current->getNodeDepth() == 0) {
// 			cout << "Expanding state" << endl;
// 			current->printNodeBoard();
// 		}
// 		else {
// 			cout << "The best state to expand with g(n) = " << current->getNodeDepth() << " is..." << endl;
// 			current->printNodeBoard();
// 		}
//
// 		nodes_expanded++;                                     //Increment number of nodes expanded.
//
// 		// For each action, create a child node. If child node is not in explored or frontier add to priority queue.
// 		Node* child_node = new Node;
// 		bool already_explored = false;                            // Assume that generated children set has not been explored
//
// 		// Generate children
// 		for (int i = 1; i <= 4; i++) {
// 			already_explored = false;
//
// 			child_node = createChildNode(current, i, 0);            // Create child node from parent node.
//
//
// 			// If child_node has been previously explored. Set already explored to true.
// 			if (explored.find(child_node->getBoard()) != explored.end()) {
// 				already_explored = true;
// 			}
//
//
// 			// If child_node with the same board is in queue. Set already explored to true, so that it is not redundantly added.
// 			if (!already_explored) {
// 				if (in_q.find(child_node->getBoard()) != in_q.end() ) {
// 						already_explored = true;
// 				}
// 			}
//
// 			// If child set is not in explored_set or in_q, add child to priority queue and in_q
// 			if (!already_explored) {
// 				frontier.push(child_node);
// 				in_q.insert(child_node->getBoard());
//
// 				// Record maximum number of nodes in queue
// 				if (frontier.size() > max_nodes_in_q) {
// 					max_nodes_in_q = frontier.size();
// 				}
// 			}
// 		}
// 	}
//
// 	//Should we hit this, something went wrong.
// 	cout << "No Solution, potential error with algorithm." << endl;
// 		return false;
// }
//
// /*
// * Function: graph_search
// * Usage: graph_search(b, heuristic_decision);
// * --------------------------------
// * This function performs a Graph-Search on the board passed by the user.
// * Graph-Search Search expands the node n with the lowest evaluation function value f(n). The evaluation
// * function is determined by the nodes depth g(n) added to the heuristic function h(n). There are two hearistic function
// * options. The first, Misplaced Tile, determined by the number of misplaced tiles in a given board. The second, Manhattan Distance
// * determined by the aggregate distances of a each tiles positon to their goal position. The nodes are strored the frontier as a priority queue orded by f(n).
// */
// bool graph_search(Board b, int heuristic_decision) {
//
// 	int nodes_expanded = 0;             // Track number of nodes expanded.
// 	int max_nodes_in_q = 0;             // Track the maximum number of nodes in the priority queue.
// 	int goal_depth = 0;	                // Track the depth of the goal state.
//
// 	Node* current = new Node();
// 	current->setBoard(b);               // Node contains initial state of Board b and path cost = 0
//
// 	Board goal;
// 	goal.setToGoalState();
//
// 	priority_queue<Node*, vector<Node*>, Comp> frontier;     // A priority queue ordered by the Evaluation Function, with node as the only element
// 	frontier.push(current);
//
// 	set<Board> explored;            //an empty set
// 	set<Board> in_q;                //mimics priority q, used to compare to child node
//
// 	while (true) {
//
// 		//returns false if there are no nodes to expand
// 		if (frontier.empty()) {
// 			cout << "frontier is empty" << endl;
// 			return false;
// 		}
//
// 		current = frontier.top();    // Chooses the lowerst-cost node in frontier
// 		frontier.pop();              // Pop frontier
// 									 // Remove popped board from in_q
//
//
// 		if (in_q.find(current->getBoard()) != in_q.end()) {
// 			in_q.erase(in_q.find(current->getBoard()));
// 		}
//
// 		// Perform goal test on current node
// 		if (current->getBoard() == goal) {
// 			cout << "Goal State reached!" << endl;
// 			goal_depth = current->getNodeDepth();
//
// 			cout << "To solve this problem the search algorithm expanded a total of " << nodes_expanded << " nodes." << endl;
// 			cout << "The maximum number of nodes in queue at any one time was " << max_nodes_in_q << "." << endl;
// 			cout << "The depth of the goal node was " << goal_depth << "." << endl;
//
// 			// Used for statisical analysis. Unimportant to the search algorithm.
// 			if (heuristic_decision == 1 && Misplaced_Tile_Avg_Expansions != 0) {
// 				Misplaced_Tile_Avg_Expansions += nodes_expanded;
// 				Misplaced_Tile_Avg_Expansions = Misplaced_Tile_Avg_Expansions / 2;
// 			}
// 			if (heuristic_decision == 1 && Misplaced_Tile_Avg_Expansions == 0) {
// 				Misplaced_Tile_Avg_Expansions = nodes_expanded;
// 			}
// 			if (heuristic_decision == 1 && Misplaced_Tile_Avg_PQ != 0) {
// 				Misplaced_Tile_Avg_PQ += max_nodes_in_q;
// 				Misplaced_Tile_Avg_PQ = Misplaced_Tile_Avg_PQ / 2;
// 			}
// 			if (heuristic_decision == 1 && Misplaced_Tile_Avg_PQ == 0) {
// 				Misplaced_Tile_Avg_PQ = max_nodes_in_q;
// 			}
//
//
//
//
//
// 			// Used for statisical analysis. Unimportant to the search algorithm.
// 			if (heuristic_decision == 2 && Manhattan_Avg_Expansions != 0) {
// 				Manhattan_Avg_Expansions += nodes_expanded;
// 				Manhattan_Avg_Expansions = Manhattan_Avg_Expansions / 2;
// 			}
// 			if (heuristic_decision == 2 && Manhattan_Avg_Expansions == 0) {
// 				Manhattan_Avg_Expansions = nodes_expanded;
// 			}
// 			if (heuristic_decision == 2 && Manhattan_Avg_PQ != 0) {
// 				Manhattan_Avg_PQ += max_nodes_in_q;
// 				Manhattan_Avg_PQ = Manhattan_Avg_PQ / 2;
// 			}
// 			if (heuristic_decision == 2 && Manhattan_Avg_PQ == 0) {
// 				Manhattan_Avg_PQ = max_nodes_in_q;
// 			}
//
//
// 			cout << "would you like the solution(y/n)?" << endl;
// 			string user_input;
// 			cin >> user_input;
// 			if (user_input == "y") {
// 				cout << "Goal Path" << endl;
//
// 				vector<Node*> goal_path;
// 				while (current != NULL)
// 				{
// 					goal_path.push_back(current);
// 					current = current->getParentNode();
// 				}
// 				for (int i = goal_path.size() - 1; i >= 0; i--) {
// 					cout << "move applied: " << goal_path.at(i)->move_applied << endl;
// 					goal_path.at(i)->printNodeBoard();
// 				}
// 			}
//
// 			return true;
// 		}
// 		explored.insert(current->getBoard());                     // Add board to explored set
//
//
// 		// Conditional output that will differ the first expansion from all others.
// 		if (current->getNodeDepth() == 0)
// 		{
// 			cout << "Expanding state" << endl;
// 			current->printNodeBoard();
// 		}
// 		else {
// 			cout << "The best state to expand with g(n) = " << current->getNodeDepth() << ", h(n) = " << current->h_of_n << " and f(n) = " <<current->getFofN() <<" is..." << endl;
// 			current->printNodeBoard();
// 		}
//
//
// 		nodes_expanded++;                                         // Increment number of nodes expanded.
//
// 		// For each action, create a child node. If child node is not in explored or frontier add to priority queue
// 		Node* child_node = new Node;
// 		bool already_explored = false;                            // Assume that generated set has not been explored
//
// 																  // Generate children
// 		for (int i = 1; i <= 4; i++) {
// 			already_explored = false;
//
// 			child_node = createChildNode(current, i, heuristic_decision);            // Create child node from parent node
//
//
// 			//check if child_node has been previously explored
// 			//check explored set
// 			if (explored.find(child_node->getBoard()) != explored.end()) {
// 				already_explored = true;
// 			}
//
// 				if (!already_explored) {
//
//
// 					if (in_q.find(child_node->getBoard()) != in_q.end()) {
// 						already_explored = true;
//
// 					}
//
//
// 				}
//
// 				// After checking explored_set and in_q add child to priority queue and in_q
// 				if (!already_explored) {
// 					frontier.push(child_node);
// 					in_q.insert(child_node->getBoard());
// 					if (frontier.size() > max_nodes_in_q) max_nodes_in_q = frontier.size(); //sets max nodes of queue
// 				}
// 			}
// 		}
//
// 		cout << "No Solution, something may be wrong with the algorithm." << endl;
// 		return false;
// 	}
//
//
//
// //createChildNode takes a pointer to the parent Node, creates a copy of the parent and applies the appropriate move to it.
// Node* createChildNode(Node *parent, int action) {
//
// 	Node* child = new Node;
// 	*child = *parent;                                 //create a copy of the parent node called child.
// 	Board child_board = parent->getBoard();			  //create a copy of the parent nodes board
// 	child->move_applied = child_board.move(action);   //apply move action to child board
// 	child->setBoard(child_board);				      // save child board to child node
// 	child->setParentNode(parent);			          // child nodes points to parent node
//
// 	return child;
// }
//
// //createChildNode takes a pointer to the parent Node, creates a copy of the parent and applies the appropriate move to it.
// Node* createChildNode(Node *parent, int action, int h) {
//
// 	Node* child = new Node;
// 	*child = *parent;                                 //create a copy of the parent node called child.
// 	Board child_board = parent->getBoard();			  //create a copy of the parent nodes board
// 	child->move_applied = child_board.move(action);   //apply move action to child board
// 	child->setBoard(child_board);				      // save child board to child node
//
// 	if (h == 0) child->h_of_n = 0;
// 	if (h == 1) child->h_of_n = child->getBoard().getMisplacedTileDistance();
// 	if (h == 2) child->h_of_n = child->getBoard().getManhattanDistance();
// 	child->setParentNode(parent);			          // child nodes points to parent node
// 	return child;
// }
//
//
// // Used in testing to generate random boards.
// Board random_board() {
//
// 	Board b;
// 	int n[9];
// 	int index = 0;
// 	int random = 0;
// 	int inv_count = 0;
// 	bool already_has = false;
// 	bool is_solvable = false; //not solvable until proven to be solvable
//
// 	srand(time(NULL));
//
//
//
// 	//generate an array of unique random numbers to be used in random board.
// 	while (!is_solvable)
// 	{
// 		fill_n(n, 9, -1); //initialize entire array to -1. Uses algorithm library
// 		for (int i = 0; i < 9; i++) {
//
// 			random = rand() % 9;        /* generate a number from 0 - 8 */
//
// 			for (int j = 0; j < 9; j++)
// 			{
// 				if (n[j] == random)
// 				{
// 					i--;
// 					already_has = true;
// 				}
// 			}
//
// 			if (!already_has) {
// 				n[i] = random;
// 			}
// 			else
// 			{
// 				already_has = false;
// 			}
// 		}
//
// 		//Inversion Test
// 		for (int i = 0; i < 9 - 1; i++)
// 		{
// 			for (int j = i + 1; j < 9; j++)
// 			{
// 				// Value 0 is used for empty space
// 				if (n[j] && n[i] && n[i] > n[j])
// 				{
// 					inv_count++;
// 				}
// 			}
// 		}
//
// 		if (inv_count % 2 == 0) {
// 			is_solvable = true;
// 		}
// 		else
// 		{
// 			inv_count = 0;
// 		}
//
// 	}
//
//
// 	index = 0;
// 	for (int i = 0; i < 3; i++) {
// 		for (int j = 0; j < 3; j++)
// 		{
// 			b.board_configuration[i][j] = n[index];
// 			if (n[index] == 0) {
// 				b.blank_row_pos = i;
// 				b.blank_col_pos = j;
// 			}
// 			index++;
// 		}
// 	}
//
//
// 	return b;
// }
