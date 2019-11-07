

#include "../include/Board.h"

#include <iostream>
#include <set>
#include <cassert>

bool testCenterLeftMove();
bool testCenterRightMove();
bool testCenterUpMove();
bool testCenterDownMove();

bool testTopRightLeftMove();
bool testTopRightRightMove();
bool testTopRightUpMove();
bool testTopRightDownMove();

bool testCenterRightDownMove();

bool testBottomLeftDownMove();

bool testEquality();
bool testInequality();

bool testBoardSet();

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

  cout << "Center Right Down Move: ";
  if(testCenterRightDownMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Bottom Left Down Move";
  if(testBottomLeftDownMove()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Equality Test: ";
  if(testEquality()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;

  cout << "Inequality Test: ";
  if(testInequality()) {
    cout << " Passed";
  } else {
    cout << " Failed";
  }
  cout << endl;
  
  cout << "Board Set Test: ";
  if(testBoardSet()) {
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

bool testCenterRightDownMove() {
  // Setup
  MOVE down = MOVE::DOWN;
  int initialBoardConfig[]  = {1, 2, 3, 
                               4, 5, 0, 
                               7, 8, 6};
  int expectedBoardConfig[] = {1, 2, 3, 
                               4, 5, 6, 
                               7, 8, 0};
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

bool testBottomLeftDownMove() {
  // Setup
  MOVE down = MOVE::DOWN;
  int initialBoardConfig[]  = {1, 2, 3, 
                               4, 5, 6, 
                               0, 7, 8};
  int expectedBoardConfig[] = {1, 2, 3, 
                               4, 5, 6, 
                               0, 7, 8};
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


bool testEquality() {
  int lhsBoardConfig[] = {1, 2, 3, 
                          4, 6, 0, 
                          7, 5, 8};
  int rhsBoardConfig[] = {1, 2, 3, 
                          4, 6, 0, 
                          7, 5, 8};
  Board lhsBoard(lhsBoardConfig);
  Board rhsBoard(rhsBoardConfig);

  return (lhsBoard == rhsBoard);
}


bool testInequality() {
  int lhsBoardConfig[] = {1, 2, 3, 
                          4, 6, 0, 
                          7, 5, 8};
  int rhsBoardConfig[] = {1, 2, 3, 
                          4, 0, 6, 
                          7, 5, 8};
  Board lhsBoard(lhsBoardConfig);
  Board rhsBoard(rhsBoardConfig);

  return !(lhsBoard == rhsBoard);
}


bool testBoardSet() {
  set<Board> setOfBoards;

  int boardConfig[] = {1, 2, 3, 
                       4, 6, 0, 
                       7, 5, 8};
  Board board(boardConfig);

  setOfBoards.insert(board);

  board.move(MOVE::UP);
  setOfBoards.insert(board);

  board.move(MOVE::DOWN);
  setOfBoards.insert(board);

  board.move(MOVE::LEFT);
  setOfBoards.insert(board);

  board.move(MOVE::RIGHT);
  setOfBoards.insert(board);

  return setOfBoards.count(board);
}