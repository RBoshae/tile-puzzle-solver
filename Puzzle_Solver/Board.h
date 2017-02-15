/*
 * File: Board.h
 * ---------------------
 * Board.h provides an interface for 8-sliding tile puzzle.
 *
 * Created by Rick Boshae on 1/29/17.
 *
 */


#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>

using namespace std;

class Board
{
public:
	int board_configuration[3][3];


	// I would like to consider using a switch value rather than an integer value 
	// enum action { blank_up, blank_down, blank_left, blank_right };

	Board();
	~Board();

	void setBoard();
	void setToGoalState();
	void printBoard();
	string move(int action);
	bool Board::operator==(const Board &other) const;
	
	int getManhattanDistance();
	int getMisplacedTileDistance();

private:
	//responsible for keeping track of blank tile so we do not have to search for it later.
	int blank_row_pos;
	int blank_col_pos;
	string move_applied;

	int misplaced_tile;
	int manhattan_distance;

	void compute_manhattan_distance();
	void compute_misplaced_tile_distance();

protected:
	

};

#endif