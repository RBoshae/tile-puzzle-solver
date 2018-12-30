#include "../include/Board.h"

// Checks if passed configuration is legal returns true if legal
// otherwise returns false.
bool checkConfig(int _boardConfig[NUMBER_OF_TILES])
{
	for (int i = 0; i <= NUMBER_OF_TILES; i++) {
		if (_boardConfig[i] < 0 || _boardConfig[i] > 8) return false;

		// TODO: Optimize
		for (int j = 0; j < i; j++){
			if _boardConfig[j] == _boardConfig[i] return false;
		}
		if (_boardConfig[i] == 0) {
			blank_row_pos = i/3;
			blank_col_pos = i%3;
		}
	}
	return true; // All checks pass
}


Board::Board()
{
	// Sets first and second row of the board.
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			board_configuration[i][j] = count;
			count++;
		}
	}
	// Sets third row of board.
  blank_row_pos = 2; blank_col_pos = 0;
	board_configuration[blank_row_pos][blank_col_pos] = 0;
	board_configuration[2][1] = 7;
	board_configuration[2][2] = 8;
}

Board::Board(int _boardConfig[3][3])
{
	if (::checkConfig(_boardConfig[3][3])){
		m_boardConfiguration = _values;
	} else {
		for (int i = 0; i < NUMBER_OF_TILES; i++) {
			m_boardConfiguration[i] = i;
		}
	}
}


Board::~Board()
{
}

bool Board::set(int _values[9])
{
	// TODO: Validate _values.
	m_values = _values;
}

// DEPRECATED
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
	compute_manhattan_distance();
	compute_misplaced_tile_distance();
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

	compute_manhattan_distance();
	compute_misplaced_tile_distance();

	return move_applied;
}


void Board::randomBoard()
{
	// Later I may include a function to randomize the board.
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

int Board::getManhattanDistance()
{
	compute_manhattan_distance();
	return manhattan_distance;
}

int Board::getMisplacedTileDistance()
{
	compute_misplaced_tile_distance();
	return misplaced_tile;
}

void Board::compute_manhattan_distance() {
	manhattan_distance = 0;
	int counter = 1;
	int row_delta = 0;
	int col_delta = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (board_configuration[i][j] != 0) {
				row_delta += abs(((board_configuration[i][j] - 1) / 3) - (counter - 1) / 3);
				col_delta += abs(((board_configuration[i][j] % 3) - 1) - ((counter % 3) - 1));
			}
			if (board_configuration[i][j] == 0) {
				row_delta += (2 - i);
				col_delta += (2 - i);
			}
			counter++;
			}
		}
	manhattan_distance = row_delta + col_delta;

	return;
	}

void Board::compute_misplaced_tile_distance() {
	misplaced_tile = 0;
	int counter = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (board_configuration[i][j] != counter && i != 2 && j != 2) {
				misplaced_tile++;
			}
			if (i == 2 & j == 2) {
				if (board_configuration[i][j] != 0) {
					misplaced_tile++;
				}
			}
		}
		counter++;

	}
	return;

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

bool Board::operator<( const Board& other) const
{

	stringstream total_other;
	stringstream total_this;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//if (other.board_configuration[i][j] == 0) {} else
			total_other << other.board_configuration[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			total_this << this->board_configuration[i][j];
		}
	}
	return (total_this.str() < total_other.str());
}
