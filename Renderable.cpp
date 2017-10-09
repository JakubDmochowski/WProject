#include "Renderable.h"
#include "CRender.h"

Renderable::Renderable(const std::string _textureName) : textureName(_textureName) {
    src = NULL;
    dst = NULL;
    angle = 0;
    rotateCenter = NULL;
}

Renderable::~Renderable() {
    delete src;
    delete dst;
    delete rotateCenter;
}

Renderable::Renderable(const Renderable& toCopy) {
    src = toCopy.src;
    dst = toCopy.dst;
    angle = toCopy.angle;
    textureName = toCopy.textureName;
    rotateCenter = toCopy.rotateCenter;
}
