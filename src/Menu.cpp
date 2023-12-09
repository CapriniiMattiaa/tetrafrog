#include "Menu.hpp"

#include "Leaderboard.hpp"
#include "Tetrafrog.hpp"
#include "tools.h"

void Menu::getMaxCoord(int &x, int &y) {
  getmaxyx(stdscr, y, x);
  y = y - 1;
  x = x - 1;
}

void Menu::showLeaderboard() {
  this->w_leaderboard = newwin(NUM_SCORES_IN_LEADERBOARD + 2,
                               MAX_DIGIT_SCORE + 8, this->y, this->x);
  refresh();
  box(this->w_leaderboard, 0, 0);

  int scores[NUM_SCORES_IN_LEADERBOARD];
  fill_n(scores, NUM_SCORES_IN_LEADERBOARD, -1);

  Leaderboard leaderboard;
  leaderboard.getFirstTen(scores);

  if (scores[0] == -1)
    wprintw(this->w_leaderboard, "Classifica vuota!");
  else {
    wprintw(this->w_leaderboard, "Classifica");
    for (int i = 0; i < NUM_SCORES_IN_LEADERBOARD; i++)
      if (scores[i] != -1)
        mvwprintw(this->w_leaderboard, i + 1, 1, to_string(scores[i]).c_str());
  }

  wrefresh(this->w_leaderboard);
}

void Menu::show() {
  getMaxCoord(this->x, this->y);
  this->x = this->x / 2 - 14;
  this->y /= 4;

  mvprintw(this->y, this->x, "Benvenuto su Tetrafrog!");

  this->y++;
  this->x += 2;
  showLeaderboard();

  this->y += NUM_SCORES_IN_LEADERBOARD + 2;
  mvaddch(this->y, this->x, '>');
  printw("Play (premi z)");

  while (getch() != 'z') {
    mvprintw(this->y + 10, this->x, "(Ho detto z idiota)");
  }

  Tetrafrog tetrafrog;
  tetrafrog.startGame();
}