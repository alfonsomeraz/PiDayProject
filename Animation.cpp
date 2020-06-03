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

Animation::Animation(std::string fileName, int left, int top, int width, int height) : _fileName(fileName), _left(left)
{
    if (!texture.loadFromFile(_fileName))
        exit(1);
    setTextureRect(left, top, width, height);
    sprite.setTexture(texture);
    sprite.setTextureRect(sourceSprite);
}

void Animation::setTextureRect(int left, int top, int width, int height)
{
    sourceSprite.left = left;
    sourceSprite.top = top;
    sourceSprite.width = width;
    sourceSprite.height = height;
    _left = left;
}

void Animation::setTime(float time)
{
    _time = time;
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

void Animation::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(sprite);
}

