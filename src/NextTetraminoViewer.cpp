#include "NextTetraminoViewer.hpp"
#include "I.hpp"
#include "J.hpp"
#include "L.hpp"
#include "O.hpp"
#include "S.hpp"
#include "T.hpp"
#include "Z.hpp"
#include <iostream>
using namespace std;

void NextTetraminoViewer::arrayTetramini(Tetramino tetramino[]){
    tetramino[0] = I i = new I();
    tetramino[1] = J i = new J();
    tetramino[2] = L i = new L();
    tetramino[3] = O i = new O();
    tetramino[4] = S i = new S();
    tetramino[5] = T i = new T();
    tetramino[6] = Z i = new Z(); 
}

Tetramino NextTetraminoViewer::generateRandomTetramino(Tetramino[]){

    srand(time(NULL));
    int position = rand()%7; //generated number between 0 and 7
    return tetramino[position]; //returned casual tetramino
}