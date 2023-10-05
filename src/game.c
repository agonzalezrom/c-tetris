#include "../include/game.h"
#include "../include/figures.h"

void init_game(GameState *game) {
    memset(game->board, 0, sizeof(game->board));
    set_current_figure(game);
}

void update_game(GameState *game, const KeyState *keys, DebounceState *debounceState, Uint64 *time) {

    if (debounceState->moveLeft) {
        game->figure.x--;
        debounceState->moveLeft = 0;
    }

    if (debounceState->moveRight) {
        game->figure.x++;
        debounceState->moveRight = 0;
    }

    if (keys->down) {
        game->figure.y++;
    }

    if (debounceState->shouldRotate) {
        rotate_current_figure(game);
        debounceState->shouldRotate = 0;
    }

    auto_drop(game, time);
    colliders(game);
    delete_lines(game);
    game_over(game);
}

void auto_drop(GameState *game, Uint64 *time) {
    Uint64 current_time = SDL_GetTicks64();
    if (current_time - *time >= 1000) {
        game->figure.y++;
        *time = current_time;
    }
}

void game_over(GameState *game) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
        if (game->board[0][x] == 1)
        {
            reset_game(game);
            set_current_figure(game);
        }
    }
}

void delete_lines(GameState *game) {
    for (int y=0; y < BOARD_HEIGHT; y++) {
        for(int x=0; x  < BOARD_WIDTH; x++) {
            if (game->board[y][x] == 0) {
                break;
            }
            if (x == BOARD_WIDTH - 1) {
                for (int i = y; i > 0; i--) {
                    for (int j = 0; j < BOARD_WIDTH; j++) {
                        game->board[i][j] = game->board[i - 1][j];
                    }
                }
            }
        }
    }
}

void colliders(GameState *game) {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            if (game->figure.matrix[i][j] != 0) {

                // check if figure is out of bounds
                if (game->figure.x + j < 0) {
                    game->figure.x++;
                }

                if (game->figure.x + j >= BOARD_WIDTH) {
                    game->figure.x--;
                }

                if (game->figure.y + i >= BOARD_HEIGHT || game->board[game->figure.y + i][game->figure.x + j] != 0) {
                    game->figure.y--;
                    solidify_figure(game);
                    set_current_figure(game);
                }
            }
        }
    }
}

void solidify_figure(GameState *game) {
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            if (game->figure.matrix[i][j] != 0) {
                game->board[game->figure.y + i][game->figure.x + j] = game->figure.color;
            }
        }
    }
}

void reset_game(GameState *game) {
    memset(game->board, 0, sizeof(game->board));
}
