#ifndef _KEYLISTEN_H_
#define _KEYLISTEN_H_

#include <SDL.h>
#include <vector>

using namespace std;

struct KeyboardListener {

        static vector<KeyboardListener*> keyboardListeners;

        KeyboardListener();
        virtual ~KeyboardListener();

        virtual void OnKeyDown(SDL_Keycode sym);

        virtual void OnKeyUp(SDL_Keycode sym);
};

#endif // _KEYLISTEN_H_
