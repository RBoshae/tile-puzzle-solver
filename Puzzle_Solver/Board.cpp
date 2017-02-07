#include "Board.h"



Board::Board()
{
}


Board::~Board()
{
}

Board Board::setBoard()
{
	char user_input[100];

	cout << "Enter your puzzle, use a zero to represent the blank" << endl;
	
	cout << "Enter the first row, use space or tabs between numbers"; 
		cin.getline(user_input, sizeof(user_input));  cout << endl;
		//loop that will parse user input and store it in a Puzzle data structure
		for(int i)

	cout << "Enter the second row, use space or tabs between numbers" << endl;
		cin.getline(user_input, sizeof(user_input));  cout << endl;
	
	cout << "Enter the third row, use space or tabs between numbers" << endl;
		cin.getline(user_input, sizeof(user_input));  cout << endl;

	return Board();
}
