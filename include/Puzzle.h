// File: Puzzle.h
// ---------------------
// Puzzle.h provides an abstraction for n-tile puzzle.

#pragma once

#include <vector>

//! Puzzle class.
/* 
Graphical representation of the puzzle. 
  -----------------
  |0,0|0,1|0,2|0,n|
  |---+---+---+---|
  |1,0|1,1|1,2|1,n|
  |---+---+---+---|
  |2,0|2,1|2,2|2,n|
  |---+---+---+---|
  |n,0|n,1|n,2|n,n|
  -----------------
*/

class Puzzle {
public:
  /*!
      Initialize a square shaped Puzzle with n tiles. 

      Note: if n+1 is not a perfect square then an error is thrown. 
  */ 
  Puzzle(unsigned int _tiles);

  /*!
      Initialze puzzle with n rows and m cols. 

      Note: This method constructor allows rectangle shaped Puzzles.
  */ 
  Puzzle(int _rows, _cols);

  /*!
      Creates a Puzzle with a user-defined tile configuration.

      Note: An error is thrown if the configuration is not a rectangle. 
  */
  Puzzle(vector<vector<int>> _tile_configuration);
  Puzzle(Puzzle _puzzle);
  ~Puzzle();

  vector<vector<int>> GetTileConfig();
  
  void Print();

  // Randomize tile configuration.
  void Randomize();

  // Swaps specified tile with "blank" tile. 
  // Return true if valid slide, otherwise false
  bool Slide(int row, int col);

  void operator =(const Puzzle& other);
  bool operator ==(const Board &other) const;

private:
  vector<vector<int>> tile_configuration_;
  pair<int> blank_tile_pos_;

  bool Validate();
};

#endif
