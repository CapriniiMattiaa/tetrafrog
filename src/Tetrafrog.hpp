#include <ncurses.h>
#include <unistd.h>

#include "Map.hpp"

class Tetrafrog {
 protected:
  Map game_map;
  Score score;
  NextTetraminoViewer ntv;

 public:
  Tetrafrog() {}
  void printFrog();
  void startGame();
};