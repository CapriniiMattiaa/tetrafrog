#include <ncurses.h>
#include <unistd.h>

#include "Menu.hpp"

int main() {
  initscr();

  Menu menu;
  menu.show();

  endwin();

  return 0;
}
