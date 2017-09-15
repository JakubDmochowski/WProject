#ifndef _CEVENT_H_
    #define _CEVENT_H_

#include "KeyboardListener.h"
#include "MouseListener.h"
#include "WindowListener.h"
#include "JoystickListener.h"
#include "UserDefinedListener.h"

class CEvent {

    public:

        static CEvent eventHandler;

        void HandleEvents();

        CEvent();
        virtual ~CEvent();

    private:

        virtual void OnEvent(SDL_Event* Event);
};

#endif
