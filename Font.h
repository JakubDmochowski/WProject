#pragma once

#include <SDL_ttf.h>
#include <string>

class Font {
    SDL_Color    fontColor;
    TTF_Font*    font;

    int         fontSize;
    public:
        Font(std::string _font = "FreeSans", int _fontSize = 12);
        ~Font();
        void setColor(int R, int G, int B, int A = 255);
        void setColor(const SDL_Color& toSet);
        SDL_Color getColor() const;
        void setStyle(int style);
        TTF_Font* get() const;
        /*
        styles:
            TTF_STYLE_BOLD
            TTF_STYLE_ITALIC
            TTF_STYLE_UNDERLINE
            TTF_STYLE_STRIKETHROUGH
            TTF_STYLE_NORMAL

        using more than one style:
            setStyle(TTF_STYLE_BOLD | TTF_STYLE_ITALIC | TTF_STYLE_UNDERLINE);
        */
};
