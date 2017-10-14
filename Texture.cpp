#include "Texture.h"
#include "CRender.h"

Texture::Texture() {
    std::list<RenderablePtr> renderables;
    priority = Priority::UNDEFINED;
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);

    #if defined(lite_debug)
        printf("Destroyed texture: \"./gfx/%s\"\n", textureName);
    #endif
}

bool Texture::loadTexture(const char* textureName) {
    std::string tmpStr = "./gfx/";
    tmpStr.append(textureName);
    const char* filePath = tmpStr.c_str();
    SDL_Surface* tempSurf = SDL_LoadBMP(filePath);
    SDL_ClearError();
    if(tempSurf == nullptr) {
        printf( "Unable to load image %s! SDL Error: %s\n", filePath, SDL_GetError() );
        SDL_ClearError();
        SDL_FreeSurface(tempSurf);
        return false;
    }
    texture = SDL_CreateTextureFromSurface(CRender::renderer, tempSurf);
    if(texture == nullptr) {
        printf( "Unable to create texture %s! SDL Error: %s\n", filePath, SDL_GetError() );
        SDL_ClearError();
        SDL_FreeSurface(tempSurf);
        return false;
    }
    SDL_FreeSurface(tempSurf);
    std::swap(this->textureName, textureName);

    #if defined(full_debug) || defined(lite_debug)
        printf( "Loaded texture: \"%s\"\n", filePath);
    #endif
    return true;
}

SDL_Texture* Texture::getTexture() const {
    return texture;
}

Priority Texture::getPriority() const {
    return priority;
}
