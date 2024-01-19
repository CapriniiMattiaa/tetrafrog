#include <ncurses.h>
#include <unistd.h>

#include "Leaderboard.hpp"
#include "Tetrafrog.hpp"
#include "tools.h"

class NextTetraminoViewer {
public:
    void displayNextTetramino(int nextTetramino[4][4]);
};