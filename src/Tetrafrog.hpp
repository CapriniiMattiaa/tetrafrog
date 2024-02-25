#include <ncurses.h>
#include <unistd.h>

#include "Map.hpp"
#include "NextTetriminoViewer.hpp"
#include "Score.hpp"

class Tetrafrog {
 protected:
  Map game_map;
  Score score;
  NextTetriminoViewer ntv;

 public:
  Tetrafrog() {
    this->game_map = Map();
    this->score = Score();
    this->ntv = NextTetriminoViewer();
  }
  void printFrog();
  void startGame();
};