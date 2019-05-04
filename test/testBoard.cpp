#include <iostream>
#include "../include/Board.h"

int main() {

  MOVE ALL_MOVES[] = {MOVE::UP, MOVE::DOWN, MOVE::LEFT, MOVE::RIGHT};

  int boardConfig[] = {1, 2, 3 ,4, 0, 5, 6, 7, 8};
  Board testBoard{boardConfig};

  cout << "Initial test board configuration:" << endl;

  testBoard.print();
  cout << endl;

  for (auto action : ALL_MOVES) {


    if(testBoard.move(action)) cout << "Move applied." << endl;
    testBoard.print();
    cout << endl;
  }


  return 0;
}
