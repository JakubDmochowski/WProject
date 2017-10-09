#include "CRender.h"

SDL_Renderer* CRender::renderer;
std::map<Texture*, std::list<RenderablePtr>> CRender::textures;
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
    std::list<RenderablePtr> tempList;
    ///
    textureNames.insert(std::pair<std::string, Texture*>(textureName, newTexture));
    textures.insert(std::pair<Texture*, std::list<RenderablePtr>>(newTexture, tempList));
}

void CRender::addRenderableToTexture(RenderablePtr renderable) {
    if(!renderable.get()){
        throw std::runtime_error("CRender::addRenderableToTexture renderablePtr = null");
        return;
    }
    auto tmpTextureIterator = textureNames.find(renderable->textureName);
    if(tmpTextureIterator == textureNames.end()) {
        Texture* tempTexture = new Texture();
        std::string tmpStr = "./gfx/" + renderable->textureName;
        if(!tempTexture->loadTexture(tmpStr.c_str())){
            if((tmpTextureIterator = textureNames.find("default.bmp")) != textureNames.end()) {
                tempTexture->loadTexture("./gfx/default.bmp");
                addTexture(tempTexture, "default.bmp");
                tmpTextureIterator = textureNames.find("default.bmp");
            } else {
                delete tempTexture;
            }
        } else {
            addTexture(tempTexture, renderable->textureName);
            tmpTextureIterator = textureNames.find(renderable->textureName);
        }
    }
    std::list<RenderablePtr>* tempList = &textures.find(tmpTextureIterator->second)->second;
    tempList->insert(tempList->end(), renderable);
}

void CRender::renderTexture(Texture* toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter) {
    SDL_RenderCopyEx(renderer, toRender->getTexture(), srcrect, dstrect, angle, rotateCenter, SDL_FLIP_NONE);
}

void CRender::removeTexture(const std::string textureName) {
    auto tmp = textureNames.find(textureName);
    textures.erase(textures.find(tmp->second));
    textureNames.erase(tmp);
}
