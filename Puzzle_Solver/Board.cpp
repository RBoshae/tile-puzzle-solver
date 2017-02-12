#include "Board.h"



Board::Board()
{
	int count = 1;
	move_applied = "initial state";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {

			board_configuration[i][j] = count;
			count++;
		}
	}
		 blank_row_pos = 2; blank_col_pos = 0;
		board_configuration[blank_row_pos][blank_col_pos] = 0;
		board_configuration[2][1] = 7;
		board_configuration[2][2] = 8;
}


Board::~Board()
{
}

void Board::setBoard()
{
	char user_input[100];
	int column_pos = 0;

	cout << "Enter your puzzle, use a zero to represent the blank" << endl;
	
	// TODO: Reduce the following code to a neat for loop.
	
	cout << "Enter the first row, use space or tabs between numbers      ";
	cin.ignore();
	cin.getline(user_input, sizeof(user_input));  //cout << endl;
		
	//loop that will parse user input and store it in a Board data structure
	for (int i = 0; i < 100; i++) {
		if (user_input[i] >= '0' && user_input[i] <= '9') {
			board_configuration[0][column_pos] = user_input[i] - '0';
			
			if (board_configuration[0][column_pos] == 0) {
				blank_row_pos = 0;
				blank_col_pos = column_pos;
			}
			column_pos++;
		}
	}
	
	column_pos = 0;

	cout << "Enter the second row, use space or tabs between numbers     ";
	
	cin.getline(user_input, sizeof(user_input));//  cout << endl;
	for (int i = 0; i < 100; i++) {
		if (user_input[i] >= '0' && user_input[i] <= '9') {
			board_configuration[1][column_pos] = user_input[i] - '0';

			if (board_configuration[1][column_pos] == 0) {
				blank_row_pos = 1;
				blank_col_pos = column_pos;
			}

			column_pos++;
		}
	}

	column_pos = 0;
	
	cout << "Enter the third row, use space or tabs between numbers      ";
	
	cin.getline(user_input, sizeof(user_input));  //cout << endl;
	for (int i = 0; i < 100; i++) {
		if (user_input[i] >= '0' && user_input[i] <= '9') {
			board_configuration[2][column_pos] = user_input[i] - '0';

			if (board_configuration[2][column_pos] == 0) {
				blank_row_pos = 2;
				blank_col_pos = column_pos;
			}

			column_pos++;
		}
	}

	return;
}



void Board::setToGoalState() 
{
	int count = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			board_configuration[i][j] = count;
			count++;
		}

		blank_col_pos = 2; blank_row_pos = 2;
		board_configuration[blank_row_pos][blank_col_pos] = 0;
		
	}
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

string Board::move(int action)
{
	//locate position of blank tile on board. Reminder that 0 is the placeholder for the blank tile.
	switch (action)
	{
	case 1: //up
		if (blank_row_pos > 0) {
			board_configuration[blank_row_pos][blank_col_pos] = board_configuration[blank_row_pos - 1][blank_col_pos];
			board_configuration[blank_row_pos - 1][blank_col_pos] = 0;
			blank_row_pos--;
			move_applied = "blank tile up";
		}

		break;
	case 2: //down
		if (blank_row_pos < 2) {
			board_configuration[blank_row_pos][blank_col_pos] = board_configuration[blank_row_pos + 1][blank_col_pos];
			board_configuration[blank_row_pos + 1][blank_col_pos] = 0;
			blank_row_pos++;
			move_applied = "blank tile down";
		}
		break;
	case 3: //left
		if (blank_col_pos > 0) {
			board_configuration[blank_row_pos][blank_col_pos] = board_configuration[blank_row_pos][blank_col_pos - 1];
			board_configuration[blank_row_pos][blank_col_pos - 1] = 0;
			blank_col_pos--;
			move_applied = "blank tile left";
		}
		break;
	case 4: //right
		if (blank_col_pos < 2) {
			board_configuration[blank_row_pos][blank_col_pos] = board_configuration[blank_row_pos][blank_col_pos + 1];
			board_configuration[blank_row_pos][blank_col_pos + 1] = 0;
			blank_col_pos++;
			move_applied = "blank tile right";
		}
		break;
	default:
		break;
	}

	return move_applied;
}

// overloaded == operator
bool Board::operator==(const Board& other) const{
	bool same = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (this->board_configuration[i][j] == other.board_configuration[i][j]) {

				same = true;

			}
			else return false;
		}
	}
	
	return same;
}

//overloaded = operator
//Board Board::operator=(Board other) {
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (this->board_configuration[i][j] = other.board_configuration[i][j]) {
//
//
//			}
//			
//		}
//	}
//	return this;
//}


