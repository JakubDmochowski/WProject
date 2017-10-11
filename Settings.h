#pragma once

#include <cstdio>
#include "FPS.h"

class Settings {
    Settings();
    int screen_width;
    int screen_height;
    bool fullscreen;
    int FPSCap;

    public:
        static Settings settings;
        int getScreenWidth() const;
        int getScreenHeight() const;
        bool getFullscreen() const;
        int getFPSCap() const;

        void setScreenWidth(int width);
        void setScreenHeight(int height);
        void setFullscreen(bool fc);
        void setFPSCap(int cap);
};
