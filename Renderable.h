#pragma once

#include <SDL.h>
#include <string>
#include <memory>

class Renderable {
    //Temporary - to be expanded upon to achieve desired functionality
    public:
        SDL_Rect* src;
        SDL_Rect* dst;
        double angle;
        SDL_Point* rotateCenter;
        std::string textureName;

        Renderable(const std::string textureName = "default.bmp");
        Renderable(const Renderable&);
        ~Renderable();
};

typedef std::shared_ptr<Renderable> RenderablePtr;
