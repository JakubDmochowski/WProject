#pragma once

#include <SDL.h>
#include <cstdio>
#include <list>

#include "Renderable.h"

enum class Priority {
    MAP,
    PROJECTILE,
    UNDEFINED
    /// lower priority -> rendered before -> behind
    /// higher priority -> rendered after -> on front
};

class Texture {
    SDL_Texture* texture;
    public:
        std::list<RenderablePtr> renderables;

        const char* textureName;
        Priority priority;

        explicit Texture();
        virtual ~Texture();

        bool  loadTexture(const char* filePath);
        SDL_Texture* getTexture() const;
        Priority getPriority() const;
};

typedef std::unique_ptr<Texture> TexturePtr;
