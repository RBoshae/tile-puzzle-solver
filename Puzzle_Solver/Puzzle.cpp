#include "Puzzle.h"



Puzzle::Puzzle()
{
}


Puzzle::~Puzzle()
{
}

Puzzle Puzzle::setPuzzle()
{
	char user_input[100];

	cout << "Enter your puzzle, use a zero to represent the blank" << endl;
	
	cout << "Enter the first row, use space or tabs between numbers"; 
		cin.getline(user_input, sizeof(user_input));  cout << endl;

	
		cout << "Enter the second row, use space or tabs between numbers" << endl;
	
	cout << "Enter the third row, use space or tabs between numbers" << endl;

	return Puzzle();
}
