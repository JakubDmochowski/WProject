#include "CRender.h"

SDL_Renderer* CRender::renderer;
std::map<std::string, TexturePtr> CRender::textures;

void CRender::handleRender() {
    SDL_RenderClear(renderer);
    for(auto i = textures.begin(); i != textures.end();) {
        for(auto j = (*i).second->renderables.begin(); j != (*i).second->renderables.end();) {
            if(j->use_count() == 1) {
                j = (*i).second->renderables.erase(j);
            } else {
                renderTexture((*i).second, (*j)->getSrc(), (*j)->getDst(), (*j)->getAngle(), (*j)->getRotateCenter());
                ++j;
            }
        }
        if((*i).second->renderables.size() == 0) {
            i = textures.erase(i);
        } else {
            ++i;
        }
    }
    SDL_RenderPresent(renderer);
}

SDL_Renderer* CRender::getRenderer() const {
    return renderer;
}

void CRender::addTexture(TexturePtr newTexture, const std::string textureName) {
    textures.insert(std::pair<std::string, TexturePtr>(textureName, std::move(newTexture)));
}

void CRender::addRenderableToTexture(RenderablePtr renderable) {
    if(!renderable.get()){
        throw std::runtime_error("CRender::addRenderableToTexture RenderablePtr = nullptr");
        return;
    }
    auto tmpTextureIterator = textures.find(renderable->textureName);
    if(tmpTextureIterator == textures.end()) {
        TexturePtr tempTexture = std::make_unique<Texture>();
        if(!tempTexture->loadTexture(renderable->textureName.c_str())){
            if((tmpTextureIterator = textures.find("default.bmp")) != textures.end()) {
                tempTexture->loadTexture("default.bmp");
                addTexture(std::move(tempTexture), "default.bmp");
                tmpTextureIterator = textures.find("default.bmp");
            }
        } else {
            addTexture(std::move(tempTexture), renderable->textureName);
            tmpTextureIterator = textures.find(renderable->textureName);
        }
    }
    std::list<RenderablePtr>* tempList = &tmpTextureIterator->second->renderables;
    tempList->insert(tempList->end(), renderable);
}

void CRender::renderTexture(TexturePtr& toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter) {
    SDL_RenderCopyEx(renderer, toRender->getTexture(), srcrect, dstrect, angle, rotateCenter, SDL_FLIP_NONE);
}
