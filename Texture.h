#pragma once

#include <SDL.h>
#include <cstdio>
#include <list>

#include "Renderable.h"

class Texture {
    SDL_Texture* texture;
    public:
        std::list<RenderablePtr> renderables;

        const char* textureName;

        explicit Texture();
        virtual ~Texture();

        bool  loadTexture(const char* filePath);
        SDL_Texture* getTexture() const;
};

typedef std::unique_ptr<Texture> TexturePtr;
