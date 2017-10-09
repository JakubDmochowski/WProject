#pragma once
#include <SDL.h>
#include <list>
#include <map>
#include <algorithm>
#include <memory>
#include "CRender.h"
#include "Window.h"
#include "Texture.h"
#include "Renderable.h"

class CRender {

    static std::map<Texture*, std::list<RenderablePtr>> textures;
    static std::map<std::string, Texture*> textureNames;

    public:
        static SDL_Renderer* renderer;

        static void handleRender();

        explicit CRender();
        virtual ~CRender();

        static void addTexture(Texture* newTexture, const std::string textureName);
        static void addRenderableToTexture(RenderablePtr renderable);
        static void removeTexture(const std::string textureName);
        static void removeRenderableFromTexture(RenderablePtr);

        SDL_Renderer* getRenderer() const;
    private:
        static void renderTexture(Texture* toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter);
};
