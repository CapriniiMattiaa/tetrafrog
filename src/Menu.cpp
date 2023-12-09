#include "Menu.hpp"

#include <ncurses.h>
#include <unistd.h>

#include "Tetrafrog.hpp"

void Menu::getMaxCoord(int &x, int &y) {
  getmaxyx(stdscr, y, x);
  y = y - 1;
  x = x - 1;
}

void Menu::show() {
  getMaxCoord(x, y);
  x = x / 2 - 14;
  y /= 2;

  mvprintw(y, x, "(Schermata Principale bellissima)");
  y += 1;
  mvaddch(y, x, '>');

  printw("Play (Premi z)");
  while (getch() != 'z') {
    mvprintw(y + 10, x, "(Ho detto z idiota)");
  }

  Tetrafrog tetrafrog;
  tetrafrog.startGame();
}