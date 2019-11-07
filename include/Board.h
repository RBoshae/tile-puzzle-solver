// File: Board.h
// ---------------------
// Board.h provides an abstraction for 8-sliding tile puzzle board.
//
// Created by Rick Boshae on 1/29/17.


#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Specifies the number of tiles on the board.
const int NUMBER_OF_TILES = 9;
enum class MOVE {UP, DOWN, LEFT, RIGHT};

class Board
{
public:
	Board();

	// Creates a board object with a user defined puzzle. Each array index
	// represent the placement of the tile from top left to bottom right.
	Board(int _boardConfig[NUMBER_OF_TILES]);
	~Board();

	// Returns true if board was changed. Returns false is board was not changed.
	// The board will not change to set values if illegal
	// values/placement is detected.
	bool set(const int _boardConfig[NUMBER_OF_TILES]);

	unsigned int getNumberOfTiles();
	void getBoardConfig(int* _boardConfig);

	void print();

	// Randomize the board configuration.
	void randomize();

	// Moves the position of the blank tile. Returns true if the move is valid
	// and returns false is the move is invalid. If the move is invalid the
	// state of the board is not changed.
	// Possible actions: UP, DOWN, LEFT, RIGHT.
	bool move(MOVE _move);

	void operator =(const Board &other);
	bool operator ==(const Board &other) const;
	friend bool operator <(const Board &lhs, const Board &rhs);

private:
	int m_boardConfiguration[NUMBER_OF_TILES];
	int m_blankTileIndex;
	void findAndSetBlankTileLocation();

};

#endif
