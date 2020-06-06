//
// Created by Venus Nguyen on 5/31/20.
//

#include "Animation.h"
#include <iostream>

Animation::Animation()
{}

Animation::Animation(std::string fileName) : _fileName(fileName)
{
    if (!texture.loadFromFile(_fileName))
        exit(1);
    sprite.setTexture(texture);
    sprite.setTextureRect(sourceSprite);
}

Animation::Animation(std::string fileName, float left, float top, int row, int column) : _fileName(fileName), _left(left)
{
    if (!texture.loadFromFile(_fileName))
        exit(1);
    _width = texture.getSize().x / column;
    _height = texture.getSize().y / row;

    sprite.setTexture(texture);
    setTextureRect(left, top, _width, _height);
    _left = left;
}

void Animation::setTextureRect(float left, float top, float width, float height)
{
    sourceSprite.left = left;
    sourceSprite.top = top;
    sourceSprite.width = width;
    sourceSprite.height = height;
    sprite.setTextureRect(sourceSprite);
    _left = left;
}

void Animation::setTime(float time)
{
    _time = time;
}

void Animation::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Animation::animate()
{
    if (clock.getElapsedTime().asMilliseconds() > _time)
    {
        if (sourceSprite.left >= (texture.getSize().x - sourceSprite.width))
            sourceSprite.left = _left;
        else
            sourceSprite.left += sourceSprite.width;

        sprite.setTextureRect(sourceSprite);
        clock.restart();
    }
}

void Animation::setScale(sf::Vector2f size)
{
    sprite.setScale(size);
}

void Animation::rotate(float angle)
{
    sprite.rotate(angle);
}

void Animation::move(sf::Vector2f offset)
{
    sprite.move(offset);
}

void Animation::goToRow(int row)
{
    sourceSprite.top = _height * (row - 1);
    sprite.setTextureRect(sourceSprite);
}

void Animation::setColumn(int column)
{
    sourceSprite.left = _width * (column - 1);
    sprite.setTextureRect(sourceSprite);
}

void Animation::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(sprite);
}

