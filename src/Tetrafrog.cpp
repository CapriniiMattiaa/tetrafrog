#include "Tetrafrog.hpp"

#include <ncurses.h>
#include <unistd.h>

void Tetrafrog::startGame() {
  clear();
  int x = 0;
  int y = 5;
  printw("(Schermata di gioco Bellissima)");

  y += 1;
  mvprintw(y, x, "         ()-()");
  y += 1;
  mvprintw(y, x, "      .-(___)-.");
  y += 1;
  mvprintw(y, x, "       _<   >_");
  y += 1;
  mvprintw(y, x, "       |      |");

  getch();
}
