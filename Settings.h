#pragma once

#include <cstdio>
#include "FPS.h"

class Settings {
    Settings();
    static int screen_width;
    static int screen_height;
    static bool fullscreen;
    static int FPSCap;

    public:
        static void initialize();

        static int getScreenWidth();
        static int getScreenHeight();
        static bool getFullscreen();
        static int getFPSCap();

        static void setScreenWidth(int width);
        static void setScreenHeight(int height);
        static void setFullscreen(bool fc);
        static void setFPSCap(int cap);
};
