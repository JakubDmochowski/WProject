#pragma once

#include <SDL.h>
#include <cstdio>

class FPS {
    public:
        static void    onLoop();
        static void    onInit();

        static int     getFPS();
        static double  getSpeedFactor();
        static int     getTickFactor();

    private:
        static int     lastSec;
        static int     lastTime;

        static double  speedFactor;

        static int     frames;
        static int     framesCount;

        static int     ticks;
        FPS();
};
