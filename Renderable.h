#pragma once

#include <SDL.h>

class Renderable {
    //Temporary - to be expanded upon to achieve desired functionality
    public:
        SDL_Rect* src;
        SDL_Rect* dst;
        double angle;
        SDL_Point* rotateCenter;

        Renderable();
        ~Renderable();
};
