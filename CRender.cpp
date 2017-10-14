#include "CRender.h"

SDL_Renderer* CRender::renderer;

std::set<TexturePtr> CRender::textures;

void CRender::handleRender() {
    SDL_RenderClear(renderer);
    for(auto const& i : textures) {
        for(auto j = (*i).renderables.begin(); j != (*i).renderables.end();) {
            if(j->use_count() == 1) {
                j = (*i).renderables.erase(j);
            } else {
                renderTexture((*i), (*j)->getSrc(), (*j)->getDst(), (*j)->getAngle(), (*j)->getRotateCenter());
                ++j;
            }
        }
        /*if((*i)->renderables.size() == 0) {
            i = textures.erase(i);
        } else {
            ++i;
        }*/
    }
    SDL_RenderPresent(renderer);
}

SDL_Renderer* CRender::getRenderer() const {
    return renderer;
}

void CRender::addTexture(TexturePtr newTexture) {
    textures.insert(textures.end(), std::move(newTexture));
}

void CRender::addRenderableToTexture(const RenderablePtr& renderable) {
    auto cmpRenderable = [&](const TexturePtr& t){ return strcmp(t->textureName, renderable->getTextureName().c_str()) == 0;};
    auto cmpDefault = [&](const TexturePtr& t){ return strcmp(t->textureName, "default.bmp") == 0;};

    //auto tmpTextureIterator = std::find_if(textures.begin(), textures.end(), cmpRenderable);

    bool check = false;
    for(auto const& i : textures) {
        if(i.get()->textureName == renderable->getTextureName()) {
            check = true;
            break;
        }
    }
    if(!check) {
    //if(tmpTextureIterator == textures.end()) {
        TexturePtr tempTexture(new Texture());
        if(!tempTexture->loadTexture(renderable->getTextureName().c_str())) {
            check = false;
            for(auto const& i : textures) {
                if(i.get()->textureName == "default.bmp") {
                    check = true;
                    break;
                }
            }
            if(check) {
            //if((tmpTextureIterator = std::find_if(textures.begin(), textures.end(), cmpDefault)) != textures.end()) {
                tempTexture->loadTexture("default.bmp");
                addTexture(std::move(tempTexture));
                //tmpTextureIterator = std::find_if(textures.begin(), textures.end(), cmpDefault);
            }
        } else {
            addTexture(std::move(tempTexture));
            //tmpTextureIterator = std::find_if(textures.begin(), textures.end(), cmpRenderable);
        }
    }
    for(auto const& i : textures) {
        if(i.get()->textureName == renderable->getTextureName()) {
            i.get()->renderables.insert(i->renderables.end(), renderable);
            break;
        }
    }
    //tmpTextureIterator->get()->renderables.insert(tmpTextureIterator->get()->renderables.end(), renderable);
            printf("%s\n", (*CRender::textures.begin())->textureName);
}

void CRender::renderTexture(const Texture& toRender, SDL_Rect* srcrect, SDL_Rect* dstrect, double angle, SDL_Point* rotateCenter) {
    SDL_RenderCopyEx(renderer, toRender.getTexture(), srcrect, dstrect, angle, rotateCenter, SDL_FLIP_NONE);
}
