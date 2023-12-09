#include "Tetrafrog.hpp"

#include <ncurses.h>
#include <unistd.h>

#include <fstream>
#include <iostream>

using namespace std;

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
}

void Tetrafrog::addScore(int score) {
  ofstream fout;
  fout.open("./Leaderboard.txt", ios::app);

  fout << score << endl;

  fout.close();
}