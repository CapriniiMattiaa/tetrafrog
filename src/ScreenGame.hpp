#include <iostream>
#include <vector>

class ScreenGame {
private:
    const int rows;
    const int cols;
    std::vector<std::vector<int>> gameBoard;

public:
    void displayGameBoard() const;

    // Metodo per inserire un tetramino nella griglia di gioco
    void placeTetramino(int tetramino[4][4], int row, int col);

    // Metodo per pulire una riga completata
    void clearCompletedRows();
};
