#include "NextTetriminoViewer.hpp"

#include <iostream>
using namespace std;

void NextTetriminoViewer::view() {
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
}