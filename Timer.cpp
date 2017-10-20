#include "Timer.h"

Timer::Timer() {
    startTick = SDL_GetTicks();
    pausedTick = 0;

    paused = false;
}


void Timer::pause() {
    if(paused) return;
    paused = true;
    pausedTick = SDL_GetTicks();
}

void Timer::unpause() {
    if(!paused) return;
    paused = false;
    startTick += SDL_GetTicks() - pausedTick;
}

unsigned int Timer::getTime() const {
    if(paused) return pausedTick - startTick;
    return SDL_GetTicks() - startTick;
}
