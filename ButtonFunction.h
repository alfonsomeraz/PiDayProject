//
// Created by Venus Nguyen on 6/6/20.
//

#ifndef FINALPROJECT_BUTTONFUNCTION_H
#define FINALPROJECT_BUTTONFUNCTION_H
#include "Animation.h"
#include "Button.h"
#include "WordGraphic.h"
#include "WordsFile.h"
#include <SFML/Graphics.hpp>
#include <string>


class ButtonFunction : public sf::Drawable
{
public:
    ButtonFunction();
    ButtonFunction(std::string fileName);
    void setButtonPosition(float x, float y);
    void setButtonSize(float width, float height);
    void setButtonColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setTextSize(int size);
    void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void addEvent(sf::RenderWindow &window, sf::Event event);

private:
    WordsFile wordsFile;
    WordGraphic wordGraphic;
    Button button;
};


#endif //FINALPROJECT_BUTTONFUNCTION_H
