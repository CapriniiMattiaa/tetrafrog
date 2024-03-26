#include "NextTetriminoViewer.hpp"

#include <iostream>
using namespace std;

void NextTetriminoViewer::gameover() {

printw("gameover:()");


}
void NextTetriminoViewer::view(Tetrimino t) {
  start_color();
  init_pair(1, 7, 7);

  for (int i = 0; i < TETRIMINO_MAX_WIDTH; i++) {
    for (int j = 0; j < TETRIMINO_MAX_HEIGHT; j++) {
      if (t.grid[i][j] == 1) {
        wattron(this->w_next_tetrimino, COLOR_PAIR(1));
        mvwprintw(this->w_next_tetrimino, i+1, j * 2 + 1, "0");
        mvwprintw(this->w_next_tetrimino, i+1, j * 2 + 2, "0");
        wattroff(this->w_next_tetrimino, COLOR_PAIR(1));
      } else {
        mvwprintw(this->w_next_tetrimino, i+1, j * 2 + 1, " ");
        mvwprintw(this->w_next_tetrimino, i+1, j * 2 + 2, " ");
        
      }
    }
  }

  box(this->w_next_tetrimino, 0, 0);
  wrefresh(this->w_next_tetrimino);
}