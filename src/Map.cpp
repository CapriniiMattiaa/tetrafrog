#include "Map.hpp"

void Map::getCenterCoord(int &x, int &y) {
  getmaxyx(stdscr, y, x);
  y = y / 2 - 1;
  x = x / 2 - 1;
}

bool Map::gameOver() {

bool toReturn = true;

for(int i = 0; i<rows_grid;i++){
for(int j = 0; j<columns_grid;j++){

  if(this->grid[i][j] == 3)
  {
    toReturn = false;


  }
}
}

return toReturn;

}
void Map::print_Tetriminos(int color_code) {
  start_color();

    init_pair(1, 7, 7);  
    init_pair(2, color_code, color_code);  


  for (int i = 0; i < rows_grid; i++) {
    for (int j = 0; j < columns_grid; j++) {
      if (this->grid[i][j] == 1){

        wattron(main_grid, COLOR_PAIR(2));
        mvwprintw(main_grid, i, j * 2 + 2, "0");
        mvwprintw(main_grid, i, j * 2 + 3, "0");

        wattroff(main_grid, COLOR_PAIR(2));


      } else if (this->grid[i][j] == 2) {

        wattron(main_grid, COLOR_PAIR(1));
        mvwprintw(main_grid, i, j * 2 + 2, "0");
        mvwprintw(main_grid, i, j * 2 + 3, "0");

        wattroff(main_grid, COLOR_PAIR(1));
      } else {
        mvwprintw(main_grid, i, j * 2 + 2, " ");
      }
    }
  }

  wrefresh(main_grid);
}

void Map::PinMap() {
  for (int i = rows_grid - 1; i >= 0; i--) {
    for (int j = columns_grid - 1; j >= 0; j--) {
      if (this->grid[i][j] == 1) {
        this->grid[i][j] = 2;
      }
    }
  }
}

bool Map::PinTetriminos() {
  bool pinned = false;
  for (int i = rows_grid - 1; i >= 0 && !pinned; i--) {
    for (int j = columns_grid - 1; j >= 0 && !pinned; j--) {
      if (this->grid[i][j] == 1) {
        if (i == rows_grid - 1) {
          PinMap();
          pinned = true;
        } else {
          if (this->grid[i + 1][j] == 2) {
            PinMap();
            pinned = true;
          }
        }
      }
    }
  }
  return pinned;
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

bool Map::Check_If_PossibleR() {
  bool toReturn = true;

  for (int i = 0; i < rows_grid && toReturn; i++) {
    if (this->grid[i][columns_grid - 1] == 1) {

      toReturn = false;
    } else {
      for (int j = 0; j < columns_grid - 1 && toReturn; j++) {
        if (this->grid[i][j] == 1) {
          if (this->grid[i][j + 1] == 2) {
            toReturn = false;
          }
        }
      }
    }
  }
  return toReturn;
}

bool Map::Check_If_PossibleL() {
  bool toReturn = true;

  for (int i = 0; i < rows_grid && toReturn; i++) {
    if (this->grid[i][0] == 1) {
      toReturn = false;
    } else {
      for (int j = 1; j < columns_grid && toReturn; j++) {
        if (this->grid[i][j] == 1) {
          if (this->grid[i][j - 1] == 2) {
            toReturn = false;
          }
        }
      }
    }
  }
  return toReturn;
}

void Map::move_Left() {
  if (Check_If_PossibleL()) {
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
}

void Map::move_Right() {
  if (Check_If_PossibleR()) {
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

//----

void Map::spawnTetrimino(Tetrimino t) {
  int wcindex = 4;
  for (int i = 0; i < TETRIMINO_MAX_WIDTH; i++) {
    for (int j = 0; j < TETRIMINO_MAX_HEIGHT; j++) {
      // NOTA BENE: += perché così capiamo in fretta se è game over
      // infatti se è già presente un pezzo fisso (2) ci sarà una cella
      // di valore 3 --> in tal caso game over
      this->grid[i][wcindex + j] += t.grid[i][j];
    }
  }
}

bool Map::checkLine(int row_index) {
  bool twos = true;
  for (int i = 0; i < columns_grid && twos; i++)
    if (grid[row_index][i] != 2) twos = false;
  return twos;
}

void Map::translateGrid(int index, int num) {
  for (int i = index; i >= num; i--) {
    for (int j = 0; j < columns_grid; j++) {
      // Copia il valore di grid[i][j] a grid[i+num][j]
      grid[i][j] = grid[i - num][j];
      // Metti il valore di grid[i][j] a 0
      grid[i - num][j] = 0;
    }
  }
}

int Map::checkAndDeleteLine() {
  // Segnati l'indice della prima riga dal basso che è composta da 2
  // Quindi conta quante righe composte da soli 2 ci sono
  int first_index = -1;
  int counter = 0;
  for (int i = rows_grid - 1; i >= 0; i--) {
    if (checkLine(i)) {
      if (first_index == -1) {
        first_index = i;
      }
      counter++;
    }
  }
  // Allora trasla tutto ciò che è sopra l'indice della prima riga all'indice
  // della riga
  if (first_index != -1) {
    translateGrid(first_index, counter);
  }
  return counter;
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
