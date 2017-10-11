#pragma once

#include <SDL.h>
#include <map>
#include <algorithm>
#include <memory>
#include "Window.h"
#include "Texture.h"

class CRender {

    static std::map<std::string, TexturePtr> textures;

    public:
        static SDL_Renderer* renderer;

        static void handleRender();

        explicit CRender();
        virtual ~CRender();

        static void addTexture(TexturePtr newTexture, const std::string textureName);
        static void addRenderableToTexture(RenderablePtr renderable);
        static void removeRenderableFromTexture(RenderablePtr);

        SDL_Renderer* getRenderer() const;
    private:
        static void renderTexture(TexturePtr toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter);
};
