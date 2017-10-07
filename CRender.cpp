#include "CRender.h"

SDL_Renderer* CRender::renderer;
std::map<Texture*, std::list<Renderable*>> CRender::textures;
std::map<std::string, Texture*> CRender::textureNames;

CRender::CRender() {
}

CRender::~CRender() {
}

void CRender::handleRender() {
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

void CRender::addTexture(Texture* newTexture, const std::string textureName) {
    /// DELETE THAT
    std::list<Renderable*> tempList;
    textureNames.insert(std::pair<std::string, Texture*>(textureName, newTexture));
    ///
    textures.insert(std::pair<Texture*, std::list<Renderable*>>(newTexture, tempList));
}

void CRender::addRenderableToTexture(Renderable* renderable, const std::string texture) {
    auto tmpTextureIterator = textureNames.find(texture);
    if(tmpTextureIterator == textureNames.end()) {
        Texture* tempTexture = new Texture();
        std::string tmpStr = "./gfx/" + texture;
        if(!tempTexture->loadTexture(tmpStr.c_str())){
            if((tmpTextureIterator = textureNames.find("default.bmp")) != textureNames.end()) {
                tempTexture->loadTexture("./gfx/default.bmp");
                addTexture(tempTexture, "default.bmp");
                tmpTextureIterator = textureNames.find("default.bmp");
            } else {
                delete tempTexture;
            }
        } else {
            addTexture(tempTexture, texture);
            tmpTextureIterator = textureNames.find(texture);
        }
    }
    std::list<Renderable*>* tempList = &textures.find(tmpTextureIterator->second)->second;
    tempList->insert(tempList->end(), renderable);
}

void CRender::renderTexture(Texture* toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter) {
    SDL_RenderCopyEx(renderer, toRender->getTexture(), srcrect, dstrect, angle, rotateCenter, SDL_FLIP_NONE);
}
