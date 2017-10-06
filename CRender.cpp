#include "CRender.h"

CRender CRender::renderHandler;
SDL_Renderer* CRender::renderer;

CRender::CRender() {
}

CRender::~CRender() {
}

void CRender::handleRender() const {
    SDL_RenderClear(renderer);
    for(auto const& i : textures) {
        for(auto const& j : i.second) {
            renderTexture(i.first, j->src, j->dst, j->angle, j->rotateCenter);
        }
    }
    SDL_RenderPresent(renderer);
}

SDL_Renderer* CRender::getRenderer() const {
    return renderer;
}

void CRender::addTexture(Texture* newTexture) {
    std::vector<Renderable*> tempVect;
    tempVect.push_back(new Renderable());
    textures.insert(std::pair<Texture*, std::vector<Renderable*>>(newTexture, tempVect));
}

void CRender::renderTexture(Texture* toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter) const {
    SDL_RenderCopyEx(renderer, toRender->getTexture(), srcrect, dstrect, angle, rotateCenter, SDL_FLIP_NONE);
}
