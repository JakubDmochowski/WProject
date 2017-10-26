#include "Transform.h"

Transform::Transform(int _w, int _h, double _x, double _y, double _angle, SDL_Point* _rotateCenter) : x(_x), y(_y), w(_w), h(_h), angle(_angle), rotateCenter(_rotateCenter) {
}

Transform::Transform(const Transform& toCopy) {
    SDL_Rect* copyRect = toCopy.getRect();
    x = copyRect->x;
    y = copyRect->y;
    w = copyRect->w;
    h = copyRect->h;
    angle = toCopy.getAngle();
    SDL_Point* copyRotateCenter = new SDL_Point();
    copyRotateCenter->x = toCopy.getRotateCenter()->x;
    copyRotateCenter->y = toCopy.getRotateCenter()->y;
    rotateCenter = copyRotateCenter;
}

Transform::~Transform() {
}

SDL_Rect* Transform::getRect() const {
    SDL_Rect* ret = new SDL_Rect();
    ret->x = x;
    ret->y = y;
    ret->w = w;
    ret->h = h;
    return ret;
}

double Transform::getAngle() const {
    return angle;
}

SDL_Point* Transform::getRotateCenter() const {
    return rotateCenter;
}

void Transform::setX(double newX) {
    x = newX;
}

void Transform::setY(double newY) {
    y = newY;
}

void Transform::setAngle(double newAngle) {
    angle = newAngle;
}
