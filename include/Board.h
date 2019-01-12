/*
 * File: Board.h
 * ---------------------
 * Board.h provides an abstraction for 8-sliding tile puzzle board.
 *
 * Created by Rick Boshae on 1/29/17.
 *
 */


#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Global Constants.
const int NUMBER_OF_TILES = 9;

class Board
{
public:
	Board();								// Creates a board object with a default
													// puzzle assigned.

	Board(int _boardConfig[NUMBER_OF_TILES]);	// Creates a board object with a
																						// user defined puzzle. Each array
																						// index represent the placement of
																						// the tile from top left to bottom
																						// right.
	~Board();

	bool set(int _boardConfig[NUMBER_OF_TILES]); // Sets board. Returns true if
	                                    				 // board was changed. Returns
																							 // false is board was not
																							 // changed. The board will not
																							 // change to set values if the
																							 // illegal values/placement
													            				 // is detected.

	void print();
	void randomize();

	bool move(Move action);	// TODO: Refactor.
													// actions: up, down, left, right. Change
													// return type to boolean to represent if
													// the board was changed (true) or not (false)


	bool operator==(const Board &other) const;
	// bool operator<(const Board &other) const;


	// DEPRECATED
	// int getMisplacedTileDistance(); // TODO: Deprecate. Move to Node class
	// int getManhattanDistance();			// TODO: Deprecate. Move to Node class
	void setBoard();								// TODO: Deprecate
	void setToGoalState();  				// TODO: Deprecate
private:
	int m_boardConfiguration[NUMBER_OF_TILES];
	int m_blankTileLocation;

	void setBlankTileLocation(int _location);

};

#endif
