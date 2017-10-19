#include "CApp.h"

bool CApp::initiate() {
    #if defined lite_debug || defined full_debug
        SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");
    #endif

    if(SDL_Init( SDL_INIT_EVERYTHING ) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    if(TTF_Init() != 0) {
        printf("Unable to initialize TTF: %s", TTF_GetError());
    }

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

    CRender::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return true;
}
