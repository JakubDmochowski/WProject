#include "Text.h"

unsigned int Text::IDCounter = 0;

Text::Text(std::string text) : content(text) {
    this->Id = ++IDCounter;
    //renderable = Renderable::create(temp);
}

Text::~Text() {
}

void Text::render() {
    ///TODO
}
