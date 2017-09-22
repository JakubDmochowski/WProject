#include "Renderable.h"

Renderable::Renderable() {
    src = NULL;
    dst = NULL;
    angle = 50;
    rotateCenter = NULL;
}

Renderable::~Renderable(){
    delete src;
    delete dst;
    delete rotateCenter;
}
