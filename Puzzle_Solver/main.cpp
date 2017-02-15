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

//#include "Problem.h" - removing because it feels unecessary

using namespace std;

//Used for priorty queue 
struct Comp {
	bool operator () (Node lhs, Node rhs) {
		return lhs.getFofN() > rhs.getFofN();
	}
	bool operator () (Node* lhs, Node* rhs) {
		return lhs->getFofN() > rhs->getFofN();
	}
};

bool graph_search(Board b, int heuristic_decision);
bool uniform_cost_search(Board b);
//Node* createChildNode(Node* parent, int action);
Node* createChildNode(Node *parent, int action, int h);
//Node createRootNode(Board b);

int main() {


	int menu_selection = 0;
	bool valid = false; //used to verify user input during prompts is valid
	Board testBoard;
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

		case 1: cout << "default puzzle selected." << endl;
			break;
		case 2: cout << "custom puzzle selected." << endl;
			//no need to set default problem since the Board default constructor already contains a default board
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
	case 2: cout << "A* with the Misplaced Tile heuristic selected" << endl; graph_search(testBoard, 2);
		break;
	case 3: cout << "A* with the Manhattan distance heuristic." << endl; graph_search(testBoard, 1);
		break;
	default: cout << "Invalid Input. Please be sure to enter \"1\" , \"2.\", or \"2.\"" << endl;
		break;
	}




	
	system("PAUSE");
	return 0;
}


bool uniform_cost_search(Board b) {

	int nodes_expanded = 0;             //Keeps track of nodes expanded.
	int max_nodes_in_q = 0;
	int goal_depth = 0;

	Node* current = new Node();
	current->setBoard(b);               //Node contains initial state of Board b and path cost = 0
	Board goal;                   
	goal.setToGoalState();         

	priority_queue<Node*, vector<Node*>, Comp> frontier;     //a priority quete ordered by Path-Cost, with node as the only element
	frontier.push(current);

	set<Board> explored;            //an empty set
	set<Board> in_q;                //mimics priority q, used to compare to child node

	while (true) {

		//returns false if there are no nodes to expand
		if (frontier.empty()) {
			cout << "frontier is empty" << endl;
			return false;
		}

		current = frontier.top();    //chooses the lowerst-cost node in frontier
		frontier.pop();              //pop frontier
		//remove popped board from in_q
	
		in_q.erase(in_q.find(current->getBoard));
		//	for (int i = 0; i < in_q.size(); i++) {
	//		if (current->getBoard() == in_q.at(i)) {
	//			in_q.erase(in_q.begin() + i);
	//			break; //if we found a match there is no need to continue the loop
	//		}
	//	}

		//perform goal test on current node
		if (current->getBoard() == goal) {
			cout << "Goal State reached!" << endl;
			goal_depth = current->getNodeDepth();
			
			cout << "To solve this problem the search algorithm expanded a total of " << nodes_expanded << " nodes." << endl;
			cout << "The maximum number of nodes in queue at any one time was " << max_nodes_in_q << "." << endl;
			cout << "The depth of the goal node was " << goal_depth << "." <<endl;

			cout << "would you like the solution(y/n)?" << endl;
			string user_input;
			cin >> user_input;
			if (user_input == "y") {
				cout << "Goal Path" << endl;
				
				vector<Node*> goal_path;
				while(current != NULL)
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
		explored.insert(current->getBoard());                  //add board to explored set

		//Conditional output that will differ the first expansion from all others.
		if (current->getNodeDepth() == 0)
		{
			cout << "Exanding state" << endl;
			current->printNodeBoard();
		}
		else {
			cout << "The best state to expand with g(n) = " << current->getNodeDepth() << " is..." << endl;
			current->printNodeBoard();
		}

		nodes_expanded++;                                         //increment number of nodes expanded.

		//for each action, create a child node. If child node is not in explored or frontier add to priority queue
		Node* child_node = new Node;
		bool already_explored = false;                            // assume that generated set has not been explored
		
		//generate children
		for (int i = 1; i <= 4; i++) {
			already_explored = false;

			child_node = createChildNode(current, i, 0);            //create child node from parent node
			

			//check if child_node has been previously explored
			//check explored set
			for (int i = 0; i < explored.size(); i++) {

				if (child_node->getBoard() == explored.at(i)) {
					already_explored = true;
					break;
				}

			}
			//check in_q
			if (!already_explored) {
				for (int i = 0; i < in_q.size(); i++) {

					if (child_node->getBoard() == in_q.at(i)) {
						already_explored = true;
						break;
					}
				}

			}

			//after checking explored_set and in_q add child to priority queue and in_q
			if (!already_explored) {
				frontier.push(child_node);
				in_q.insert(child_node->getBoard());
				if(frontier.size() > max_nodes_in_q) max_nodes_in_q = frontier.size(); //sets max nodes of queue
			}
		}
	}
	cout << "No Solution" << endl;
		return false;
}

//Graph search takes in board and determines the goal state based on the heurisitc provided by the user
bool graph_search(Board b, int heuristic_decision) {

	int nodes_expanded = 0;             //Keeps track of nodes expanded.
	int max_nodes_in_q = 0;
	int goal_depth = 0;

	Node* current = new Node();
	current->setBoard(b);               //Node contains initial state of Board b and path cost = 0

	Board goal;
	goal.setToGoalState();

	priority_queue<Node*, vector<Node*>, Comp> frontier;     //a priority quete ordered by Path-Cost, with node as the only element
	frontier.push(current);

	set<Board> explored;            //an empty set
	set<Board> in_q;                //mimics priority q, used to compare to child node

	while (true) {

		//returns false if there are no nodes to expand
		if (frontier.empty()) {
			cout << "frontier is empty" << endl;
			return false;
		}

		current = frontier.top();    //chooses the lowerst-cost node in frontier
		frontier.pop();              //pop frontier
									 //remove popped board from in_q
		for (int i = 0; i < in_q.size(); i++) {
			if (current->getBoard() == in_q.at(i)) {
				in_q.erase(in_q.begin() + i);
				break; //if we found a match there is no need to continue the loop
			}
		}

		//perform goal test on current node
		if (current->getBoard() == goal) {
			cout << "Goal State reached!" << endl;
			goal_depth = current->getNodeDepth();

			cout << "To solve this problem the search algorithm expanded a total of " << nodes_expanded << " nodes." << endl;
			cout << "The maximum number of nodes in queue at any one time was " << max_nodes_in_q << "." << endl;
			cout << "The depth of the goal node was " << goal_depth << "." << endl;

			cout << "would you like the solution(y/n)?" << endl;
			string user_input;
			cin >> user_input;
			if (user_input == "y") {
				cout << "Goal Path" << endl;

				vector<Node*> goal_path;
				while (current != NULL)
				{
					goal_path.insert(current);
					current = current->getParentNode();
				}
				for (int i = goal_path.size() - 1; i >= 0; i--) {
					cout << "move applied: " << goal_path.at(i)->move_applied << endl;
					goal_path.at(i)->printNodeBoard();
				}
			}

			return true;
		}
		explored.insert(current->getBoard());                  //add board to explored set

																  //Conditional output that will differ the first expansion from all others.
		if (current->getNodeDepth() == 0)
		{
			cout << "Expanding state" << endl;
			current->printNodeBoard();
		}
		else {
			cout << "The best state to expand with g(n) = " << current->getNodeDepth() << " is..." << endl;
			current->printNodeBoard();
		}

		nodes_expanded++;                                         //increment number of nodes expanded.

																  //for each action, create a child node. If child node is not in explored or frontier add to priority queue
		Node* child_node = new Node;
		bool already_explored = false;                            // assume that generated set has not been explored

																  //generate children
		for (int i = 1; i <= 4; i++) {
			already_explored = false;

			child_node = createChildNode(current, i, heuristic_decision);            //create child node from parent node


																 //check if child_node has been previously explored
																 //check explored set
			for (int i = 0; i < explored.size(); i++) {

				if (child_node->getBoard() == explored.at(i)) {
					already_explored = true;
					break;
				}

			}
			//check in_q
			if (!already_explored) {
				for (int i = 0; i < in_q.size(); i++) {

					if (child_node->getBoard() == in_q.at(i)) {
						already_explored = true;
						break;
					}
				}

			}

			//after checking explored_set and in_q add child to priority queue and in_q
			if (!already_explored) {
				frontier.push(child_node);
				in_q.insert(child_node->getBoard());
				if (frontier.size() > max_nodes_in_q) max_nodes_in_q = frontier.size(); //sets max nodes of queue
			}
		}
	}
	cout << "No Solution" << endl;
	return false;
}


//createChildNode takes a pointer to the parent Node, creates a copy of the parent and applies the appropriate move to it. 
Node* createChildNode(Node *parent, int action) {
	
	Node* child = new Node;
	*child = *parent;                              //create a copy of the parent node called child.   
	Board child_board = parent->getBoard();			  //create a copy of the parent nodes board
	child->move_applied = child_board.move(action);    //apply move action to child board
	child->setBoard(child_board);				      // save child board to child node
	child->setParentNode(parent);			          // child nodes points to parent node
	
	return child;
}

//createChildNode takes a pointer to the parent Node, creates a copy of the parent and applies the appropriate move to it. 
Node* createChildNode(Node *parent, int action, int h) {

	Node* child = new Node;
	*child = *parent;                              //create a copy of the parent node called child.   
	Board child_board = parent->getBoard();			  //create a copy of the parent nodes board
	child->move_applied = child_board.move(action);    //apply move action to child board
	child->setBoard(child_board);				      // save child board to child node
	
	if (h == 0) child->h_of_n = 0;
	if (h == 1) child->h_of_n = child->getBoard().getManhattanDistance();
	if (h == 2) child->h_of_n = child->getBoard().getMisplacedTileDistance();
	child->setParentNode(parent);			          // child nodes points to parent node
	return child;
}

//Node* createRootNode(Board parent) {
//	
//	Node root;
//	root.setBoard(parent);
//
//	return root;
//}
