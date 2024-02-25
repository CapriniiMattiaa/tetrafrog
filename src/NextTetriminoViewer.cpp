#include "NextTetriminoViewer.hpp"

#include <iostream>
using namespace std;

void NextTetriminoViewer::view(Tetrimino t) {
  /*
  int x = 30;
  int y = 22;

  y += 1;
  mvprintw(y, x, "Next Tetramino:");
  y += 1;
  mvprintw(y, x, "{|-------------|}");
  y += 1;
  mvprintw(y, x, "{|             |}");
  y += 1;
  mvprintw(y, x, "{|             |}");
  y += 1;
  mvprintw(y, x, "{|             |}");
  y += 1;
  mvprintw(y, x, "{|             |}");
  y += 1;
  mvprintw(y, x, "{|             |}");
  y += 1;
  mvprintw(y, x, "{|-------------|}");
  */

  for (int i = 0; i < TETRIMINO_MAX_WIDTH; i++) {
    for (int j = 0; j < TETRIMINO_MAX_HEIGHT; j++) {
      if (t.grid[i][j] == 1) {
        mvwprintw(this->w_next_tetrimino, i + 1, j * 2 + 1, "0");
      } else {
        mvwprintw(this->w_next_tetrimino, i + 1, j * 2 + 1, " ");
      }
    }
  }

  box(this->w_next_tetrimino, 0, 0);
  wrefresh(this->w_next_tetrimino);
}