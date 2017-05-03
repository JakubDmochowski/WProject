#include "WindowListener.h"

vector<WindowListener*> WindowListener::windowListeners;

WindowListener::WindowListener() {
    windowListeners.push_back(this);
}

WindowListener::~WindowListener() {
    //Virtual
}

void WindowListener::OnInputFocus() {
    //Virtual
}

void WindowListener::OnInputBlur() {
    //Virtual
}

void WindowListener::OnMouseFocus() {
    //Virtual
}

void WindowListener::OnMouseBlur() {
    //Virtual
}

void WindowListener::OnResize(int w,int h) {
    //Virtual
}

void WindowListener::OnExit() {
    //Virtual
}
