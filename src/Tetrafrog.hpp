#include <ncurses.h>
#include <unistd.h>

#include "Map.hpp"
#include "NextTetriminoViewer.hpp"
#include "Score.hpp"
#include "Tetrimino.hpp"
#include "tetriminos/I.hpp"
#include "tetriminos/J.hpp"
#include "tetriminos/L.hpp"
#include "tetriminos/O.hpp"
#include "tetriminos/S.hpp"
#include "tetriminos/T.hpp"
#include "tetriminos/Z.hpp"
#include "tools.h"

class Tetrafrog {
 protected:
  Map game_map;
  Score score;
  NextTetriminoViewer ntv;

  void printFrog();
  Tetrimino generateTetrimino();

 public:
  Tetrafrog() {
    this->game_map = Map();
    this->score = Score();
    this->ntv = NextTetriminoViewer();
  }
  void startGame();
};