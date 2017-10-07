#pragma once
#include <SDL.h>
#include <list>
#include <map>
#include <algorithm>
#include "CRender.h"
#include "Window.h"
#include "Texture.h"
#include "Renderable.h"

class CRender {

    static std::map<Texture*, std::list<Renderable*>> textures;
    static std::map<std::string, Texture*> textureNames;

    public:
        static SDL_Renderer* renderer;

        static void handleRender();

        explicit CRender();
        virtual ~CRender();

        static void addTexture(Texture* newTexture, const std::string textureName);
        static void addRenderableToTexture(Renderable* renderable, const std::string texture);

        SDL_Renderer* getRenderer() const;
    private:
        static void renderTexture(Texture* toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter);
};
