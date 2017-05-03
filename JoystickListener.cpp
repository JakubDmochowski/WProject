#include "JoystickListener.h"

vector<JoystickListener*> JoystickListener::joystickListeners;

JoystickListener::JoystickListener() {
    joystickListeners.push_back(this);
}

JoystickListener::~JoystickListener() {
    //Virtual
}

void JoystickListener::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value) {
    //Virtual
}

void JoystickListener::OnJoyButtonDown(Uint8 which, Uint8 button) {
    //Virtual
}

void JoystickListener::OnJoyButtonUp(Uint8 which, Uint8 button) {
    //Virtual
}

void JoystickListener::OnJoyHat(Uint8 which, Uint8 hat, Uint8 value) {
    //Virtual
}

void JoystickListener::OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel) {
    //Virtual
}
