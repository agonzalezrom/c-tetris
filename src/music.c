#include "../include/music.h"

int init_audio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        SDL_Log("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640)) {
        SDL_Log("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return -1;
    }

    return 0;
}

Mix_Music* load_music(const char* path) {
    Mix_Music *music = Mix_LoadMUS(path);
    if (music == NULL) {
        SDL_Log("Failed to load music: %s\n", Mix_GetError());
    }
    return music;
}

void play_music(Mix_Music* music) {
    Mix_PlayMusic(music, -1);
}

void clean_music(Mix_Music* music) {
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}