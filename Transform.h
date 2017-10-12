#pragma once

#include <memory>
#include <SDL.h>

class Transform {
    double x;
    double y;
    int w;
    int h;
    double angle;
    SDL_Point* rotateCenter;

    public:
        SDL_Rect* getRect() const;
        double getAngle() const;
        SDL_Point* getRotateCenter() const;

        void setX(double newX);
        void setY(double newY);
        void setAngle(double newAngle);

        Transform(int w = 0, int h = 0, double x = 0, double y = 0, double angle = 0, SDL_Point* rotateCenter = nullptr);
        ~Transform();
};

typedef std::shared_ptr<Transform> TransformPtr;
