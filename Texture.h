#pragma once

#include <SDL.h>
#include <cstdio>
#include <list>

#include "Renderable.h"

enum class Priority {
    MAP,
    PROJECTILE,
    TEXT,
    UNDEFINED
    /// lower priority -> rendered before -> behind
    /// higher priority -> rendered after -> on front
};

class Texture {
    SDL_Texture* texture;
    public:
        std::list<RenderablePtr> renderables;

        std::string textureName;
        Priority priority;

        explicit Texture();
        virtual ~Texture();

        bool  loadTexture(std::string filePath);
        std::string getTextureName() const;
        void setTextureName(std::string name);
        SDL_Texture* getTexture() const;
        Priority getPriority() const;
};

typedef std::unique_ptr<Texture> TexturePtr;
