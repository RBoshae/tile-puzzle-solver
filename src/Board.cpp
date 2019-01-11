#include "../include/Board.h"

// Checks if passed configuration is legal returns true if legal
// otherwise returns false.

// Global
const int DEFAULT_CONFIG[NUMBER_OF_TILES] = {1,2,3,4,5,6,7,8,0};

// Helper functions
bool checkConfig(int *_boardConfig)
{
	for (int i = 0; i < NUMBER_OF_TILES; i++) {
		if (_boardConfig[i] < 0 || _boardConfig[i] > 8) return false;

		// TODO: Optimize
		for (int j = 0; j < i; j++) {
			if (_boardConfig[j] == _boardConfig[i]) return false;
		}
	}
	return true; // All checks pass
}

Board::Board()
{
	// Representation of board.
	//  +------+
	//	|0|1|2|
	//	|3|4|5|
	//  |6|7|8|
	//  +-----+

	for (int i = 0; i < 6; i++){
		m_boardConfiguration[i] = DEFAULT_CONFIG[i];
	}

	// Sets third row of board.
	m_boardConfiguration[7] = 7;
	m_boardConfiguration[8] = 8;
	m_boardConfiguration[6] = 0;

	m_blankTileLocation = 6;				// Store location of blank tile.
}

Board::Board(int _boardConfiguration[NUMBER_OF_TILES])
{
	if (::checkConfig(_boardConfiguration)) {
		for(int i = 0; i < NUMBER_OF_TILES; i++){
			m_boardConfiguration[i] = _boardConfiguration[i];
		}
	}
	else {
		cerr << "Invalid board configuration. Setting board to default configuration." << endl;
		for (int i = 0; i < NUMBER_OF_TILES; i++){
			m_boardConfiguration[i] = DEFAULT_CONFIG[i];
		}
	}
}


Board::~Board()
{
}

bool Board::set(int _boardConfiguration[NUMBER_OF_TILES])
{
	if (::checkConfig(_boardConfiguration)){
		for(int i = 0; i < NUMBER_OF_TILES; i++){
			m_boardConfiguration[i] = _boardConfiguration[i];
		}
		return true;
	}
	else {
		return false;
	}
}

// DEPRECATED
void Board::setBoard()
{
	// char user_input[100];
	// int column_pos = 0;
	//
	// cout << "Enter your puzzle, use a zero to represent the blank" << endl;
	//
	// // TODO: Reduce the following code to a neat for loop.
	//
	// cout << "Enter the first row, use space or tabs between numbers      ";
	// cin.ignore();
	// cin.getline(user_input, sizeof(user_input));  //cout << endl;
	//
	// //loop that will parse user input and store it in a Board data structure
	// for (int i = 0; i < 100; i++) {
	// 	if (user_input[i] >= '0' && user_input[i] <= '9') {
	// 		board_configuration[0][column_pos] = user_input[i] - '0';
	//
	// 		if (board_configuration[0][column_pos] == 0) {
	// 			blank_row_pos = 0;
	// 			blank_col_pos = column_pos;
	// 		}
	// 		column_pos++;
	// 	}
	// }
	//
	// column_pos = 0;
	//
	// cout << "Enter the second row, use space or tabs between numbers     ";
	//
	// cin.getline(user_input, sizeof(user_input));//  cout << endl;
	// for (int i = 0; i < 100; i++) {
	// 	if (user_input[i] >= '0' && user_input[i] <= '9') {
	// 		board_configuration[1][column_pos] = user_input[i] - '0';
	//
	// 		if (board_configuration[1][column_pos] == 0) {
	// 			blank_row_pos = 1;
	// 			blank_col_pos = column_pos;
	// 		}
	//
	// 		column_pos++;
	// 	}
	// }
	//
	// column_pos = 0;
	//
	// cout << "Enter the third row, use space or tabs between numbers      ";
	//
	// cin.getline(user_input, sizeof(user_input));  //cout << endl;
	// for (int i = 0; i < 100; i++) {
	// 	if (user_input[i] >= '0' && user_input[i] <= '9') {
	// 		board_configuration[2][column_pos] = user_input[i] - '0';
	//
	// 		if (board_configuration[2][column_pos] == 0) {
	// 			blank_row_pos = 2;
	// 			blank_col_pos = column_pos;
	// 		}
	//
	// 		column_pos++;
	// 	}
	// }
	// compute_manhattan_distance();
	// compute_misplaced_tile_distance();
	// return;
}



void Board::setToGoalState()
{
	// int count = 1;
	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < 3; j++) {
	//
	// 		board_configuration[i][j] = count;
	// 		count++;
	// 	}
	//
	// 	blank_col_pos = 2; blank_row_pos = 2;
	// 	board_configuration[blank_row_pos][blank_col_pos] = 0;
	//
	// }
}



void Board::print()
{
	for (int i = 0; i < NUMBER_OF_TILES; i++) {
			if (m_boardConfiguration[i] == 0)
			{
				cout << "b ";
			}
			else
			{
				cout << m_boardConfiguration[i] << " ";
			}

			if ((i+1)%3 == 0) cout << endl;
	}
	return;
}

string Board::move(int action)
{
	// //locate position of blank tile on board. Reminder that 0 is the placeholder for the blank tile.
	// switch (action)
	// {
	// case 1: //up
	// 	if (blank_row_pos > 0) {
	// 		board_configuration[blank_row_pos][blank_col_pos] = board_configuration[blank_row_pos - 1][blank_col_pos];
	// 		board_configuration[blank_row_pos - 1][blank_col_pos] = 0;
	// 		blank_row_pos--;
	// 		move_applied = "blank tile up";
	// 	}
	//
	// 	break;
	// case 2: //down
	// 	if (blank_row_pos < 2) {
	// 		board_configuration[blank_row_pos][blank_col_pos] = board_configuration[blank_row_pos + 1][blank_col_pos];
	// 		board_configuration[blank_row_pos + 1][blank_col_pos] = 0;
	// 		blank_row_pos++;
	// 		move_applied = "blank tile down";
	// 	}
	// 	break;
	// case 3: //left
	// 	if (blank_col_pos > 0) {
	// 		board_configuration[blank_row_pos][blank_col_pos] = board_configuration[blank_row_pos][blank_col_pos - 1];
	// 		board_configuration[blank_row_pos][blank_col_pos - 1] = 0;
	// 		blank_col_pos--;
	// 		move_applied = "blank tile left";
	// 	}
	// 	break;
	// case 4: //right
	// 	if (blank_col_pos < 2) {
	// 		board_configuration[blank_row_pos][blank_col_pos] = board_configuration[blank_row_pos][blank_col_pos + 1];
	// 		board_configuration[blank_row_pos][blank_col_pos + 1] = 0;
	// 		blank_col_pos++;
	// 		move_applied = "blank tile right";
	// 	}
	// 	break;
	// default:
	// 	break;
	// }
	//
	// compute_manhattan_distance();
	// compute_misplaced_tile_distance();
	//
	// return move_applied;
	return "null";
}


void Board::randomize()
{
	// TODO: randomize the board.
}

// overloaded == operator
bool Board::operator==(const Board& other) const {
	bool isIdentical = true;
	for (int i = 0; i < NUMBER_OF_TILES; i++) {
		if (this->m_boardConfiguration[i] != other.m_boardConfiguration[i]) {
			isIdentical = false;
			break;
		}
	}
	return isIdentical;
}

// Private Function Definitions.
void Board::setBlankTileLocation(int _location) {
	m_blankTileLocation = _location;
}
