#include <cassert>						// assert
#include <algorithm>					// algorithm
#include "../include/Board.h"

// Checks if passed configuration is legal returns true if legal
// otherwise returns false.

// Global
const int DEFAULT_CONFIG[NUMBER_OF_TILES] = {1,2,3,4,5,6,7,8,0};

// Helper functions
bool checkConfig(const int *_boardConfig)
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
	// Abstract representation of board. Numbers are position, not value.
	//  -------
	//	|0|1|2|
	//  |-+-+-|
	//	|3|4|5|
	//  |-+-+-|
	//  |6|7|8|
	//  -------

	for (int i = 0; i < NUMBER_OF_TILES; i++){
		m_boardConfiguration[i] = DEFAULT_CONFIG[i];
	}

	// Sets third row of board.
	m_boardConfiguration[2] = 0;
	m_boardConfiguration[5] = 3;
	m_boardConfiguration[8] = 6;

	m_blankTileIndex = 2;				// Store location of blank tile.
}

Board::Board(int _boardConfiguration[NUMBER_OF_TILES])
{
	set(_boardConfiguration);
}


Board::~Board()
{
}

bool Board::set(const int _boardConfiguration[NUMBER_OF_TILES])
{
	if (::checkConfig(_boardConfiguration)){
		for(int i = 0; i < NUMBER_OF_TILES; i++){
			m_boardConfiguration[i] = _boardConfiguration[i];
			if(_boardConfiguration[i] == 0) {
				m_blankTileIndex = i;
			}
		}
		return true;
	}
	else {
		return false;
	}
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


// Abstract representation of board.
//  -------
//	|0|1|2|
//  |-+-+-|
//	|3|4|5|
//  |-+-+-|
//  |6|7|8|
//  -------
bool Board::move(MOVE action)
{
	bool moveApplied = false;
	switch (action)
	{
	case (MOVE::UP): //up
		//  -------
		//	|3|1|2|
		//  |-+-+-|
		//	|0|4|5|
		//  |-+-+-|
		//  |6|7|8|
		//  -------
		if (m_blankTileIndex > 2) {
			// Move non-blank tile to blank tile location.
			m_boardConfiguration[m_blankTileIndex] = m_boardConfiguration[m_blankTileIndex-3];

			// Set blank tile.
			m_blankTileIndex = m_blankTileIndex - 3;
			m_boardConfiguration[m_blankTileIndex] = 0;
			moveApplied = true;
		}
		break;
	case (MOVE::DOWN): //down
		//  -------
		//	|3|1|2|
		//  |-+-+-|
		//	|0|4|5|
		//  |-+-+-|
		//  |6|7|8|
		//  -------
	if (m_blankTileIndex + 3 < NUMBER_OF_TILES - 1) {
		// Move non-blank tile to blank tile location.
		m_boardConfiguration[m_blankTileIndex] = m_boardConfiguration[m_blankTileIndex+3];

		// Set blank tile.
		m_blankTileIndex = m_blankTileIndex + 3;
		m_boardConfiguration[m_blankTileIndex] = 0;
		moveApplied = true;
	}
		break;
	case (MOVE::LEFT): //left
	if (m_blankTileIndex%3 != 0) {
		// Move non-blank tile to blank tile location.
		m_boardConfiguration[m_blankTileIndex] = m_boardConfiguration[m_blankTileIndex-1];
		m_blankTileIndex = m_blankTileIndex - 1;
		m_boardConfiguration[m_blankTileIndex] = 0;
		moveApplied = true;
	}
		break;
	case (MOVE::RIGHT): //right
	if ((m_blankTileIndex + 1)%3 != 0) {
		m_boardConfiguration[m_blankTileIndex] = m_boardConfiguration[m_blankTileIndex+1];
		m_blankTileIndex = m_blankTileIndex + 1;
		m_boardConfiguration[m_blankTileIndex] = 0;
		moveApplied = true;
	}
		break;
	default:
		break;
	}

	return moveApplied;
}


void Board::randomize()
{
	random_shuffle(std::begin(m_boardConfiguration), std::end(m_boardConfiguration));
	// find blank tile _location
	findAndSetBlankTileLocation();
	return;
}


void Board::operator =(const Board &other) {
	set(other.m_boardConfiguration);
	return;
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


// overloaded == operator
bool Board::operator<(const Board& other) const {

	for (int i = 0; i < NUMBER_OF_TILES; i++) {
		if (this->m_boardConfiguration[i] < other.m_boardConfiguration[i]) {
			return true;
		}
	}

	return false;
}

// Private Function Definitions.
void Board::findAndSetBlankTileLocation() {
	for (int index = 0; index < NUMBER_OF_TILES; index++) {
		if (this->m_boardConfiguration[index] == 0) {
			m_blankTileIndex = index;
			break;
		}
	}
}
