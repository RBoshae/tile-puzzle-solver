#include "Problem.h"



Problem::Problem()
{
	
	initial_state = new Board();
	goal_state = new Board();
	goal_state->setToGoalState();
	
}

Problem::Problem(Board* user_Board)
{
	initial_state = user_Board;
	goal_state = new Board();
	goal_state->setToGoalState();
}


Problem::~Problem()
{
}
