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

Uint32 render(Uint32 interval, void *param) {
    //----------------------------render--------------------------------
    SDL_Surface* splashSurf = nullptr;
    SDL_Surface* windowSurf = nullptr;

    SDL_Renderer* renderer = nullptr;
    SDL_Texture* splashTexture = nullptr;

    renderer = SDL_CreateRenderer(Window::window, -1, SDL_RENDERER_ACCELERATED);

    windowSurf = SDL_GetWindowSurface(Window::window);
    if(windowSurf == nullptr) {
        printf("Unable to get WindowSurface. SDL Error: %s\n", SDL_GetError() );
    }
    splashSurf = SDL_LoadBMP("gfx/Background.bmp");
    if(splashSurf == nullptr) {
        printf( "Unable to load image %s! SDL Error: %s\n", "gfx/Background.bmp", SDL_GetError() );
    }

    splashTexture = SDL_CreateTextureFromSurface(renderer, splashSurf);
    SDL_FreeSurface(splashSurf);

    SDL_RenderCopy(renderer, splashTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
    //----------------------------render--------------------------------
    int cap = Settings::settings.getFPSCap();
    int fps = FPS::FPSControl.getFPS();
    //cout << "Rendered: " << ++index << endl;
    return 1000 / (fps || cap ? (fps && cap ? (fps < cap ? fps : cap) : (fps ? fps : cap)) : 1);
}

int CApp::execute() {
    if(!initiate()) return 1;
    int a[10] = {1,2,3,4,5,6,7,8,9,8};
    SDL_TimerID WIP = SDL_AddTimer(1000, fpsCounter, nullptr); /// for debug purposes
    SDL_TimerID onRender = SDL_AddTimer(0, render, nullptr);

    while(running) {
        CEvent::eventHandler.HandleEvents();
        FPS::FPSControl.onLoop();
    }
    SDL_DestroyWindow(Window::window);
    SDL_Quit();

    return 0;
}

void CApp::OnKeyDown(SDL_Keycode sym) {
    if(sym == SDLK_ESCAPE) running = false;
}

void CApp::quit() {
    running = false;
}

int main() {
    CApp app;
    return app.execute();
}
