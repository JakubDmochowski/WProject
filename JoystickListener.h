#ifndef _JOYLISTEN_H_
#define _JOYLISTEN_H_

#include <SDL.h>
#include <vector>

using namespace std;

struct JoystickListener {

        static vector<JoystickListener*> joystickListeners;

        JoystickListener();
        virtual ~JoystickListener();

        virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);

        virtual void OnJoyButtonDown(Uint8 which, Uint8 button);

        virtual void OnJoyButtonUp(Uint8 which, Uint8 button);

        virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);

        virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
};

#endif // _JOYLISTEN_H_

