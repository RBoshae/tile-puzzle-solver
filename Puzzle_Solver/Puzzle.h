/*
 * File: Puzzle.h
 * ---------------------
 *
 * Created by Rick Boshae on 1/29/17.
 *
 */


#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <string>

using namespace std;

class Puzzle
{
public:
	Puzzle();
	~Puzzle();

	Puzzle setPuzzle();
private:
	int puzzle_configuration[3][3];
};

#endif