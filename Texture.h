#pragma once

#include <SDL.h>
#include <cstdio>
#include <list>

#include "define.h"
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

typedef std::shared_ptr<Texture> TexturePtr;
