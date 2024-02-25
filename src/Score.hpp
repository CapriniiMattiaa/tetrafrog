#include <ncurses.h>
#include <unistd.h>

#include <iostream>

class Score {
 protected:
  int score;

 public:
  void viewScore();
};