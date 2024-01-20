#include "ScreenGame.hpp"
using namespace std;

void ScreenGame::displayGameBoard(){
    cout << "Game Board:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (gameBoard[i][j] == 1) { //controller in == 1 (full or eampty) 
                cout << "■ ";  // print the correct and current tetramino
            } else {
                cout << "  ";  // empty cout because there isn't one tetramino
            }
        }
        cout << "\n";
    }
    cout << "\n";
}