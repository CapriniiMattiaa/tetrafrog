#include <iostream>
#include <ncurses.h>
using namespace std;

int main() {
  initscr();

  printw("SUS");
  
  int d = getch();


  printw("%d", d);
  printw("%d", d+1);

  getch();

  endwin();
}