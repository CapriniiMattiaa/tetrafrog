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
  void PinMap();

  bool Check_If_PossibleL();
  bool Check_If_PossibleR();
  bool checkLine(int row_index);
  void translateGrid(int index, int num);

 public:
  void getCenterCoord(int &x, int &y);
  void InitializeMap();
  void move_down();
  void start_movement();
  void InitializeGrid();
  void spawnTetrimino(Tetrimino t);
  void print_Map();
  bool gameOver();

  void print_Tetriminos();
  void move_Right();
  void move_Left();
  bool PinTetriminos();
  int checkAndDeleteLine();
  WINDOW *getW();
};
