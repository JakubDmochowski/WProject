#pragma once

#include <SDL.h>
#include <vector>

using namespace std;

struct MouseListener {
        static vector<MouseListener*> mouseListeners;

        MouseListener();
        virtual ~MouseListener();

        virtual void OnMouseWheel(bool Up, bool Down);

        virtual void OnLButtonDown(int mX, int mY);

        virtual void OnLButtonUp(int mX, int mY);

        virtual void OnRButtonDown(int mX, int mY);

        virtual void OnRButtonUp(int mX, int mY);

        virtual void OnMButtonDown(int mX, int mY);

        virtual void OnMButtonUp(int mX, int mY);

        virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
};
