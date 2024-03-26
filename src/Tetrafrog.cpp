#include "Tetrafrog.hpp"
#include <cstdlib>

using namespace std;

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

Tetrimino Tetrafrog::rotation(Tetrimino block) {
  Tetrimino rotatedBlock = block; // Copia il tetrimino originale 

  // Effettua la trasposizione della matrice
  for (int i = 0; i < TETRIMINO_MAX_WIDTH; ++i) {
      for (int j = i + 1; j < TETRIMINO_MAX_HEIGHT; ++j) {
          swap(rotatedBlock.grid[i][j], rotatedBlock.grid[j][i]);
      }
  }

  // Rifletti la matrice orizzontalmente
  for (int i = 0; i < TETRIMINO_MAX_WIDTH / 2; ++i) {
      for (int j = 0; j < TETRIMINO_MAX_HEIGHT; ++j) {
          swap(rotatedBlock.grid[i][j], rotatedBlock.grid[TETRIMINO_MAX_WIDTH - 1 - i][j]);
      }
  }
  this->game_map.spawnTetrimino(rotatedBlock);    // solo per capire se funziona la rotazione

  return rotatedBlock;
}


void Tetrafrog::startGame() {
  Tetrimino tetriminoUse = generateTetrimino();
  clear();
  printFrog();

  int color_code = 2;
  this->game_map.InitializeMap();
  this->game_map.spawnTetrimino(tetriminoUse);
  this->game_map.print_Tetriminos(color_code);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);  // Funzione ncurses che non ferma il gioco se //
                          // invocate funzione con interrupt(getch)

  // Loop di gioco
  Tetrimino nextTetrimino = generateTetrimino();
  long int downCounter = 0;
  bool gameLoop = true;
  while (gameLoop) {
    // Verifica se c'è una linea completa (composta da 2)
    gameLoop = this->game_map.gameOver();
    this->game_map.checkAndDeleteLine();

    // Gestione movimenti
    int c = getch();
    if (c == KEY_RIGHT) {
      this->game_map.move_Right();
    }
    if (c == KEY_LEFT) {
      this->game_map.move_Left();
    }
    if (c == KEY_UP) {
    //  tetriminoUse = rotation(tetriminoUse);  
      //this->score.calcPoint(random_range(1, 4));   //n. righe completate contemporaneamente
    }
    if (c == KEY_DOWN) {
      // fallo andare giù velocemente
      downCounter = 0;
    }

    bool Spawn = false;
    if (downCounter == 0) {
      Spawn = this->game_map.PinTetriminos();
      this->game_map.move_down();
    }
    downCounter++;
    downCounter %= 3000 / TETRIMINO_SPEED;
    // Fisso Tetrimini setto Spawn

    // Esempio di passaggio al Tetrimino successivo
    if (Spawn) {
    color_code = (rand()%6)+1; 
      this->game_map.spawnTetrimino(nextTetrimino);
      tetriminoUse = nextTetrimino;
      nextTetrimino = generateTetrimino();
    }

    // Gestione grafica
    this->game_map.print_Map();
    this->game_map.print_Tetriminos(color_code);
    this->score.viewScore();
    this->ntv.view(nextTetrimino);
  }

  nodelay(stdscr, FALSE);  // Funzione ncurses che non ferma il gioco se //
  
  keypad(stdscr, FALSE);

  int x;
  int y;

  getMaxCoord(x,y);
mvprintw(y-y/2,x-x/4,"Gameover:()");

refresh();
    getch();
    getch();

  



}
