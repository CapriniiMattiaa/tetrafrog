#include <ncurses.h>
#include <unistd.h>

#include "tools.h"

class Map {
 protected:
  int grid[rows_grid][columns_grid];
  WINDOW *main_grid;

 public:
  void getCenterCoord(int &x, int &y);
  void InitializeMap();
  void InitializeGrid();
  void print_Map(int rows, int columns);
};
