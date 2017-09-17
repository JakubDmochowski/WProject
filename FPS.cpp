#include "FPS.h"

FPS FPS::FPSControl;

FPS::FPS() {
    lastSec     = 0;
    lastTime    = 0;

    speedFactor    = 0;

    frames         = 0;
    framesCount    = 0;

    ticks = 0;
}

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

int FPS::getFPS() const {
    return frames;
}

double FPS::getSpeedFactor() const {
    return speedFactor;
}

int FPS::getTickFactor() const {
    return ticks;
}
