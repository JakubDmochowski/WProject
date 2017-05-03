#define SDL_MAIN_HANDLED
#include "CApp.h"

CApp::CApp() {
    running = true;

    CEvent eventHandler;
}

CApp::~CApp() {
}

int CApp::execute() {
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *screen = SDL_CreateWindow(TXT_TITLE,
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          Settings::settings.getScreenWidth(), Settings::settings.getScreenHeight(),
                          SDL_WINDOW_OPENGL);


    while(running) {
        CEvent::eventHandler.HandleEvents();
    }

    SDL_Quit();

    return 0;
}

void CApp::OnKeyDown(SDL_Keycode sym) {
    if(sym == SDLK_ESCAPE) running = false;
}

void CApp::OnExit() {
    running = false;
}

int main() {
    CApp app;
    return app.execute();
}
