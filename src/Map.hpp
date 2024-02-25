#include <chrono>
#include <thread>
using namespace std;

#include <ncurses.h>
#include <unistd.h>

#include "Tetrimino.hpp"
#include "tools.h"

class Map {
 protected:
  int window_size_rows = rows_grid + 1;
  int window_size_columns = columns_grid * 2 + 4;
  int grid[rows_grid][columns_grid];
  WINDOW *main_grid;

 public:
  void getCenterCoord(int &x, int &y);
  void InitializeMap();
  void move_down();
  bool Check_If_PossibleL();
  bool Check_If_PossibleR();
  void start_movement();
  void InitializeGrid();
  void spawnTetrimino(Tetrimino t);
  void print_Map();
  void print_Tetriminos();
  void move_Right();
  void move_Left();
  WINDOW *getW();
};
