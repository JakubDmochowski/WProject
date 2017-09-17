#pragma once
#include <SDL.h>
#include <vector>
#include <algorithm>
#include "CRender.h"
#include "Window.h"
#include "Texture.h"

class CRender {

    std::vector<Texture*> textures;

    public:
        static SDL_Renderer* renderer;
        static CRender renderHandler;

        void handleRender() const;

        explicit CRender();
        virtual ~CRender();

        void addTexture(Texture* newTexture);

        SDL_Renderer* getRenderer() const;
    private:
        void renderTexture(Texture* toRender, SDL_Rect* srcrect, SDL_Rect* dstrect) const;
};
