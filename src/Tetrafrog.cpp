#include "Tetrafrog.hpp"

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

Tetrimino Tetrafrog::generateTetrimino() {
  int num = random_range(0, 6);
  if (num == 0) {
    I i = I();
    i.build();
    return i;
  } else if (num == 1) {
    J j = J();
    j.build();
    return j;
  } else if (num == 2) {
    L l = L();
    l.build();
    return l;
  } else if (num == 3) {
    O o = O();
    o.build();
    return o;
  } else if (num == 4) {
    S s = S();
    s.build();
    return s;
  } else if (num == 5) {
    T t = T();
    t.build();
    return t;
  } else if (num == 6) {
    Z z = Z();
    z.build();
    return z;
  }
}

void Tetrafrog::startGame() {
  clear();
  printFrog();
  this->game_map.InitializeMap();
  this->game_map.spawnTetrimino(generateTetrimino());
  this->game_map.print_Tetriminos();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);  // Funzione ncurses che non ferma il gioco se //
                          // invocate funzione con interrupt(getch)

  // Loop di gioco
  Tetrimino nextTetrimino = generateTetrimino();
  long int downCounter = 0;
  bool gameLoop = true;
  while (gameLoop) {  // IpoteticaFunzioneCheDiceSeGiocoFinito
    // Verifica se c'è una linea completa (composta da 2)
    this->game_map.checkAndDeleteLine();

    // Gestione movimenti
    int c = getch();
    if (c == KEY_RIGHT) {
      this->game_map.move_Right();
    }
    if (c == KEY_LEFT) {
      this->game_map.move_Left();
    }

    bool Spawn = false;

    if (downCounter == 0) {
      this->game_map.move_down();
      Spawn = this->game_map.PinTetriminos();
    }
    downCounter++;
    downCounter %= 5000;
    // Fisso Tetrimini setto Spawn

    // Esempio di passaggio al Tetrimino successivo
    if (Spawn) {
      this->game_map.spawnTetrimino(nextTetrimino);
      nextTetrimino = generateTetrimino();
    }

    // Gestione grafica
    this->game_map.print_Map();
    this->game_map.print_Tetriminos();
    this->score.viewScore();
    this->ntv.view(nextTetrimino);
  }

  getch();
}
