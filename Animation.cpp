#include "Animation.h"

Animation::Animation(unsigned int _frameWidth, unsigned int _frameHeight, unsigned int _maxFrames, unsigned int _frameInterval, bool _oscilate) : frameWidth(_frameWidth), frameHeight(_frameHeight), maxFrames(_maxFrames), frameInterval(_frameInterval), oscilate(_oscilate) {
    frameShift = frameWidth;
}

Animation::Animation(unsigned int _frameWidth, unsigned int _frameHeight, unsigned int _maxFrames, unsigned int _frameInterval, bool _oscilate, unsigned int _frameShift) : frameWidth(_frameWidth), frameHeight(_frameHeight), maxFrames(_maxFrames), frameInterval(_frameInterval), oscilate(_oscilate), frameShift(_frameShift) {
}

unsigned int Animation::getCurrentFrame() const {
    if(maxFrames == 1) return 0;
    if(oscilate) {
        return abs((int)((timer.getTime() / frameInterval) % (maxFrames * 2 - 2) - maxFrames + 1));
    } else {
        return (timer.getTime() / frameInterval) % maxFrames;
    }
}

SDL_Rect* Animation::getRect() const {
    SDL_Rect* ret = new SDL_Rect();
    ret->w = frameWidth;
    ret->h = frameHeight;
    ret->x = frameShift * getCurrentFrame();
    ret->y = 0;
}

void Animation::freeze() {
    timer.pause();
}

void Animation::unfreeze() {
    timer.unpause();
}
