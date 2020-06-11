//
// Created by Venus Nguyen on 6/8/20.
//

#include "Balloons.h"

Balloons::Balloons()
{}

Balloons::Balloons(std::string fileName)
        : balloon(fileName), balloonStill(fileName)
{}

Balloons::Balloons(std::string fileName, float left, float top, int row, int column)
        : balloon(fileName), balloonStill(fileName)
{
    setTextureRect(left, top, row, column);
}

void Balloons::setTextureRect(float left, float top, int row, int column)
{
    balloon.setTextureRect(left, top, row, column);
    balloonStill.setTextureRect(left, top, row, column);
}

void Balloons::setScale(float x, float y)
{
    balloon.setScale({x, y});
    balloonStill.setScale({x, y});
}

void Balloons::setPosition(float x, float y)
{
    balloon.setPosition(x, y);
    balloonStill.setPosition(x, y);
}

void Balloons::setOrigin(float x, float y)
{
    balloon.setOrigin(x, y);
    balloonStill.setOrigin(x, y);
}

void Balloons::setColumn(int column)
{
    balloon.setColumn(column);
    balloonStill.setColumn(column);
}

void Balloons::rotate(float angle)
{
    balloon.rotate(angle);
    balloonStill.rotate(angle);
}

sf::IntRect& Balloons::getTextureRect()
{
    return balloon.getTextureRect();
}

void Balloons::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    if (getState() == SHOW)
        window.draw(balloonStill);
    else if (getState() == POP)
        window.draw(balloon);
}

void Balloons::animate()
{
    balloon.animateLoop();
    if (balloon.getTextureRect().left >= balloon.getTextureSize().x - balloon.width)
    {
        changeState(HIDE);
    }
}

void Balloons::changeState(states state)
{
    this -> state = state;
}

Balloons::states Balloons::getState() const
{
    return state;
}

void Balloons::addEvents(sf::RenderWindow& window, sf::Event event)
{
    if(state == POP && event.type)
        animate();
}
