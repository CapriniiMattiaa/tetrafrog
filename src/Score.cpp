#include "Score.hpp"

#include <iostream>
using namespace std;

void Score::viewScore() {
  int x = 30;
  int y = 20;

  std::string variabile = "score: " + std::to_string(this->score);
  mvprintw(y, x, "%s", variabile.c_str());
}