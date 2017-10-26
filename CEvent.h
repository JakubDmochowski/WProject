#pragma once

#include "KeyboardListener.h"
#include "MouseListener.h"
#include "WindowListener.h"
#include "JoystickListener.h"
#include "UserDefinedListener.h"

class CEvent {

    public:

        static void handleEvents();

    private:

        explicit CEvent();
        virtual ~CEvent();

        static void OnEvent(SDL_Event* Event);
};

