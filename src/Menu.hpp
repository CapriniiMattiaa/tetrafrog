#include <ncurses.h>
#include <unistd.h>

#include "Leaderboard.hpp"
#include "Tetrafrog.hpp"
#include "tools.h"

class Menu {
 protected:
  int x;
  int y;
  WINDOW *w_leaderboard;

  void getMaxCoord(int &x, int &y);
  void showLeaderboard();

 public:
  void show();
};