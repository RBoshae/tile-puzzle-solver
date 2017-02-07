/*
* File: Problem.h
* ---------------------
*
* Created by Rick Boshae on 2/05/17.
*
*/


#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <string>
#include "Puzzle.h"

using namespace std;

class Problem
{
public:
	Problem();
	~Problem();


	 
private: 
	Puzzle initial_state;
	Puzzle goal_state;
	const string blank_left = "blank left";
	const string blank_right = "blank right";
	const string blank_up = "blank up";
	const string blank_down = "blank down";

};

#endif