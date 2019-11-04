

#include "../include/Board.h"

#include <iostream>
#include <cassert>

bool testCenterLeftMove();
bool testCenterRightMove();
bool testCenterUpMove();
bool testCenterDownMove();

bool testTopRightLeftMove();
bool testTopRightRightMove();
bool testTopRightUpMove();
bool testTopRightDownMove();

int main() {
 
  cout << "Center Left Move: ";
  if(testCenterLeftMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Center Right Move: ";
  if(testCenterRightMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

    cout << "Center Up Move: ";
  if(testCenterUpMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Center Down Move: ";
  if(testCenterDownMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Top Right Left Move: ";
  if(testTopRightLeftMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Top Right Right Move: ";
  if(testTopRightRightMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Top Right Up Move: ";
  if(testTopRightUpMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Top Right Down Move: ";
  if(testTopRightDownMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  return 0;
}

bool testCenterLeftMove() {

  // Setup
  MOVE left = MOVE::LEFT;
  int initialBoardConfig[]  = {1, 2, 3 ,4, 0, 5, 6, 7, 8};
  int expectedBoardConfig[] = {1, 2, 3 ,0, 4, 5, 6, 7, 8};
  Board testBoard{initialBoardConfig};
  Board expectedResult(expectedBoardConfig);

  // Action
  testBoard.move(left);

  // Test
  if(testBoard == expectedResult) {
    return true;
  }
  assert(false);
  return false;
}


bool testCenterRightMove() {
  // Setup
  MOVE right = MOVE::RIGHT;
  int initialBoardConfig[]  = {1, 2, 3 ,4, 0, 5, 6, 7, 8};
  int expectedBoardConfig[] = {1, 2, 3 ,4, 5, 0, 6, 7, 8};
  Board testBoard{initialBoardConfig};
  Board expectedResult(expectedBoardConfig);

  // Action
  testBoard.move(right);

  // Test
  if(testBoard == expectedResult) {
    return true;
  }
  assert(false);
  return false;
}

bool testCenterUpMove() {
  // Setup
  MOVE up = MOVE::UP;
  int initialBoardConfig[]  = {1, 2, 3, 4, 0, 5, 6, 7, 8};
  int expectedBoardConfig[] = {1, 0, 3, 4, 2, 5, 6, 7, 8};
  Board testBoard{initialBoardConfig};
  Board expectedResult(expectedBoardConfig);

  // Action
  testBoard.move(up);

  // Test
  if(testBoard == expectedResult) {
    return true;
  }
  assert(false);
  return false;
}


bool testCenterDownMove() {
  // Setup
  MOVE down = MOVE::DOWN;
  int initialBoardConfig[]  = {1, 2, 3, 4, 0, 5, 6, 7, 8};
  int expectedBoardConfig[] = {1, 2, 3, 4, 7, 5, 6, 0, 8};
  Board testBoard{initialBoardConfig};
  Board expectedResult(expectedBoardConfig);

  // Action
  testBoard.move(down);

  // Test
  if(testBoard == expectedResult) {
    return true;
  }
  assert(false);
  return false;
}


bool testTopRightLeftMove() {
  // Setup
  MOVE left = MOVE::LEFT;
  int initialBoardConfig[]  = {1, 2, 0, 4, 5, 3, 6, 7, 8};
  int expectedBoardConfig[] = {1, 0, 2, 4, 5, 3, 6, 7, 8};
  Board testBoard{initialBoardConfig};
  Board expectedResult(expectedBoardConfig);

  // Action
  testBoard.move(left);

  // Test
  if(testBoard == expectedResult) {
    return true;
  }
  assert(false);
  return false;
}


bool testTopRightRightMove() {
  // Setup
  MOVE right = MOVE::RIGHT;
  int initialBoardConfig[]  = {1, 2, 0, 4, 5, 3, 6, 7, 8};
  int expectedBoardConfig[] = {1, 2, 0, 4, 5, 3, 6, 7, 8};
  Board testBoard{initialBoardConfig};
  Board expectedResult(expectedBoardConfig);

  // Action
  testBoard.move(right);

  // Test
  if(testBoard == expectedResult) {
    return true;
  }
  assert(false);
  return false;
}


bool testTopRightUpMove() {
  // Setup
  MOVE up = MOVE::UP;
  int initialBoardConfig[]  = {1, 2, 0, 4, 5, 3, 6, 7, 8};
  int expectedBoardConfig[] = {1, 2, 0, 4, 5, 3, 6, 7, 8};
  Board testBoard{initialBoardConfig};
  Board expectedResult(expectedBoardConfig);

  // Action
  testBoard.move(up);

  // Test
  if(testBoard == expectedResult) {
    return true;
  }
  assert(false);
  return false;
}


bool testTopRightDownMove() {
  // Setup
  MOVE down = MOVE::DOWN;
  int initialBoardConfig[]  = {1, 2, 0, 4, 5, 3, 6, 7, 8};
  int expectedBoardConfig[] = {1, 2, 3, 4, 5, 0, 6, 7, 8};
  Board testBoard{initialBoardConfig};
  Board expectedResult(expectedBoardConfig);

  // Action
  testBoard.move(down);

  // Test
  if(testBoard == expectedResult) {
    return true;
  }
  assert(false);
  return false;
}