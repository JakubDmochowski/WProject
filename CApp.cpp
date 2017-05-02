#define SDL_MAIN_HANDLED
#include "CApp.h"

CApp::CApp() {
    running = true;
}

CApp::~CApp() {
}

int CApp::execute() {
    return 0;
}

int main() {
    CApp app;
    return app.execute();
}
