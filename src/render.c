#include "../include/render.h"

void init_renderer(SDL_Window* window, SDL_Renderer **renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void render_board(SDL_Renderer *renderer, GameState *game) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (game->board[i][j]) {
                SDL_Rect block = { j * SCALE, i * SCALE, SCALE, SCALE };
                SDL_RenderFillRect(renderer, &block);
            }
        }
    }

    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            if (game->figure.matrix[i][j]) {
                SDL_Rect block = {
                        (game->figure.x + j) * SCALE,
                        (game->figure.y + i) * SCALE,
                        SCALE,
                        SCALE
                };
                SDL_RenderFillRect(renderer, &block);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

void close_renderer(SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
