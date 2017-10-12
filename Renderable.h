#pragma once

#include <SDL.h>
#include <string>
#include <memory>

#include "Transform.h"

class Renderable {
    TransformPtr transform;

    public:
        std::string textureName;

        Renderable(const std::string textureName = "default.bmp", TransformPtr transform = NULL);
        ~Renderable();

        SDL_Rect* getSrc() const;
        SDL_Rect* getDst() const;
        double getAngle() const;
        SDL_Point* getRotateCenter() const;
};

typedef std::shared_ptr<Renderable> RenderablePtr;
