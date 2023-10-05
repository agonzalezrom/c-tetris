#include "../include/input.h"

void process_input(KeyState* keys, int *loop, DebounceState *debounceState) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            *loop = 0;
        } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    if(event.type == SDL_KEYDOWN && debounceState->upReleased) {
                        debounceState->shouldRotate = 1;
                        debounceState->upReleased = 0;
                    } else if(event.type == SDL_KEYUP) {
                        debounceState->upReleased = 1;
                    }
                    keys->up = (event.type == SDL_KEYDOWN);
                    break;
                case SDLK_DOWN:
                    keys->down = (event.type == SDL_KEYDOWN);
                    break;
                case SDLK_LEFT:
                    if(event.type == SDL_KEYDOWN && debounceState->leftReleased) {
                        debounceState->moveLeft = 1;
                        debounceState->leftReleased = 0;
                    } else if(event.type == SDL_KEYUP) {
                        debounceState->leftReleased = 1;
                    }
                    keys->left = (event.type == SDL_KEYDOWN);
                    break;
                case SDLK_RIGHT:
                    if(event.type == SDL_KEYDOWN && debounceState->rightReleased) {
                        debounceState->moveRight = 1;
                        debounceState->rightReleased = 0;
                    } else if(event.type == SDL_KEYUP) {
                        debounceState->rightReleased = 1;
                    }
                    keys->right = (event.type == SDL_KEYDOWN);
                    break;
                default:
                    break;
            }
        }
    }
}
