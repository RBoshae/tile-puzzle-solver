#include <cassert>						// assert
#include <algorithm>					// algorithm
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
	// Abstractr representation of board.
	//  -------
	//	|0|1|2|
	//  |-+-+-|
	//	|3|4|5|
	//  |-+-+-|
	//  |6|7|8|
	//  -------

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
	assert(::checkConfig(_boardConfiguration));

	for(int i = 0; i < NUMBER_OF_TILES; i++) {
		m_boardConfiguration[i] = _boardConfiguration[i];
		if(_boardConfiguration[i] == 0) {
			m_blankTileLocation = i;
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
			if(_boardConfiguration[i] == 0) {
				m_blankTileLocation = i;
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

bool Board::move(Board::MOVE action)
{
	bool moveApplied = false;
	switch (action)
	{
	case (Board::UP): //up
		if (m_blankTileLocation - 4 > 0) {
			m_boardConfiguration[m_blankTileLocation] = m_blankTileLocation[m_blankTileLocation-4];
			m_blankTileLocation = m_blankTileLocation - 4;
			moveApplied = true;
		}
		break;
	case (Board::DOWN): //down
	if (m_blankTileLocation + 4 < NUMBER_OF_TILES) {
		m_boardConfiguration[m_blankTileLocation] = m_blankTileLocation[m_blankTileLocation+4];
		m_blankTileLocation = m_blankTileLocation + 4;
		moveApplied = true;
	}
		break;
	case (Board::LEFT): //left
	if (m_blankTileLocation - 1 > 0) {
		m_boardConfiguration[m_blankTileLocation] = m_blankTileLocation[m_blankTileLocation-1];
		m_blankTileLocation = m_blankTileLocation - 1;
		moveApplied = true;
	}
		break;
	case (Board::RIGHT): //right
	if (m_blankTileLocation + 1 > 0) {
		m_boardConfiguration[m_blankTileLocation] = m_blankTileLocation[m_blankTileLocation+1];
		m_blankTileLocation = m_blankTileLocation + 1;
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
	for (int location = 0; location < NUMBER_OF_TILES; location++) {
		if(m_boardConfiguration[location] == 0){
			m_blankTileLocation = location;
			break;
		}
	}
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

// Private Function Definitions.
void Board::findAndSetBlankTileLocation() {
	for (int location = 0; location < NUMBER_OF_TILES; i++) {
		if (this->m_boardConfiguration[i] == 0 {
			m_blankTileLocation = location;
			break;
		}
	}
}
