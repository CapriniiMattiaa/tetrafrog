#include "NextTetraminoViewer.hpp"


void NextTetraminoViewer::displayNextTetramino(int nextTetramino[4][4]){
    std::cout << "Next Tetramino:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (nextTetramino[i][j] == 1) {
                std::cout << "■ ";  // Simbolo per il blocco del tetramino
            } else {
                std::cout << "  ";  // Spazio vuoto
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}