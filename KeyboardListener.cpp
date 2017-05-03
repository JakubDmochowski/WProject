#include "KeyboardListener.h"

vector<KeyboardListener*> KeyboardListener::keyboardListeners;

KeyboardListener::KeyboardListener() {
    keyboardListeners.push_back(this);
}

KeyboardListener::~KeyboardListener() {
    //Virtual
}

void KeyboardListener::OnKeyDown(SDL_Keycode sym) {
    //Virtual
}

void KeyboardListener::OnKeyUp(SDL_Keycode sym) {
    //Virtual
}
