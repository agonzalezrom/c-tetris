#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "input.h"

typedef struct {
    int matrix[FIGURE_SIZE][FIGURE_SIZE];
    int x;
    int y;
    int color;
} Figure;

typedef struct {
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    Figure  figure;
} GameState;

void init_game(GameState* game);
void update_game(GameState *game, const KeyState *keys, DebounceState *debounceState, Uint64 *time);
void auto_drop(GameState *game, Uint64 *time);
void game_over(GameState *game);
void delete_lines(GameState *game);
void colliders(GameState *game);
void solidify_figure(GameState *game);
void reset_game(GameState* game);

#endif // GAME_H
