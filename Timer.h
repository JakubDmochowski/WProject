#pragma once

#include <SDL.h>

class Timer {
    private:
        unsigned int startTick;
        unsigned int pausedTick;

        bool paused;
    public:
        Timer();

        void pause();
        void unpause();

        unsigned int getTime() const;
};
