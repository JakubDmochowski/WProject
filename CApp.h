#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <ctime>
#include <cstdio>

#include "define.h"

class CApp {
    public:
        bool running;

        CApp();
        ~CApp();

        int execute();
};

#endif // _CAPP_H_
