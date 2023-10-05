#include <SDL2/SDL.h>
#include "../include/config.h"
#include "../include/render.h"
#include "../include/music.h"

int main(int argc, char* argv[]) {
    SDL_Window* window = SDL_CreateWindow("Tetris",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, BOARD_WIDTH * SCALE, BOARD_HEIGHT * SCALE, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer;

    init_renderer(window, &renderer);
    init_audio();

    Mix_Music *music = load_music("../assets/music/tetris.mp3");
    play_music(music);

    GameState game;
    init_game(&game);
    KeyState keys = {0};
    DebounceState debounceState = {0, 1,0,1, 0, 1};
    Uint64 time = 0;

    int running = 1;
    while (running) {
        process_input(&keys, &running, &debounceState);
        update_game(&game, &keys, &debounceState, &time);
        render_board(renderer, &game);
        SDL_Delay(10);
    }

    clean_music(music);
    close_renderer(renderer);
    SDL_DestroyWindow(window);
}