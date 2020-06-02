// Modified by Alyssa Ng on 6/2/20.
// Created by Venus Nguyen on 5/31/20.
//

#include "Animate.h"
#include <iostream>

Animate::Animate()
{}

Animate::Animate(std::string spriteName, float left, float top, int width, int height)
{
    if (!texture.loadFromFile(spriteName))
        exit(1);
    setTextureRect(left, top, width, height);
    sprite.setTexture(texture);
    sprite.setTextureRect(textureRect);
}
// instead of sf::Texture texture -> string::

void Animate::setTextureRect(float left, float top, int width, int height) //sets position + size of rectangle
{
    textureRect.left = left;
    textureRect.top = top;
    textureRect.width = width;
    textureRect.height = height;
}

void Animate::setTime(float time)
{
    this->time = time;
}

void Animate::animation()
{
    if (clock.getElapsedTime().asMilliseconds() > time)
    {
        if (textureRect.left >= (texture.getSize().x - textureRect.width))
            textureRect.left = 0;
        else
            textureRect.left += textureRect.width;

        sprite.setTextureRect(textureRect);
        clock.restart();
    }
}

void Animate::setScale(sf::Vector2f factor)
{
    sprite.setScale(factor);
}

void Animate::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(sprite);
}

void Animate::move(float offsetX, float offsetY)
{
    sf::Vector2f pos = sprite.getPosition();
    sprite.setPosition(pos.x + offsetX, pos.y + offsetY);
}

void Animate::rotate(float angle)
{
    sprite.setRotation(sprite.getRotation() + angle);
}
