#ifndef NUM_SCORES_IN_LEADERBOARD
#define NUM_SCORES_IN_LEADERBOARD 10
#endif

#ifndef MAX_DIGIT_SCORE
#define MAX_DIGIT_SCORE 10
#endif

#ifndef rows_grid
#define rows_grid 20
#endif

#ifndef columns_grid
#define columns_grid 10
#endif

#ifndef TETRIMINO_MAX_WIDTH
#define TETRIMINO_MAX_WIDTH 4
#endif

#ifndef TETRIMINO_MAX_HEIGHT
#define TETRIMINO_MAX_HEIGHT 3
#endif

#ifndef TETRIMINO_SPEED
#define TETRIMINO_SPEED 1
#endif

#include <cstdlib>
#include <ctime>

void selection_sort_reverted(int v[], int n);
void swap(int &a, int &b);
int random_range(int min, int max);