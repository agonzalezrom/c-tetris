#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include "config.h"
#include "game.h"

void init_renderer(SDL_Window *window, SDL_Renderer **renderer);
void close_renderer(SDL_Renderer *renderer);
void render_board(SDL_Renderer *renderer, GameState *game);

#endif /* RENDER_H */
