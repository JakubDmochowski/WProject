#pragma once

#include <SDL.h>

class FPS {
    public:
        static FPS FPSControl;

    private:
        int     LastSec;
        int     LastTime;

        double  SpeedFactor;

        int     Frames;
        int     FramesCount;

        int     Ticks;

    public:
        FPS();

        void    OnLoop();

    public:
        int     GetFPS();

        double  GetSpeedFactor() const;
        int     GetTickFactor() const;
};
