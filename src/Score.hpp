#include <ncurses.h>
#include <unistd.h>

#include <iostream>

class Score {
 protected:
  int score;

 public:
  Score() { this->score = 0; }
  void viewScore();
};