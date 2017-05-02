#define SDL_MAIN_HANDLED
#include "CApp.h"

CApp::CApp() {
    running = true;
}

CApp::~CApp() {
}

int CApp::execute() {
    SDL_Event Event;

    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *screen = SDL_CreateWindow(TXT_TITLE,
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          640, 480,
                          SDL_WINDOW_OPENGL);

    while(running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }
    }

    SDL_Quit();

    return 0;
}

void CApp::OnKeyDown(SDL_Keycode sym) {
    if(sym == SDLK_ESCAPE) running = false;
}

int main() {
    CApp app;
    return app.execute();
}
