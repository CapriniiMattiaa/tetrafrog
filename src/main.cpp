#include <ncurses.h>
#include <unistd.h>

#include "Menu.hpp"
#include "tools.h"

int main() {
  srand(time(NULL));
  initscr();
curs_set(0);
  Menu menu;
  menu.show();

  endwin();

  return 0;
}
