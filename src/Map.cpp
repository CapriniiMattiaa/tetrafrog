#include "Map.hpp"

void Map::getCenterCoord(int &x, int &y) {
  getmaxyx(stdscr, y, x);
  y = y / 2 - 1;
  x = x / 2 - 1;
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

void Map::InitializeGrid() {
  for (int i = 0; i < rows_grid; i++) {
    for (int j = 0; j < columns_grid; j++) {
      grid[i][j] = 0;
    }
  }
}

void Map::InitializeMap() {
  InitializeGrid();  // Setta la griglia a 0

  int x,y;
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
