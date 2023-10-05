#include "../include/figures.h"

void set_current_figure(GameState* game) {

    int randomIndex = rand() % NUM_FIGURES;
    int *randomFigureMatrix = FIGURES[randomIndex];

    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            game->figure.matrix[i][j] = randomFigureMatrix[i * FIGURE_SIZE + j];
        }
    }
    game->figure.x = BOARD_WIDTH / 2 - FIGURE_SIZE / 2;
    game->figure.y = 0;

    int randomColor = rand() % NUM_FIGURES;
    int COLORS[NUM_FIGURES] = {1, 2, 3, 4, 5, 6, 7};
    game->figure.color = COLORS[randomColor];
}

void rotate_current_figure(GameState* game) {

    int tempMatrix[FIGURE_SIZE][FIGURE_SIZE];

    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            tempMatrix[i][j] = game->figure.matrix[i][j];
        }
    }

    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            game->figure.matrix[i][j] = tempMatrix[FIGURE_SIZE - j - 1][i];
        }
    }
}