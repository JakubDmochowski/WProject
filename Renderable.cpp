#include "Renderable.h"

Renderable::Renderable() {
    src = NULL;
    dst = NULL;
    angle = 0;
    rotateCenter = NULL;
}

Renderable::~Renderable(){
    delete src;
    delete dst;
    delete rotateCenter;
}
