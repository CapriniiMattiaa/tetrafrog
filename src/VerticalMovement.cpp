#include "VerticalMovement.hpp"

void MovimentVerticalTetramino :: moveVertical(Tetrimino *tetramino, int positions) {

    for (int i = 0; i < positions; ++i) {
        if (tetramino->grid[i][j] == 1) { // Supponiamo che 1 rappresenti un blocco del tetramino
            // Effettua il movimento verticale
            // Ad esempio, decrementa j per far scendere il blocco
            // Nota: Aggiungi controlli per evitare di scendere oltre il limite inferiore
        }
    
    }

    // Stampa il tetramino
    tetramino->print();

    // Attendi un secondo prima del prossimo movimento
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
}