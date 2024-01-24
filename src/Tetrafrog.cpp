#include "Tetrafrog.hpp"
#include "NextTetraminoViewer.hpp"

void Tetrafrog::startGame() {
  clear();
  int x = 10;
  int y = 2;

  // Set the coord correctly
  // game_map.getCenterCoord(x,y);

  this->game_map.InitializeMap();

  y += 1;
  mvprintw(y, x, "        o  o   o  o");
  y += 1;
  mvprintw(y, x, "        |\\/ \\^/ \\/|");
  y += 1;
  mvprintw(y, x, "        |,-------.|");
  y += 1;
  mvprintw(y, x, "      ,-.(|)   (|),-.");
  y += 1;
  mvprintw(y, x, "      \\_*._ ' '_.* _/");
  y += 1;
  mvprintw(y, x, "       /`-.`--' .-'\\");
  y += 1;
  mvprintw(y, x, "  ,--./    `---'    \\,--.");
  y += 1;
  mvprintw(y, x, "  \\   |(  )     (  )|   /");
  y += 1;
  mvprintw(y, x, "   \\  | ||       || |  /");
  y += 1;
  mvprintw(y, x, "    \\ | /|\\     /|\\ | /");
  y += 1;
  mvprintw(y, x, "    /  \\\\-._     _,-/  \\");
  y += 1;
  mvprintw(y, x, "   //| \\\\  `---'  // |\\");
  y += 1;
  mvprintw(y, x, "  /,-.,-.\\       /,-.,-.\\");
  y += 1;
  mvprintw(y, x, "  o   o   o      o   o    o");


  NextTetraminoViewer nxTrm;
  nxTrm.view();

  getch();
}
