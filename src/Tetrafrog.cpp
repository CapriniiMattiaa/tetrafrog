#include "Tetrafrog.hpp"

Tetrafrog::Tetrafrog() {
  this->game_map = Map();
  this->score = Score();
  this->ntv = NextTetraminoViewer();
}

void Tetrafrog::printFrog() {
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
}

void Tetrafrog::startGame() {
  clear();
  printFrog();
  this->game_map.InitializeMap();
  this->game_map.print_Tetriminos();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);  // Funzione ncurses che non ferma il gioco se //
                          // invocate funzione con interrupt(getch)

  // Loop di gioco
  bool gameLoop = true;
  while (gameLoop) {  // IpoteticaFunzioneCheDiceSeGiocoFinito
    // Gestione movimenti
    int c = getch();
    if (c == KEY_RIGHT) {
      this->game_map.move_Right();
    }
    if (c == KEY_LEFT) {
      this->game_map.move_Left();
    }

    // Gestione grafica
    this->game_map.print_Map();
    this->game_map.print_Tetriminos();
    this->score.viewScore();
    this->ntv.view();
  }

  getch();
}
