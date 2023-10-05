#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

typedef struct {
    int up;
    int down;
    int left;
    int right;
} KeyState;

typedef struct {
    int moveLeft;
    int leftReleased;
    int moveRight;
    int rightReleased;
    int shouldRotate;
    int upReleased;
} DebounceState;

void process_input(KeyState* keys, int *loop, DebounceState *upKeyProcessed);

#endif // INPUT_H
