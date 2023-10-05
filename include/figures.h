#ifndef FIGURES_H
#define FIGURES_H

#include "config.h"
#include "game.h"

static int FIGURE_I[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
};

static int FIGURE_O[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
};

static int FIGURE_T[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
};

static int FIGURE_J[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
};

static int FIGURE_L[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0}
};

static int FIGURE_S[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
};

static int FIGURE_Z[FIGURE_SIZE][FIGURE_SIZE] = {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
};

static int *FIGURES[NUM_FIGURES] = {
        (int*)FIGURE_I,
        (int*)FIGURE_O,
        (int*)FIGURE_T,
        (int*)FIGURE_J,
        (int*)FIGURE_L,
        (int*)FIGURE_S,
        (int*)FIGURE_Z
};

void set_current_figure(GameState* game);

void rotate_current_figure(GameState* game);

#endif // FIGURES_H
