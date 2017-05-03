#include "MouseListener.h"

vector<MouseListener*> MouseListener::mouseListeners;

MouseListener::MouseListener() {
    mouseListeners.push_back(this);
}

MouseListener::~MouseListener() {
    //Virtual
}

void MouseListener::OnMouseWheel(bool Up, bool Down) {
    //Virtual
}

void MouseListener::OnLButtonDown(int mX, int mY) {
    //Virtual
}

void MouseListener::OnLButtonUp(int mX, int mY) {
    //Virtual
}

void MouseListener::OnRButtonDown(int mX, int mY) {
    //Virtual
}

void MouseListener::OnRButtonUp(int mX, int mY) {
    //Virtual
}

void MouseListener::OnMButtonDown(int mX, int mY) {
    //Virtual
}

void MouseListener::OnMButtonUp(int mX, int mY) {
    //Virtual
}

void MouseListener::OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle) {
    //Virtual
}
