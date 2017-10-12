#pragma once

#include <SDL.h>
#include <ctime>
#include <cstdio>
#include <gl/gl.h>
#include <gl/glu.h>

#include "locale/localeEN.h"

#include "FPS.h"
#include "Timer.h"
#include "Settings.h"
#include "CEvent.h"
#include "CRender.h"
#include "Entity.h"

struct CApp : KeyboardListener, WindowListener {
        bool running;
        SDL_Window* window;

        CApp();

        int execute();

        bool initiate();

        //------Events------

        void OnKeyDown(SDL_Keycode sym);

        void OnExit();
};
