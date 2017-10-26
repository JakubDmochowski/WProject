#pragma once

#include "Renderable.h"
#include "Font.h"
#include "CRender.h"
#include <string>
#include <SDL.h>

class Text {
    static unsigned int IDCounter;
    unsigned int Id;
    Font font;
    RenderablePtr renderable;
    std::string content;
    public:
        Text(const std::string text = "");
        ~Text();
        void render();
};
