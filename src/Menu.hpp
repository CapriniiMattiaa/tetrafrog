#include <ncurses.h>
#include <unistd.h>

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