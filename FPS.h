#pragma once

#include <SDL.h>
#include <cstdio>

class FPS {
    public:
        static void    onLoop();
        static void    onInit();

        static unsigned int     getFPS();
        static double           getSpeedFactor();
        static unsigned int     getTickFactor();

    private:
        static unsigned int     lastSec;
        static unsigned int     lastTime;

        static double           speedFactor;

        static unsigned int     frames;
        static unsigned int     framesCount;

        static unsigned int     ticks;
        FPS();
};
