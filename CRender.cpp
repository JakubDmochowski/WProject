#include "CRender.h"

CRender CRender::renderHandler;
SDL_Renderer* CRender::renderer;

CRender::CRender() {
    //renderer = SDL_CreateRenderer(Window::window, -1, SDL_RENDERER_ACCELERATED);
}

CRender::~CRender() {
}

void CRender::handleRender() const {
    SDL_RenderClear(renderer);
    int nOfTextures = textures.size();
    for(int i = 0; i < nOfTextures; ++i) {
        renderTexture(textures[i], NULL, NULL);
    }
    SDL_RenderPresent(renderer);
}

SDL_Renderer* CRender::getRenderer() const {
    return renderer;
}

void CRender::addTexture(Texture* newTexture) {
    textures.push_back(newTexture);
}

void CRender::renderTexture(Texture* toRender, SDL_Rect* srcrect, SDL_Rect* dstrect) const {
    SDL_RenderCopy(renderer, toRender->getTexture(), srcrect, dstrect);
}
