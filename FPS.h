#ifndef _FPS_H_
    #define _FPS_H_

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

        int     FPSCap;

    public:
        FPS();

        void    onLoop();

    public:
        int     getFPS() const;

        double  getSpeedFactor() const;
        int     getTickFactor() const;

        void    setFPSCap(int cap);
        int     getFPSCap() const;
};

#endif //_FPS_H_
