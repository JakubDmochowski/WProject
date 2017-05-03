#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <ctime>
#include <cstdio>

#include "locale/localeEN.h"

#include "define.h"
#include "Settings.h"
#include "CEvent.h"

class CApp : KeyboardListener, WindowListener {
    public:
        bool running;

        CApp();
        ~CApp();

        int execute();

        //------Events------

        void OnKeyDown(SDL_Keycode sym);

        void OnExit();
};

#endif // _CAPP_H_
