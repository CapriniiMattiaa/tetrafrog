#include "tools.h"

class Tetrimino {
 protected:
  int grid[TETRIMINO_MAX_WIDTH][TETRIMINO_MAX_HEIGHT] = {{0}};

 public:
  void build();
};