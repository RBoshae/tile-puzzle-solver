# Sliding Puzzle Solver Using A*

In this project I implement the A* search algorithm using C++. A* is the best 
path-finding and graph traversal algorithm because it is both optimal and 
complete. A* evaluates nodes by estimating the cost of the cheapest solution 
through *n*. The cheapest solution is estimated by summing the cost to reach 
the node, *g(n)*, and the cost to get from the node to the goal, *h(n)*. 

If you discard the *h(n)* component, the algorithm acts the same as a 
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
