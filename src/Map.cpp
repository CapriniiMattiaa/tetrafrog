#include "Map.hpp"

void Map::getCenterCoord(int &x, int &y) {
  getmaxyx(stdscr, y, x);
  y = y / 2 - 1;
  x = x / 2 - 1;
}

void Map::print_Tetriminos() {
  for (int i = 0; i < rows_grid; i++) {
    for (int j = 0; j < columns_grid; j++) {
      if (this->grid[i][j] == 1 || this->grid[i][j] == 2) {
        mvwprintw(main_grid, i, j * 2 + 2, "0");
      } else {
        mvwprintw(main_grid, i, j * 2 + 2, " ");
      }
    }
  }
  wrefresh(main_grid);
}

void Map::print_Map() {
  for (int i = 0; i < window_size_rows; i++) {
    for (int j = 0; j < window_size_columns; j++) {
      if (j == 0) {
        mvwprintw(main_grid, i, j, "{");
      } else if (j == window_size_columns - 1) {
        mvwprintw(main_grid, i, j, "}");
      } else if (j == 1 || j == window_size_columns - 2) {
        mvwprintw(main_grid, i, j, "|");
      } else {
        if (i == window_size_rows - 1) {
          mvwprintw(main_grid, i, j, "-");
        } else {
          mvwprintw(main_grid, i, j, " ");
        }
      }
    }
  }
}

WINDOW *Map::getW() { return main_grid; }

void Map::move_Left() {
  // FIXME: deve prima verificare se è possibile muovere l'intero pezzo a
  // sinistra
  for (int i = 0; i < rows_grid; i++) {
    for (int j = 0; j < columns_grid; j++) {
      if (this->grid[i][j] == 1) {
        if (j != 0) {
          this->grid[i][j] = 0;
          this->grid[i][j - 1] = 1;
        } else {
          j = columns_grid;  // BREAK
        }
      }
    }
  }
}

void Map::move_Right() {
  // Cicli al contrario per Spostare senza problemi
  // FIXME: deve prima verificare se è possibile muovere
  // l'intero pezzo a destra
  for (int i = rows_grid - 1; i >= 0; i--) {  // Parto da row-1
    for (int j = columns_grid - 1; j >= 0; j--) {
      if (this->grid[i][j] == 1) {
        if (j != columns_grid - 1) {
          this->grid[i][j] = 0;
          this->grid[i][j + 1] = 1;
        } else {
          j = -1;  // BREAK
        }
      }
    }
  }
}

//----

void Map::move_down() {
  for (int j = 0; j < columns_grid; ++j) {
    for (int i = rows_grid - 1; i >= 0; --i) {
      if (grid[i][j] == 1 && grid[i + 1][j] == 0) {
        grid[i][j] = 0;
        grid[i + 1][j] = 1;
      }
    }
  }
}

void Map::start_movement() {
  while (true) {
    move_down();         // down movement
    print_Tetriminos();  // print tetriminos after movement
    this_thread::sleep_for(
        chrono::seconds(1));  // wait one second before movement
  }
}

//----

void Map::spawnTetrimino(Tetrimino t) {
  int wcindex = 3;
  for (int i = 0; i < TETRIMINO_MAX_WIDTH; i++) {
    for (int j = 0; j < TETRIMINO_MAX_HEIGHT; j++) {
      // NOTA BENE: += perché così capiamo in fretta se è game over
      // infatti se è già presente un pezzo fisso (2) ci sarà una cella
      // di valore 3 --> in tal caso game over
      this->grid[i][wcindex + j] += t.grid[i][j];
    }
  }
}

void Map::InitializeGrid() {
  for (int i = 0; i < rows_grid; i++) {
    for (int j = 0; j < columns_grid; j++) {
      grid[i][j] = 0;
    }
  }
  /*grid[5][5] = 1;
  grid[5][6] = 1;
  grid[6][5] = 1;
  grid[6][6] = 1;*/
}

void Map::InitializeMap() {
  InitializeGrid();  // Setta la griglia a 0

  start_movement();
  
  int x, y;
  // Prendo la posizine dove andra la finestra e quindi la griglia
  getCenterCoord(x, y);

  x = x - 12;
  y = y - 10;

  main_grid = newwin(window_size_rows, window_size_columns, y, x);
  refresh();

  // Stampo la griglia
  print_Map();

  wrefresh(main_grid);

  refresh();
}
