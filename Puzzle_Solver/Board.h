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
	Board();
	~Board();

	void setBoard();
	void printBoard();

private:
	int board_configuration[3][3];
};

#endif