#include "Score.hpp"

#include <iostream>
using namespace std;

Score::Score() { this->score = 0; }

void Score::viewScore() {
  int x = 30;
  int y = 20;

  std::string variabile = "score: " + std::to_string(this->score);
  mvprintw(y, x, "%s", variabile.c_str());
}