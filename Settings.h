#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <cstdio>
#include "FPS.h"

class Settings {
    Settings();
    int screen_width;
    int screen_height;
    bool fullscreen;

    public:
        static Settings settings;
        int getScreenWidth() const;
        int getScreenHeight() const;
        bool getFullscreen() const;

        void setScreenWidth(int width);
        void setScreenHeight(int height);
        void setFullscreen(bool fc);
};

#endif // _SETTINGS_H_
