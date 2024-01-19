#include "ScreenGame.hpp"
#include "../../../../../../usr/include/c++/13/bits/algorithmfwd.h"

void ScreenGame::displayGameBoard() const {
    std::cout << "Game Board:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (gameBoard[i][j] == 1) {
                std::cout << "■ ";  // Simbolo per il blocco del tetramino
            } else {
                std::cout << "  ";  // Spazio vuoto
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

// Metodo per inserire un tetramino nella griglia di gioco
void ScreenGame::placeTetramino(int tetramino[4][4], int row, int col) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (tetramino[i][j] == 1) {
                // Assicurati di non superare i limiti della griglia
                if (row + i < rows && col + j < cols) {
                    gameBoard[row + i][col + j] = 1;
                }
            }
        }
    }
}

// Metodo per pulire una riga completata
void ScreenGame::clearCompletedRows() {
    for (int i = rows - 1; i >= 0; --i) {
        if (std::all_of(gameBoard[i].begin(), gameBoard[i].end(), [](int block) { return block == 1; })) {
            // Rimuovi la riga completata
            gameBoard.erase(gameBoard.begin() + i);
            // Aggiungi una nuova riga vuota in cima
            gameBoard.insert(gameBoard.begin(), std::vector<int>(cols, 0));
        }
    }
}

