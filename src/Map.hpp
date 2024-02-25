#include <chrono>
#include <thread>
using namespace std;

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
  void move_down();
  void start_movement();
  void InitializeGrid();
  void print_Map(int rows, int columns);
  void print_Tetriminos();
  void move_Right();
  void move_Left();
  WINDOW *getW();
};
