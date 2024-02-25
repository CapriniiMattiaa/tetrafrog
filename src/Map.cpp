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

void Map::print_Map(int rows, int columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (j == 0) {
        mvwprintw(main_grid, i, j, "{");
      } else if (j == columns - 1) {
        mvwprintw(main_grid, i, j, "}");
      } else if (j == 1 || j == columns - 2) {
        mvwprintw(main_grid, i, j, "|");
      } else {
        if (i == rows - 1) {
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
void Map::move_Right()  // Cicli al contrario per Spostare senza problemi
{
  for (int i = rows_grid - 1; i >= 0; i--)  // Parto da row-1

    for (int i = rows_grid - 1; i >= 0; i--)  // Parto da row-1
    {
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
    for (int i = rows_grid - 1; i > 0; --i) {
      if (grid[i][j] == 1 && grid[i - 1][j] == 0) {
        grid[i][j] = 0;
        grid[i - 1][j] = 1;
      }
    }
  }
}
void Map::start_movement() {
  while (true) {
    move_down();                                     // down movement
    print_Map(rows_grid + 1, columns_grid * 2 + 4);  // print map after movement
    this_thread::sleep_for(
        chrono::seconds(1));  // wait one second before movement
  }
}

//----

void Map::InitializeGrid() {
  for (int i = 0; i < rows_grid; i++) {
    for (int j = 0; j < columns_grid; j++) {
      grid[i][j] = 0;
    }
  }
  grid[5][5] = 1;
  grid[5][6] = 1;
  grid[6][5] = 1;
  grid[6][6] = 1;
}

void Map::InitializeMap() {
  InitializeGrid();  // Setta la griglia a 0

  int x, y;
  // Prendo la posizine dove andra la finestra e quindi la griglia
  getCenterCoord(x, y);

  x = x - 12;
  y = y - 10;

  // Prendo la grandezza della griglia != dalla grandezza della matrice griglia
  int window_Size_rows = rows_grid + 1;            // Add the base of the grid
  int window_Size_columns = columns_grid * 2 + 4;  // Add the lateral edges

  main_grid = newwin(window_Size_rows, window_Size_columns, y, x);
  refresh();
  // Stampo la griglia
  print_Map(window_Size_rows, window_Size_columns);

  wrefresh(main_grid);

  refresh();
}
