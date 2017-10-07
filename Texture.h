#pragma once

#include <SDL.h>
#include <cstdio>

class Texture {
    SDL_Texture* texture;
    public:
        static Texture textureHandler;

        explicit Texture();
        virtual ~Texture();

        bool  loadTexture(const char* filePath);
        SDL_Texture* getTexture() const;
};
