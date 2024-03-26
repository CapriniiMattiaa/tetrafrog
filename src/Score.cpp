#include "Score.hpp"

#include <iostream>
using namespace std;

void Score::viewScore() {
  int x = 30;
  int y = 20;

  std::string variabile = "score: " + std::to_string(this->score);
  mvprintw(y, x, "%s", variabile.c_str());
}

void Score::calcPoint(int molt){
  this->score = this->score + (molt*100);     //100 punti per riga completata 
  viewScore();                               //(*)per il moltiplicatore che cambia a seconda
}                                              //delle righe completate
