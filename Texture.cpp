#include "Texture.h"
#include "CRender.h"

Texture::Texture() {
}

Texture::~Texture() {
}

void Texture::loadTexture(char* FilePath) {
    SDL_Surface* tempSurf = SDL_LoadBMP(FilePath);
    SDL_ClearError();
    if(tempSurf == nullptr) {
        printf( "Unable to load image %s! SDL Error: %s\n", FilePath, SDL_GetError() );
        SDL_ClearError();
    }
    texture = SDL_CreateTextureFromSurface(CRender::renderer, tempSurf);
    if(texture == nullptr) {
        printf( "Unable to create texture %s! SDL Error: %s\n", FilePath, SDL_GetError() );
        SDL_ClearError();
    }
    SDL_FreeSurface(tempSurf);
}

SDL_Texture* Texture::getTexture() const {
    return texture;
}
