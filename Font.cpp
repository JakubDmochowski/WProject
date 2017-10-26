#include "Font.h"

Font::Font(std::string _font, int _fontSize) : fontSize(_fontSize) {
    std::string tmpStr = "./fonts/";
    tmpStr.append(_font);
    tmpStr.append(".ttf");
    fontColor.r = 0;
    fontColor.g = 0;
    fontColor.b = 0;
    fontColor.a = 255;
    font = TTF_OpenFont(tmpStr.c_str(), fontSize);
}

Font::~Font() {
}

void Font::setColor(int R, int G, int B, int A) {
    this->fontColor.r = R;
    this->fontColor.g = G;
    this->fontColor.b = B;
    this->fontColor.a = A;
}

void Font::setColor(const SDL_Color& toSet) {
    this->fontColor = toSet;
}

SDL_Color Font::getColor() const {
    return fontColor;
}

void Font::setStyle(int style) {
    TTF_SetFontStyle(font, style);
}

TTF_Font* Font::get() const {
    return font;
}
