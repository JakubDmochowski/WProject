#pragma once

#include <math.h>
#include <memory>

#include "Timer.h"

class Animation {
    unsigned int frameWidth;
    unsigned int frameHeight;
    unsigned int frameShift;
    unsigned int frameInterval;
    unsigned int maxFrames;

    bool oscilate;

    Timer timer;

    public:
        explicit Animation(unsigned int _frameWidth = 100, unsigned int frameHeight = 100, unsigned int maxFrames = 1, unsigned int frameInterval = 1000, bool oscilate = false);
        explicit Animation(unsigned int _frameWidth, unsigned int frameHeight, unsigned int maxFrames, unsigned int frameInterval, bool oscilate, unsigned int frameShift);

        unsigned int getCurrentFrame() const;
        SDL_Rect* getRect() const;

        void freeze();
        void unfreeze();
};

typedef std::unique_ptr<Animation> AnimationPtr;
