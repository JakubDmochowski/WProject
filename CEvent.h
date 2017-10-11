#pragma once

#include "KeyboardListener.h"
#include "MouseListener.h"
#include "WindowListener.h"
#include "JoystickListener.h"
#include "UserDefinedListener.h"

class CEvent {

    public:

        static CEvent eventHandler;

        void handleEvents();

        explicit CEvent();
        virtual ~CEvent();

    private:

        virtual void OnEvent(SDL_Event* Event);
};

