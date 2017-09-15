#define SDL_MAIN_HANDLED
#include "CApp.h"

#include <iostream>
#include <cstdlib>

CApp::CApp() {
    running = true;

    CEvent eventHandler;
}

int index = 0;

//example function
Uint32 workInProgress(Uint32 interval, void* param) {
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
    int cap = FPS::FPSControl.getFPSCap();
    int fps = FPS::FPSControl.getFPS();
    cout << "Rendered: " << ++index << endl;
    return 1000 / (fps || cap ? (fps && cap ? (fps < cap ? fps : cap) : (fps ? fps : cap)) : 1);
}

int CApp::execute() {
    if(!initiate()) return 1;
    SDL_TimerID WIP = SDL_AddTimer(1000, workInProgress, nullptr); /// for debug purposes
    SDL_TimerID onRender = SDL_AddTimer(0, render, nullptr);

    while(running) {
        CEvent::eventHandler.HandleEvents();
        FPS::FPSControl.onLoop();

                // Example code
        /*
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
        SDL_GL_SwapWindow(window);SDL_RenderClear(renderer);*/
        // Example code
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
