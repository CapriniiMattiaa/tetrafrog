#include "tools.h"
#include <ncurses.h>
void getMaxCoord(int &x, int &y) {
  getmaxyx(stdscr, y, x);
  y = y - 1;
  x = x - 1;
}
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void selection_sort_reverted(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int selected = i;
    for (int j = i + 1; j < n; j++) {
      if (v[j] > v[selected]) selected = j;
    }
    if (selected != i) swap(v[i], v[selected]);
  }
}

int random_range(int min, int max) { return rand() % (max - min + 1) + min; }