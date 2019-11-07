#include "../include/Node.h"

bool testNodeCompare();

int main() {

  testNodeCompare() ? cout << "testNodeCompare pass" : cout << "testNodeCompareFail";
  cout << endl;

  return 0;
}


bool testNodeCompare() {
  Node lesserNode;
  Node greaterNode;

  lesserNode.setPathCost(4);
  greaterNode.setHeuristcCost(10);

  return lesserNode < greaterNode;
}

