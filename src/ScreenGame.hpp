#include <iostream>
using namespace std;

class ScreenGame {
private:
    const int rows;
    const int cols;
    int gameBoard[rows][cols];

public:
    void displayGameBoard();
};
