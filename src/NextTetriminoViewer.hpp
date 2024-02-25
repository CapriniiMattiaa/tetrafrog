#include <ncurses.h>
#include <unistd.h>

#include <iostream>

class NextTetriminoViewer {
 protected:
  WINDOW *w_next_tetrimino;

 public:
  NextTetriminoViewer() {}
  void view();
};