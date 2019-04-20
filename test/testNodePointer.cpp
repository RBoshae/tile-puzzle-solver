#include <iostream>
#include <vector>

int main ()
{
  struct Node {
    Node* parent;
    int nodeNumber;
  };

  // Place the nodes into a vector<>.
  std::vector<Node> vNodes;

  // Create node pointers
  Node *ptrNode;
  Node *ptrAnotherNode;

  for (unsigned int i = 0; i < 5; i++ )
  {
    Node testNode;
    testNode.nodeNumber = i;

    vNodes.push_back(testNode);

    if ( i == 1 ) {
      ptrNode = &testNode;
      ptrAnotherNode = &vNodes.at(i);
    }
  }

  std::cout << "Accessing vector of nodes." << std::endl;
  for (unsigned int i = 0; i < vNodes.size(); i++)
  {
    std::cout << "Node " << i << ": " << vNodes[i].nodeNumber << std::endl;
  }

  // Access the nodes via a pointer.
  std::cout << "Accessing pointer nodes." << std::endl;
  std::cout << "ptrNode 1: " << ptrNode->nodeNumber << std::endl;
  std::cout << "ptrAnotherNode 1: " << ptrAnotherNode->nodeNumber << std::endl;

  return 0;
}
