#ifndef MUSIC_H
#define MUSIC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int init_audio();
Mix_Music* load_music(const char* path);
void play_music(Mix_Music* music);
void clean_music(Mix_Music* music);

#endif // MUSIC_H
