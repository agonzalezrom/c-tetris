#include "../include/utility.h"

SDL_Texture* load_texture(SDL_Renderer* renderer, const char* filename) {
    SDL_Surface* surface = SDL_LoadBMP(filename);
    if (!surface) {
        SDL_Log("Error al cargar la imagen %s: %s\n", filename, SDL_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* load_tile(SDL_Renderer* renderer, int color) {
    char filename[256];
    SDL_Log(filename, sizeof(filename), "assets/%d.png", color);
    SDL_Texture* texture = load_texture(renderer, filename);
    return texture;
}

void render_figure(SDL_Renderer* renderer, const Figure *figure) {
    SDL_Texture* tile = load_tile(renderer, figure->color);
    for (int i = 0; i < FIGURE_SIZE; i++) {
        for (int j = 0; j < FIGURE_SIZE; j++) {
            if (figure->matrix[i][j]) {
                SDL_Rect dest = {
                        figure->x * TILE_SIZE + j * TILE_SIZE,
                        figure->y * TILE_SIZE + i * TILE_SIZE,
                        TILE_SIZE,
                        TILE_SIZE
                };
                SDL_RenderCopy(renderer, tile, NULL, &dest);
            }
        }
    }
    SDL_DestroyTexture(tile);
}


int check_collision(SDL_Rect a, SDL_Rect b) {
    return a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y;
}
