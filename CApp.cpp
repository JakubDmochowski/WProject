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
    std::vector<RenderablePtr> craplist;
    for(int i = 0; i < 100; ++i) {
        TransformPtr tempTransform = std::make_shared<Transform>(Settings::getScreenWidth() / 10, Settings::getScreenHeight() / 10, Settings::getScreenWidth() / 10 * (i % 10), Settings::getScreenHeight() / 10 * (i / 10));
        AnimationPtr tempAnimation = std::make_unique<Animation>(100, 100, 5, 100, false);
        RenderablePtr temp = Renderable::create("asdf.bmp", tempTransform, std::move(tempAnimation));
        craplist.push_back(temp);
    }
    /// --CRAP CODE

    while(running) {
        CEvent::handleEvents();
        FPS::onLoop();
        CRender::handleRender();
    }
    SDL_DestroyWindow(window);
    TTF_Quit();
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
