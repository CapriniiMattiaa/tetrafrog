#include <ncurses.h>
#include <unistd.h>

#include "Menu.hpp"
#include "tools.h"

int main() {
  srand(time(NULL));

  initscr();

  Menu menu;
  menu.show();

  endwin();

  return 0;
}
