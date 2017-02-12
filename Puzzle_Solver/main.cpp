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
#include <stack>
#include "Board.h"
#include "Node.h"

//#include "Problem.h" - removing because it feels unecessary

using namespace std;

//Used for priorty queue 
struct Comp {
	bool operator () (Node lhs, Node rhs) {
		return lhs.getFofN() > rhs.getFofN();
	}
};

bool graph_search(Board b, int heuristic_decision);
Node createChildNode(Node* parent, int action);
Node createRootNode(Board b);

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

	case 1: cout << "Uniform Cost Search selected" << endl; graph_search(testBoard, 1);
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





//Graph search takes in board and determines the goal state based on the heurisitc provided by the user
bool graph_search(Board b, int heuristic_decision) {

	vector<Node> explored_set;           //explored set keeps an account of all boards that have been previously expanded.
	bool explored = false;               //we assume upon the generation of a new board it has not been explored.

	int graph_depth = 0;                 //keeps track of graph depth.
	Board goal_state;                    //Declare an object naemd goal_state of type Board.
	goal_state.setToGoalState();         //set goal_state to the problem goal state.

	Node child_node;

	//Uniform Cost Search
	if (heuristic_decision == 1) {
		priority_queue<Node, vector<Node>, Comp> node_q;
		Board root_board = b;
		Node root = createRootNode(root_board);
		//Node current;                                   //Keeps track of current node in queue
		
		node_q.push(root);
		Node current_node = node_q.top();
		
		while (!node_q.empty()) {
			
			if (current_node.getBoard() == goal_state) {
				cout << "Goal!!" << endl;

				cout << "Would you like the parent?(y/n)";
				string user_response = "no";
				cin >> user_response;
				if (user_response == "y") {
					cout << "goal board: " << endl;
					current_node.printNodeBoard();

					cout << "previous state" << endl;
					current_node.getParentNode()->printNodeBoard();

					current_node = *current_node.getParentNode();
					cout << "previous previous state" << endl;
					current_node.getParentNode()->printNodeBoard();

					//store solution set in a vector
					/*vector<Node> solution_set;
					while (current_node.getParentNode() != NULL) {

						solution_set.push_back(current_node);
						current_node = *current_node.getParentNode();

					}

					for (int i = solution_set.size(); i >= 0; i--) {

						solution_set.at(i).printNodeBoard();

					}*/



				}
				return true;
			}
			
			explored_set.push_back(current_node); //add soon to be expanded node to explored set.

			if (current_node.getNodeDepth() == 0)
			{
				cout << "Exanding state" << endl;
				current_node.printNodeBoard();
			}
			else {
				cout << "The best state to expand with g(n) = " << current_node.getNodeDepth() << " is..." << endl;
				current_node.printNodeBoard();
			}
			//iterated through all possible moves
			for (int i = 1; i <= 4; i++) {

				child_node = createChildNode(&current_node, i);              //create child node from parent node
				explored = false;                                              //default state of explored is false
				//check if child_node has been previously explored
				for (int i = 0; i < explored_set.size(); i++) {

					if (child_node.getBoard() == explored_set.at(i).getBoard()) {
						explored = true;
						continue;
					}
				}

				//after checking redundant state add child to queue
				if (explored == false) {
					child_node.setParentNode(&explored_set.at(explored_set.size()-1));
					node_q.push(child_node);
				}
				explored = false; // reset explored to false state for next move application

			}
			node_q.pop();
			current_node = node_q.top();
		}
		

		
		return false;
	}


	//Manhattan
	//Misplaced Tile

	
	return true;
}

//createChildNode takes a pointer to the parent Node, creates a copy of the parent and applies the appropriate move to it. 
Node createChildNode(Node* parent, int action) {
	
	Node child = *parent;                             //create a copy of the parent node called child.   
	Board child_board = parent->getBoard();			  //create a copy of the parent nodes board
	child.move_applied = child_board.move(action);    //apply move action to child board
	child.setBoard(child_board);				      // save child board to child node
	//child.setParentNode(parent);			          // child nodes points to parent node
	
	return child;
}

Node createRootNode(Board parent) {
	
	Node root;
	root.setBoard(parent);

	return root;
}
