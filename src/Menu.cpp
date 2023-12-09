#include "Menu.hpp"

#include <ncurses.h>
#include <unistd.h>

#include "Leaderboard.hpp"
#include "Tetrafrog.hpp"

void Menu::getMaxCoord(int &x, int &y) {
  getmaxyx(stdscr, y, x);
  y = y - 1;
  x = x - 1;
}

void Menu::showLeaderboard() {
  int scores[10];
  Leaderboard leaderboard;
  leaderboard.getFirstTen(scores);

  if (scores[0] == -1) printw("Classifica vuota!");

  for (int i = 0; i < 10; i++) printw(to_string(scores[i]).c_str());
}

void Menu::show() {
  getMaxCoord(x, y);
  x = x / 2 - 14;
  y /= 2;

  mvprintw(y, x, "(Schermata Principale bellissima)");
  y += 1;
  mvaddch(y, x, '>');

  showLeaderboard();

  printw("Play (Premi z)");
  while (getch() != 'z') {
    mvprintw(y + 10, x, "(Ho detto z idiota)");
  }

  Tetrafrog tetrafrog;
  tetrafrog.startGame();
}