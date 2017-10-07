#include "Renderable.h"
#include "CRender.h"

Renderable::Renderable(const std::string textureName) {
    src = NULL;
    dst = NULL;
    angle = 0;
    rotateCenter = NULL;
    CRender::addRenderableToTexture(this, textureName);
}

Renderable::~Renderable() {
    delete src;
    delete dst;
    delete rotateCenter;
}
