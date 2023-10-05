#ifndef UTILITY_H
#define UTILITY_H

#include <SDL2/SDL.h>
#include "game.h"

SDL_Texture* load_texture(SDL_Renderer* renderer, const char* filename);

SDL_Texture* load_tile(SDL_Renderer* renderer, int color);

void render_figure(SDL_Renderer* renderer, const Figure *figure);

int check_collision(SDL_Rect a, SDL_Rect b);

#endif // UTILITY_H
