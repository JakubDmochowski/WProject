#include "CApp.h"

bool CApp::initiate() {
    SDL_Init( SDL_INIT_EVERYTHING );

    if(!Settings::settings.getFullscreen()) {
        window = SDL_CreateWindow(TXT_TITLE,
                  SDL_WINDOWPOS_UNDEFINED,
                  SDL_WINDOWPOS_UNDEFINED,
                  Settings::settings.getScreenWidth(), Settings::settings.getScreenHeight(),
                  SDL_WINDOW_OPENGL);
    } else {
        window = SDL_CreateWindow(TXT_TITLE,
                  SDL_WINDOWPOS_UNDEFINED,
                  SDL_WINDOWPOS_UNDEFINED,
                  Settings::settings.getScreenWidth(), Settings::settings.getScreenHeight(),
                  SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
    }
    if(!window) {
        printf("Error while creating window!\n");
        return false;
    }
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    context = SDL_GL_CreateContext( window );
}
