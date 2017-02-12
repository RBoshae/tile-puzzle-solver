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

//#include "Problem.h" - removing because it feels unecessary

using namespace std;

//Used for priorty queue 
struct Comp {
	bool operator () (Node lhs, Node rhs) {
		return lhs.getFofN() > rhs.getFofN();
	}
	/*bool operator () (Node* lhs, Node* rhs) {
		return lhs->getFofN() > rhs->getFofN();
	}*/
};

//bool graph_search(Board b, int heuristic_decision);
bool uniform_cost_search(Board b);
Node createChildNode(Node *parent, int action);
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

		valid = true;                           //Assume the cin will be an integer

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
	case 2: cout << "A* with the Misplaced Tile heuristic selected" << endl;
		break;
	case 3: cout << "A* with the Manhattan distance heuristic." << endl;
		break;
	default: cout << "Invalid Input. Please be sure to enter \"1\" , \"2.\", or \"2.\"" << endl;
		break;
	}




	
	system("PAUSE");
	return 0;
}


bool uniform_cost_search(Board b) {

	Node current;
	current.setBoard(b);               //Node contains initial state of Board b and path cost = 0
	Board goal;                   ///
	goal.setToGoalState();         ///

	priority_queue<Node, vector<Node>, Comp> frontier;     //a priority quete ordered by Path-Cost, with node as the only element
	frontier.push(current);

	vector<Board> explored;            //an empty set
	vector<Board> in_q;                //mimics priority q, used to compare to child node

	while (true) {

		//returns false if there are no nodes to expand
		if (frontier.empty()) {
			return false;
		}

		current = frontier.top();    //chooses the lowerst-cost node in frontier
		frontier.pop();              //pop frontier
		//remove popped board from in_q
		for (int i = 0; i < in_q.size(); i++) {
			if (current.getBoard() == in_q.at(i)) {
				in_q.erase(in_q.begin() + i);
				break; //if we found a match there is no need to continue the loop
			}
		}

		//perform goal test on current node
		if (current.getBoard() == goal) {
			cout << "Goal State reached!" << endl;

			cout << "would you like the solution(y/n)?" << endl;
			string user_input;
			cin >> user_input;
			if (user_input == "y") {
				cout << "Goal Path" << endl;
				for (int i = 0; i < current.board_history.size(); i++)
				{
					//cout << "move applied: " << current.board_history.at(i) << endl;
					current.board_history.at(i).printBoard();
					cout << endl;
				}
				current.printNodeBoard();
			}

			return true;
		}
		explored.push_back(current.getBoard());         //add board to explored set

		if (current.getNodeDepth() == 0)
		{
			cout << "Exanding state" << endl;
			current.printNodeBoard();
		}
		else {
			cout << "The best state to expand with g(n) = " << current.getNodeDepth() << " is..." << endl;
			current.printNodeBoard();
		}

		//for each action, create a child node. If child node is not in explored or frontier add to priority queue
		Node child_node;
		bool already_explored = false;                            // assume that generated set has not been explored
		
		//generate children
		for (int i = 1; i <= 4; i++) {
			already_explored = false;

			child_node = createChildNode(&current, i);            //create child node from parent node
			

			//check if child_node has been previously explored
			//check explored set
			for (int i = 0; i < explored.size(); i++) {

				if (child_node.getBoard() == explored.at(i)) {
					already_explored = true;
					break;
				}

			}
			//check in_q
			if (!already_explored) {
				for (int i = 0; i < in_q.size(); i++) {

					if (child_node.getBoard() == in_q.at(i)) {
						already_explored = true;
						break;
					}
				}

			}

			//after checking explored_set and in_q add child to priority queue and in_q
			if (!already_explored) {
				frontier.push(child_node);
				in_q.push_back(child_node.getBoard());
			}
		}
	}
	cout << "No Solution" << endl;
		return false;
}
/*

//Graph search takes in board and determines the goal state based on the heurisitc provided by the user
bool graph_search(Board b, int heuristic_decision) {

	vector<Node> explored_set;           //explored set keeps an account of all boards that have been previously expanded.
	bool explored = false;               //we assume upon the generation of a new board it has not been explored.
	priority_queue<Node, vector<Node>, Comp> node_q;

	int graph_depth = 0;                 //keeps track of graph depth.
	int index = 0;
	Board goal_state;                    //Declare an object naemd goal_state of type Board.
	goal_state.setToGoalState();         //set goal_state to the problem goal state.

	Node child_node;                                 // allocate memory for child

	//Uniform Cost Search
	if (heuristic_decision == 1) {

		
		Node root;
		root.setBoard(b);
		Node current_node;
		
		node_q.push(root);
		
		while (!node_q.empty()) {
			current_node = node_q.top();
			node_q.pop();
			
			if (current_node.getBoard() == goal_state) {
				cout << "Goal!!" << endl;

				cout << "Would you like the parent?(y/n)";
				string user_response = "no";
				cin >> user_response;
				if (user_response == "y") {
					
					
					//store solution set in a vector
					vector<Node> solution_set;
					while (current_node.getParentNode() != NULL || current_node.getParentNode()->move_applied == "initial state") {

						//solution_set.push_back(current_node);
						current_node.printNodeBoard();
						cout << endl;
						current_node = *current_node.getParentNode();

					}



				}
				return true;
			}
			
			explored_set.push_back(current_node); //add soon to be expanded node to explored set.
			index++;

			if (current_node.getNodeDepth() == 0)
			{
				cout << "Exanding state" << endl;
				current_node.printNodeBoard();
			}
			else {
				cout << "The best state to expand with g(n) = " << current_node.getNodeDepth() << " is..." << endl;
				current_node.printNodeBoard();
			}

			//generate child node from all possible moves
			for (int i = 1; i <= 4; i++) {
				explored = false;                                              //default state of explored is false
				

				child_node = createChildNode(&current_node, i);              //create child node from parent node
				
				
		        //check if child_node has been previously explored
				for (int i = 0; i < explored_set.size(); i++) {

					if (child_node.getBoard() == explored_set.at(i).getBoard()) {
						explored = true;
						//continue;
					}
				
					//after checking redundant state add child to queue
					if (explored == false) {
						//child_node.setParentNode(&explored_set.at(index-1));

						node_q.push(child_node);
					}
				}

				explored = false; // reset explored to false state for next move application

			}
			//node_q.pop();
			//current_node = node_q.top();
		}
		

		
		return false;
	}


	//Manhattan
	//Misplaced Tile

	
	return true;
}

*/

//createChildNode takes a pointer to the parent Node, creates a copy of the parent and applies the appropriate move to it. 
Node createChildNode(Node *parent, int action) {
	
	Node child = *parent;                              //create a copy of the parent node called child.   
	Board child_board = parent->getBoard();			  //create a copy of the parent nodes board
	child.move_applied = child_board.move(action);    //apply move action to child board
	child.setBoard(child_board);				      // save child board to child node
	child.setParentNode(parent);			          // child nodes points to parent node
	
	return child;
}

//Node* createRootNode(Board parent) {
//	
//	Node root;
//	root.setBoard(parent);
//
//	return root;
//}
