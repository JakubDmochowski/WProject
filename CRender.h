#pragma once

#include <SDL.h>
#include <set>
#include <algorithm>
#include <memory>
#include "Texture.h"
#include "Font.h"

struct CRenderTextureComparator {
    bool operator()(const TexturePtr& left, const TexturePtr& right) {
        return left->priority < right->priority;
    }
};

class CRender {
    static std::set<TexturePtr, CRenderTextureComparator> textures;

    public:
        static SDL_Renderer* renderer;

        static void handleRender();

        static inline void addTexture(TexturePtr newTexture);
        static void addRenderableToTexture(const RenderablePtr& renderable);

        SDL_Renderer* getRenderer() const;
    private:
        CRender();

        static inline void renderTexture(const TexturePtr& toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter);
};
