#include "Renderable.h"
#include "CRender.h"

Renderable::Renderable(const std::string _textureName, TransformPtr _transform) : transform(_transform), textureName(_textureName) {
}

Renderable::Renderable(const Renderable& toCopy) {
    textureName = toCopy.textureName;
    transform = std::make_shared<Transform>(*transform);
}

RenderablePtr Renderable::create(const std::string textureName, TransformPtr transform, AnimationPtr animation) {
    RenderablePtr temp(new Renderable(textureName, transform));
    temp->animation = std::move(animation);
    CRender::addRenderableToTexture(temp);
    return temp;
}

SDL_Rect* Renderable::getSrc() const {
    if(animation == nullptr) return nullptr;
    return animation->getRect();
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
