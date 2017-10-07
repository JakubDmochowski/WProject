#include "CApp.h"

bool CApp::initiate() {
    // This line is only needed, if you want debug the program
    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");

    if(SDL_Init( SDL_INIT_EVERYTHING ) != 0){
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    };

    if(!Settings::settings.getFullscreen()) {
        Window::window = SDL_CreateWindow(TXT_TITLE,
                  SDL_WINDOWPOS_UNDEFINED,
                  SDL_WINDOWPOS_UNDEFINED,
                  Settings::settings.getScreenWidth(), Settings::settings.getScreenHeight(),
                  SDL_WINDOW_OPENGL);
    } else {
        Window::window = SDL_CreateWindow(TXT_TITLE,
                  SDL_WINDOWPOS_UNDEFINED,
                  SDL_WINDOWPOS_UNDEFINED,
                  Settings::settings.getScreenWidth(), Settings::settings.getScreenHeight(),
                  SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
    }
    if(!Window::window) {
        printf("Error while creating window!\n");
        return false;
    }/*
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    context = SDL_GL_CreateContext( Window::window );*/

    CRender::renderer = SDL_CreateRenderer(Window::window, -1, SDL_RENDERER_ACCELERATED);

    Timer::GameTimerControl.start();
    return true;
}
