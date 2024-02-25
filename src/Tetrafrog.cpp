#include "Tetrafrog.hpp"

#include "NextTetraminoViewer.hpp"
#include "Score.hpp"

void Tetrafrog::startGame() {
  clear();
  int x = 10;
  int y = 2;

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
  mvprintw(y, x, "  o   o   o      o   o    o(Press A toExit)");

  this->game_map.InitializeMap();

  NextTetraminoViewer nxTrm;
  nxTrm.view();

  Score scr;
  scr.viewScore(32);  // fake score

  this->game_map.print_Tetriminos();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);  // Funzione ncurses che non ferma il gioco se invocate
                          // funzione con interrupt(getch)
  while (getch() != 'A') {  // IpoteticaFunzioneCheDiceSeGiocoFinito
    this->game_map.start_movement();
    if (getch() == KEY_RIGHT) {
      this->game_map.move_Right();
    }
    if (getch() == KEY_LEFT) {
      this->game_map.move_Left();
    }
    this->game_map.print_Tetriminos();
  }

  getch();
}
