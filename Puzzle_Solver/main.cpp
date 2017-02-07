/*
* File: main.cpp
* ----------------
* Created by Rick Boshae on 1/29/17.
*/
#include <iostream>
#include <string>
#include "Board.h"

using namespace std;

void menu();

int main() {

	cout << "Welcome to Rick's 8-puzzle solver." << endl;
	menu();
	
	system("PAUSE");
	return 0;
}





void menu() {

	int menu_selection = 0;
	bool valid = false;
	Board* testBoard = new Board();
	
	//Prompt user
	
	cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;

	while (!valid) {

		valid = true; //Assume the cin will be an integer

		cin >> menu_selection;

		if (cin.fail()) {  //cin.fail() checks to see if the value in the cin stream is the correct type, if not returns true, otherwise false.
			cin.clear(); //This corrects the stream
			cin.ignore(); // This skips the left over stream data
			cout << "Please enter an integer value only." << endl;
			valid = false; //The cin was not an integer so try again.
		} //end of if statement
	} //end of while loop

	
	switch (menu_selection)
	{
	case 1: cout << "default puzzle selected." << endl;
		break;
	case 2: cout << "custom puzzle selected." << endl; 
		testBoard->setBoard(); 
		cout << "This is your Board:" << endl;
		testBoard->printBoard();
		break;
	default: cout << "Invalid Input. Please be sure to enter \"1\" or \"2.\"" << endl; menu(); //recursive call to menu
		break;
	} //end of switch
		
	
	return;
} //end of menu