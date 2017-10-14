#define SDL_MAIN_HANDLED
#include "CApp.h"

#include <cstdlib>

CApp::CApp() {
    running = true;
}

#if defined showFPS
    Uint32 fpsCounter(Uint32 interval, void* param) {
        printf("Current FPS: %d\n", FPS::getFPS());
        return interval;
    }
#endif

int CApp::execute() {
    if(!initiate()) return 1;

    #if defined showFPS
        SDL_AddTimer(1000, fpsCounter, nullptr);
    #endif

    /// CRAP CODE
    RenderablePtr temp = RenderablePtr(new Renderable());
    CRender::addRenderableToTexture(temp);
    /// --CRAP CODE

    while(running) {
        CEvent::handleEvents();
        FPS::onLoop();
        CRender::handleRender();
    }
    SDL_DestroyWindow(window);
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
