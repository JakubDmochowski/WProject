#include "FPS.h"

int FPS::lastSec     = 0;
int FPS::lastTime    = 0;

double FPS::speedFactor    = 0;

int FPS::frames         = 0;
int FPS::framesCount    = 0;

int FPS::ticks = 0;

void FPS::onLoop() {
    if(lastSec + 1000 < SDL_GetTicks()) {
        lastSec = SDL_GetTicks();
        frames = framesCount;
        framesCount = 0;
    }

    speedFactor = ((SDL_GetTicks() - lastTime) / 1000.0f) * 32.0f; //32.0f for what?
    ticks = SDL_GetTicks() - lastTime;
    lastTime = SDL_GetTicks();
    ++framesCount;
}

int FPS::getFPS() {
    return frames;
}

double FPS::getSpeedFactor() {
    return speedFactor;
}

int FPS::getTickFactor() {
    return ticks;
}
