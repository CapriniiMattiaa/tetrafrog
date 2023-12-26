#include <ncurses.h>
#include <unistd.h>

#include "Map.hpp"

class Tetrafrog {
 protected:
  Map game_map;

 public:
  void startGame();
};