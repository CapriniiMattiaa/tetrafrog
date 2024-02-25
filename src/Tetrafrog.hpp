#include <ncurses.h>
#include <unistd.h>

#include "Map.hpp"
#include "NextTetraminoViewer.hpp"
#include "Score.hpp"

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