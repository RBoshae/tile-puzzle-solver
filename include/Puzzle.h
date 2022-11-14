// File: Puzzle.h
// ---------------------
// Puzzle.h provides an abstraction for n-tile puzzle.

#pragma once

#include <vector>

class Puzzle
{
public:
  Puzzle();

  // Creates a Puzzle with a user-defined tile configuration.
  Puzzle(vector<vector<int>> _tile_configuration);
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
};

#endif
