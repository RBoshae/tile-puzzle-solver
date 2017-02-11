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
//#include "Problem.h" - removing because it feels unecessary

using namespace std;

bool graph_search(Board b, int heuristic_decision);
Board createChild(Board parent, int action);

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

		if (cin.fail()) {//cin.fail() checks to see if the value in the cin stream is the correct type, if not returns true, otherwise false.
			cin.clear(); //This corrects the stream
			cin.ignore(); // This skips the left over stream data
			cout << "Please enter an integer value only." << endl;
			valid = false; //The cin was not an integer so try again.
		} 
	}

	valid = false; //valid will be resused so we set it back to false


	switch (menu_selection)
	{

		case 1: cout << "default puzzle selected." << endl;
			break;
		case 2: cout << "custom puzzle selected." << endl;
			//no need to set default problem since the Board default constructor already contains a default board
			cout << "This is your Board:" << endl;
			testBoard.setBoard(); //declare new board object
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

		valid = true; //Assume the cin will be an integer

		cin >> heuristic_choice;

		if (cin.fail()) {//cin.fail() checks to see if the value in the cin stream is the correct type, if not returns true, otherwise false.
			cin.clear(); //This corrects the stream
			cin.ignore(); // This skips the left over stream data
			cout << "Please enter an integer value only." << endl;
			valid = false; //The cin was not an integer so try again.
		}
	}



	switch (heuristic_choice)
	{

	case 1: cout << "Uniform Cost Search selected" << endl;
		break;
	case 2: cout << "A* with the Misplaced Tile heuristic selected" << endl;
		break;
	case 3: cout << "A* with the Manhattan distance heuristic." << endl;
		break;
	default: cout << "Invalid Input. Please be sure to enter \"1\" , \"2.\", or \"2.\"" << endl;
		break;
	}


	cout << "Board Initial State:" <<endl;
	testBoard.printBoard();


	
	system("PAUSE");
	return 0;
}






bool graph_search(Board b, int heuristic_decision) {

	vector<Board> explored_set;
	bool explored = false;

	int graph_depth = 0;
	Board goal_state;
	Board childBoard;
	goal_state.setToGoalState();

	//Uniform Cost Search
	if (heuristic_decision == 1) {
		queue<Board> board_q;

		if (b == goal_state) {
			cout << "GOAL!!!";
			return true;
		}
		else {
			for (int i = 0; i < 3; i++) {

			childBoard = createChild(b, i);//

			for (int i = 0; i < explored_set.size(); i++) {
			
				if (childBoard == explored_set.at(i)) {
					explored = true;
				}
			}

			if (explored == false) {
				board_q.push(childBoard);
			}

			}
		}

		
		return false;
	}


	//Manhattan
	//Misplaced Tile

	
	return true;
}

Board createChild(Board parent, int action) {
	Board child = parent;
	child.move(1);
	
	return child;
}
