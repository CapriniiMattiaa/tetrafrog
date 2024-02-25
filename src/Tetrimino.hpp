#ifndef tetrim
#define tetrim

#include "tools.h"

class Tetrimino {
 protected:
 public:
  int grid[TETRIMINO_MAX_WIDTH][TETRIMINO_MAX_HEIGHT] = {{0}};
  void build();
};

#endif