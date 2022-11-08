# Sliding Puzzle Solver Using A*

In this project I implement the A* search algorithm, using C++ to solve any
sliding tile puzzle. 

## Approach

To solve this problem, I use nodes to contain the state of each puzzle. Nodes
are connected based on the next possible state of a puzzle. The overarching
concept is to traverse the graph until the goal state aka a solution is found.

This is where A* comes in. The A* search algorithm is used because it is the
best known path-finding and graph traversal algorithm. A* is both optimal and
complete. 

In essence, A* works by assigning a cost to each node encountered. The node
with the cheapest cost is and selected to expand, generating the next potential
states.

The cost of a node is calculated by summing the cost to reach the node, *g(n)*,
and cost of the heuristic *h(n)). The heuristic cost is the value assigned to
get from the node being considerred to the goal node. 

In this project we'll use two heuristics. The first heuristic is the
manhattan distance. The manhattan distance is calculated by how far away a tile
is from it's desired location. The second heuristic is based on the number of
misplaced tiles.

If you discard the heuristic component, the algorithm becomes a
Uniform-Cost-Search.

## Getting Started

These instructions will get you a copy of the project up and running on your 
local machine for development and testing purposes.

### Prerequisites

To run this code you need g++ (or your favorite C++ compiler) installed on your 
machine. For instructions on how to install g++ please refer to this 
[video link.](https://www.youtube.com/watch?v=8Ib7nwc33uA)

### Installing

Once the compiler has been installed on your machine you are ready to run the 
program.

Start by opening a terminal. Next, navigate to the project directory and enter 
"make" to compile the code:

```
make
```

Next, navigate to the bin folder and run the program:

```
cd bin/
./puzzle_solver
```

Follow the program interface and enjoy.

To halt the program press ctrl-c

```
ctrl-c
```
## Running the tests

Follow the interface to enter custom puzzles. When a solution is found the 
program returns the solution trace, otherwise the program returns indicates 
there is no solution.

## Author

* **Rick Boshae** - [Personal Website](https://rboshae.github.io)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file 
for details

## Acknowledgments

* Dr. Niloofar Montazeri

## Resources

* [Artificial Intelligence: A Modern Approach 3rd Ed](http://aima.cs.berkeley.edu/) by [Stuart Russell](https://people.eecs.berkeley.edu/~russell/) and [Peter Norvig](http://www.norvig.com/)
