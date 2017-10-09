#define SDL_MAIN_HANDLED
#include "CApp.h"

#include <iostream>
#include <cstdlib>

CApp::CApp() {
    running = true;

    CEvent eventHandler;
}

Uint32 fpsCounter(Uint32 interval, void* param) {
    cout << Timer::GameTimerControl.getTime() << endl;
    printf("Current FPS: %d\n", FPS::FPSControl.getFPS());
    return interval;
}

int CApp::execute() {
    if(!initiate()) return 1;
    int a[10] = {1,2,3,4,5,6,7,8,9,8};
    SDL_TimerID WIP = SDL_AddTimer(1000, fpsCounter, nullptr); /// for debug purposes

    // CRAP CODE
    RenderablePtr costam(new Renderable());
    costam->dst = new SDL_Rect();
    costam->dst->w = 100;
    costam->dst->h = 100;
    CRender::addRenderableToTexture(costam);

    // --CRAP CODE
    while(running) {
        CEvent::eventHandler.handleEvents();
        FPS::FPSControl.onLoop();
        CRender::handleRender();
        // CRAP CODE
        costam->dst->x++;
        if(costam->dst->x > Settings::settings.getScreenWidth()) {
            costam->dst->x = -100;
            costam->dst->y++;
        }
        // --CRAP CODE
    }
    SDL_DestroyWindow(Window::window);
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
