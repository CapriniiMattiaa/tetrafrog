#include <ncurses.h>
#include <unistd.h>

#include <iostream>

class Score {
 protected:
  int score;

 public:
  Score() {}
  void viewScore();
};