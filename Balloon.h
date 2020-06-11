//
// Created by Venus Nguyen on 6/8/20.
//

#ifndef FINALPROJECT_BALLOONS_H
#define FINALPROJECT_BALLOONS_H
#include "Animation.h"
#include "WordGraphic.h"
#include <SFML/Graphics.hpp>
#include <string>


class Balloons : public sf::Drawable
{
public:
    Balloons();
    Balloons(std::string fileName);
    Balloons(std::string fileName, float left, float top, int row, int column);
    void setTextureRect(float left, float top, int row, int column);
    void setScale(float x, float y);
    void setPosition(float x, float y);
    void setOrigin(float x, float y);
    void setColumn(int column);
    void rotate(float angle);
    sf::IntRect& getTextureRect();

    void animate();
    void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void addEvents(sf::RenderWindow& window, sf::Event event);
    enum states
    {
        SHOW,
        HIDE,
        POP
    };
    void changeState(states state);
    states getState() const;

private:
    Animation balloon, balloonStill;
    WordGraphic wordGraphic;
    states state = SHOW;
};


#endif //FINALPROJECT_BALLOONS_H
