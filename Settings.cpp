#include "Settings.h"

Settings Settings::settings;

Settings::Settings() {
    FILE* file = fopen("./Settings.txt", "r");
    fscanf(file, "ScreenWidth: %d\n", &screen_width);
    fscanf(file, "ScreenHeight: %d\n", &screen_height);
    int fs = 0;
    fscanf(file, "Fullscreen: %d\n", &fs);
    fullscreen = (fs == 1);
    fscanf(file, "FPSCap: %d\n", &FPSCap);
    fclose(file);
}

int Settings::getScreenWidth() const {
    return screen_width;
}

int Settings::getScreenHeight() const {
    return screen_height;
}

bool Settings::getFullscreen() const {
    return fullscreen;
}

int Settings::getFPSCap() const {
    return FPSCap;
}

void Settings::setFullscreen(bool fc) {
    fullscreen = fc;
}

void Settings::setScreenHeight(int height) {
    screen_height = height;
}

void Settings::setScreenWidth(int width) {
    screen_width = width;
}

void Settings::setFPSCap(int cap) {
    FPSCap = cap;
}
