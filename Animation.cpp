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

Animation::Animation(std::string fileName, float left, float top, int row, int column) : _fileName(fileName), left(left)
{
    if (!texture.loadFromFile(_fileName))
        exit(1);
    width = texture.getSize().x / column;
    height = texture.getSize().y / row;

    sprite.setTexture(texture);
    setTextureRect(left, top, width, height);
    this -> left = left;
}

void Animation::setTextureRect(float left, float top, float width, float height)
{
    sourceSprite.left = left;
    sourceSprite.top = top;
    sourceSprite.width = width;
    sourceSprite.height = height;
    sprite.setTextureRect(sourceSprite);
    this -> left = left;
}

void Animation::setTextureRect(float left, float top, int row, int column)
{
    width = texture.getSize().x / column;
    height = texture.getSize().y / row;

    setTextureRect(left, top, width, height);
    sprite.setTexture(texture);
    this -> left = left;
}

void Animation::setTime(float time)
{
    _time = time;
}

void Animation::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Animation::setOrigin(float x, float y)
{
    sprite.setOrigin(x, y);
}

sf::Vector2<unsigned int> Animation::getTextureSize()
{
    return texture.getSize();
}

sf::IntRect& Animation::getTextureRect()
{
    return sourceSprite;
}

void Animation::animate()
{
    if (clock.getElapsedTime().asMilliseconds() > _time)
    {
        if (sourceSprite.left >= (texture.getSize().x - sourceSprite.width))
            sourceSprite.left = left;
        else
            sourceSprite.left += sourceSprite.width;

        sprite.setTextureRect(sourceSprite);
        clock.restart();
    }
}

void Animation::animateLoop()
{
    if (clock.getElapsedTime().asMilliseconds() > 100.f)
    {
        sourceSprite.left += sourceSprite.width;
        sprite.setTextureRect(sourceSprite);
        clock.restart();
    }
}

//void Animation::rotation(float targetAngle)
//{
//    if (clock.getElapsedTime().asSeconds() > .25f)
//    {
//        if (sprite.getRotation() < targetAngle)
//            sprite.rotate(5);
//
//        clock.restart();
//    }
//}

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
    sourceSprite.top = height * (row - 1);
    sprite.setTextureRect(sourceSprite);
}

void Animation::setColumn(int column)
{
    sourceSprite.left = width * (column - 1);
    sprite.setTextureRect(sourceSprite);
}

sf::Vector2f Animation::getPosition()
{
    return sprite.getPosition();
}

void Animation::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(sprite);
}

void Animation::moveByGravitation(sf::Vector2f offset, sf::Vector2f targetPosition)
{
    if (sprite.getPosition().x < targetPosition.x && sprite.getPosition().y < targetPosition.y)
        //sprite.move(offset);
        //sf::Vector2f spritePos = sprite.getPosition();
        sprite.setPosition(sprite.getPosition().x + 1, (sprite.getPosition().x + 1) / 1920.0 * (sprite.getPosition().x + 1) / 1920.0 * 1080.0);
}

void Animation::moveVertically(sf::Vector2f offset, sf::Vector2f targetPosition)
{
//    if (sprite.getPosition().x < targetPosition.x && sprite.getPosition().y < targetPosition.y)
        //sprite.move(offset);
        //sf::Vector2f spritePos = sprite.getPosition();
        sprite.setPosition(sprite.getPosition().x , (sprite.getPosition().y + 1) );
}


void Animation::moveHoriz(sf::Vector2f offset, sf::Vector2f targetPosition)
{
    if (sprite.getPosition().x < targetPosition.x && sprite.getPosition().y < targetPosition.y)
        //sprite.move(offset);
        //sf::Vector2f spritePos = sprite.getPosition();
        sprite.setPosition(sprite.getPosition().x + .1 , (sprite.getPosition().y ) );
}
