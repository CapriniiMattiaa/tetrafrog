#include <ncurses.h>
#include <unistd.h>

#include <iostream>

#include "Tetrimino.hpp"
#include "tools.h"

class NextTetriminoViewer {
 protected:
  WINDOW *w_next_tetrimino;

 public:
  NextTetriminoViewer() {
    this->w_next_tetrimino =
        newwin(TETRIMINO_MAX_WIDTH + 2, TETRIMINO_MAX_HEIGHT * 2 + 2, 22, 30);
    refresh();
  }
  void view(Tetrimino t);
  void gameover();
};