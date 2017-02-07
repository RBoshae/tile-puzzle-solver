#include "Board.h"



Board::Board()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			board_configuration[i][j] = 0;

		}
	}
}


Board::~Board()
{
}

void Board::setBoard()
{
	char user_input[100];
	int column_pos = 0;

	cout << "Enter your puzzle, use a zero to represent the blank" << endl;
	
	cout << "Enter the first row, use space or tabs between numbers" << endl;
	cin.ignore();
	cin.getline(user_input, sizeof(user_input));  cout << endl;
		
	//loop that will parse user input and store it in a Board data structure
	for (int i = 0; i < 100; i++) {
		if (user_input[i] >= '0' && user_input[i] <= '9') {
			board_configuration[0][column_pos] = user_input[i] - '0';
			column_pos++;
		}
	}
	
	column_pos = 0;

	cout << "Enter the second row, use space or tabs between numbers" << endl;
	
	cin.getline(user_input, sizeof(user_input));  cout << endl;
	for (int i = 0; i < 100; i++) {
		if (user_input[i] >= '0' && user_input[i] <= '9') {
			board_configuration[1][column_pos] = user_input[i] - '0';
			column_pos++;
		}
	}

	column_pos = 0;
	
	cout << "Enter the third row, use space or tabs between numbers" << endl;
	
	cin.getline(user_input, sizeof(user_input));  cout << endl;
	for (int i = 0; i < 100; i++) {
		if (user_input[i] >= '0' && user_input[i] <= '9') {
			board_configuration[2][column_pos] = user_input[i] - '0';
			column_pos++;
		}
	}

	return;
}

void Board::printBoard()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board_configuration[i][j] == 0) cout << "b ";
			else
			{
				cout << board_configuration[i][j] << " ";
			}
			
		}
		cout << endl;
	}
	return;
}
