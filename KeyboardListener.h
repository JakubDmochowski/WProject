#pragma once

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
