/*
 * File: Board.h
 * ---------------------
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
	//enum action { blank_up, blank_down, blank_left, blank_right };

	Board();
	~Board();

	void setBoard();
	void printBoard();
	void move(int action);

private:
	int board_configuration[3][3];
	
	//responsible for keeping track of blank tile so we do not have to search for it later.
	int blank_row_pos;
	int blank_col_pos;
};

#endif