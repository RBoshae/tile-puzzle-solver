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

class Board
{
public:
	Board();								// Creates a board object with a default
													// puzzle assigned.

	Board(int _boardConfig[3][3]);	// Creates a board object with a user
																	// defined puzzle. Each array index
																	// represent the placement of the
																	// tile from top left to bottom right.
	~Board();

	bool set(int _boardConfig[3][3]);		// Sets board. Returns true if
	                                    // board was changed. Returns
																			// false is board was not
																			// changed. The board will not
																			// change to set values if the
																			// illegal values/placement
													            // is detected.


	void printBoard();      // TODO: Refactor. Rename function to print.
	string move(int action);// TODO: Refactor. Seperate move into four
													// actions: up, down, left, right. Change
													// return type to boolean to represent if
													// the board was changed (true) or not (false)


	bool operator==(const Board &other) const;
	bool operator<(const Board &other) const;


	// DEPRECATED
	int getMisplacedTileDistance(); // TODO: Deprecate. Move to Node class
	int getManhattanDistance();			// TODO: Deprecate. Move to Node class
	void randomBoard();			// TODO: Deprecate.
	void setBoard();				// TODO: Deprecate
	void setToGoalState();  // TODO: Deprecate
private:
	const int NUMBER_OF_TILES = 9;
	int m_boardConfiguration[3][3];

	//keeps track of blank tile so we do not have to search for it later.
	int blank_row_pos;
	int blank_col_pos;

	string move_applied;		// TODO: Deprecate

	int misplaced_tile;			// TODO: Deprecate
	int manhattan_distance;	// TODO: Deprecate

	void compute_manhattan_distance();			// TODO: Deprecate. Move to
	 																				// Node class
	void compute_misplaced_tile_distance(); // TODO: Deprecate. Move to
	 																				// Node class


};

#endif
