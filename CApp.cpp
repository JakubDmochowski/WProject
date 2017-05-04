#define SDL_MAIN_HANDLED
#include "CApp.h"

CApp::CApp() {
    running = true;

    CEvent eventHandler;
}

CApp::~CApp() {
}

int CApp::execute() {
    if(!initiate()) return 1;

    while(running) {
        CEvent::eventHandler.HandleEvents();

        // Example code

        static double current = 0.0;
        static bool change = true;
        if(change) {
            current += 0.001;
            if(current >= 1.0) {
                change = false;
            }
        } else {
            current -= 0.001;
            if(current <= 0.0) {
                change = true;
            }
        }
        glClearColor(current, current, current, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);

        // /Example code
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
