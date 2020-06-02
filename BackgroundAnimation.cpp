//
// Created by Venus Nguyen on 5/31/20.
//

#include "BackgroundAnimation.h"
#include <iostream>

BackgroundAnimation::BackgroundAnimation()
{}

BackgroundAnimation::BackgroundAnimation(sf::Texture _texture)
{
    texture = _texture;
    sprite.setTexture(texture);
    sprite.setTextureRect(sourceSprite);
}

void BackgroundAnimation::setSprite(int left, int top, int width, int height)
{
    sourceSprite.left = left;
    sourceSprite.top = top;
    sourceSprite.width = width;
    sourceSprite.height = height;
}

void BackgroundAnimation::setTime(float time)
{
    _time = time;
}

void BackgroundAnimation::animation()
{
    if (clock.getElapsedTime().asMilliseconds() > _time)
    {
        if (sourceSprite.left >= (texture.getSize().x - sourceSprite.width))
            sourceSprite.left = 0;
        else
            sourceSprite.left += sourceSprite.width;

        sprite.setTextureRect(sourceSprite);
        clock.restart();
    }
}

void BackgroundAnimation::setScale(sf::Vector2f size)
{
    sprite.setScale(size);
}

void BackgroundAnimation::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(sprite);
}

