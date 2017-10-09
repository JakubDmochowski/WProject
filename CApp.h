#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <ctime>
#include <cstdio>
#include <gl/gl.h>
#include <gl/glu.h>

#include "locale/localeEN.h"

#include "FPS.h"
#include "Timer.h"
#include "define.h"
#include "Settings.h"
#include "CEvent.h"
#include "Window.h"
#include "Texture.h"
#include "CRender.h"
#include "Entity.h"

struct CApp : KeyboardListener, WindowListener {
        bool running;

        SDL_GLContext context;

        CApp();

        int execute();

        bool initiate();

        //------Events------

        void OnKeyDown(SDL_Keycode sym);

        void OnExit();
};

#endif // _CAPP_H_
