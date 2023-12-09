#include <fstream>
#include <iostream>

using namespace std;

class Leaderboard {
 protected:
  int countScores(ifstream &fin);

 public:
  void addScore(int score);
  void getFirstTen(int scores[]);
};