#include "Leaderboard.hpp"

#include "tools.h"

int Leaderboard::countScores(ifstream &fin) {
  int length_scores = 0;
  while (!fin.eof()) {
    char c[MAX_DIGIT_SCORE];
    fin.getline(c, MAX_DIGIT_SCORE);
    if (c[0] != '\0') length_scores++;
  }
  return length_scores;
}

void Leaderboard::addScore(int score) {
  ofstream fout;
  fout.open("./Leaderboard.txt", ios::app);
  fout << score << endl;
  fout.close();
}

void Leaderboard::getFirstTen(int scores[]) {
  // Apro il file
  ifstream fin;
  fin.open("./Leaderboard.txt");

  // Conto le linee (numero di punteggi)
  int length_scores = countScores(fin);

  // Inserisco in un array tutti i punteggi
  fin.clear();
  fin.seekg(0);
  int all_scores[length_scores];
  for (int i = 0; i < length_scores; i++) {
    char c[MAX_DIGIT_SCORE];
    fin.getline(c, MAX_DIGIT_SCORE);
    all_scores[i] = atoi(c);
  }

  // Ordino l'array in modo decrescente
  selection_sort_reverted(all_scores, length_scores);

  // Inserisco i primi 10 punteggi in scores[]
  for (int i = 0; i < NUM_SCORES_IN_LEADERBOARD && i < length_scores; i++)
    scores[i] = all_scores[i];
}