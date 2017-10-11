#pragma once

#include <SDL.h>
#include <cstdio>

class FPS {
    public:
        static FPS FPSControl;

    private:
        int     lastSec;
        int     lastTime;

        double  speedFactor;

        int     frames;
        int     framesCount;

        int     ticks;

    public:
        FPS();

        void    onLoop();

    public:
        int     getFPS() const;

        double  getSpeedFactor() const;
        int     getTickFactor() const;
};
