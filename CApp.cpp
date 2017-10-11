#define SDL_MAIN_HANDLED
#include "CApp.h"

#include <cstdlib>

CApp::CApp() {
    running = true;

    CEvent eventHandler;
}

#if defined showFPS
Uint32 fpsCounter(Uint32 interval, void* param) {
    printf("Current FPS: %d\n", FPS::FPSControl.getFPS());
    return interval;
}
#endif // defined

int CApp::execute() {
    if(!initiate()) return 1;

    #if defined showFPS
        SDL_TimerID WIP = SDL_AddTimer(1000, fpsCounter, nullptr); /// for debug purposes
    #endif

    // CRAP CODE
    bool check = true;
    int k = 0;
    std::list<RenderablePtr> templist;
    // --CRAP CODE
    while(running) {
        CEvent::eventHandler.handleEvents();
        FPS::FPSControl.onLoop();
        CRender::handleRender();

        // CRAP CODE
        if(k > 1000 && !check){
            check = true;
            k = 0;
            templist.clear();
        }
        if(k > 100 && check){
            for(int i = 0; i < 100; ++i){
                RenderablePtr news(new Renderable("asdf.bmp"));
                CRender::addRenderableToTexture(news);
                templist.insert(templist.end(), news);
                news->dst = new SDL_Rect();
                news->dst->w = 50 + rand() % 50 - 25;
                news->dst->h = 50 + rand() % 50 - 25;
                news->dst->x = rand() % 500;
                news->dst->y = rand() % 500;
                check = false;
                k = 0;
            }
        }
        k++;
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
