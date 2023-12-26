#include "Tetrafrog.hpp"

void Tetrafrog::startGame() {
  clear();
  int x = 0;
  int y = 5;

  // Set the coord correctly
  // game_map.getCenterCoord(x,y);

  this->game_map.InitializeMap(x, y);

  y += 1;
  mvprintw(y, x, "         ()-()");
  y += 1;
  mvprintw(y, x, "      .-(___)-.");
  y += 1;
  mvprintw(y, x, "       _<   >_");
  y += 1;
  mvprintw(y, x, "       |      |");

  getch();
}
