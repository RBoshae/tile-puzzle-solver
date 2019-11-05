#include "../include/Board.h"

#include <iostream>
#include <cassert>

int main() {
    Board boardA;
    Board boardB;

    int boardAConfig[] = {0,8,7,6,5,4,3,2,1};

    boardA.set(boardAConfig);

    cout << "Board A config" << endl;
    boardA.print();

    cout << endl;

    cout << "Board B config" << endl;
    boardB.print();

    cout << "Assigning Board A to Board B (boardB = boardA)." << endl;
    boardB = boardA;
    cout << "Board B config: " << endl;
    boardB.print();

}