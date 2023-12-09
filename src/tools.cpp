#include "tools.h"

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