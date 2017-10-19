#include "Renderable.h"
#include "CRender.h"

Renderable::Renderable(const std::string _textureName, TransformPtr _transform) : transform(_transform), textureName(_textureName) {
}

Renderable::Renderable(const Renderable& toCopy) {
    textureName = toCopy.textureName;
    transform = std::make_shared<Transform>(*transform);
}

Renderable::~Renderable() {
}

RenderablePtr Renderable::create(const std::string textureName, TransformPtr transform) {
    RenderablePtr temp(new Renderable(textureName, transform));
    CRender::addRenderableToTexture(temp);
    return temp;
}

SDL_Rect* Renderable::getSrc() const {
    ///TODO
    return nullptr;
}

SDL_Rect* Renderable::getDst() const {
    return transform == nullptr ? nullptr : transform->getRect();
}

double Renderable::getAngle() const {
    return transform == nullptr ? 0 : transform->getAngle();
}

SDL_Point* Renderable::getRotateCenter() const {
    return transform == nullptr ? nullptr : transform->getRotateCenter();
}

std::string Renderable::getTextureName() const {
    return textureName;
}
