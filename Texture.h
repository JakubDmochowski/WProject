#pragma once

#include <SDL.h>
#include <cstdio>

class Texture {
    SDL_Texture* texture;
    public:
        static Texture textureHandler;

        explicit Texture();
        virtual ~Texture();

        void  loadTexture(char* filePath);
        SDL_Texture* getTexture() const;
};
