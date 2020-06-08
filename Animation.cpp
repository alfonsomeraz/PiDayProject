//
// Edited by Yu-Chung Chang on 6/8/20
//
// Edited by Alyssa Ng on 6/7/20.
//
// Created by Venus Nguyen on 5/31/20.
//

#include "Animation.h"
#include <iostream>

Animation::Animation()
{}

Animation::Animation(std::string fileName) : fileName(fileName)
{
    if (!texture.loadFromFile(fileName))
        exit(1);
    sprite.setTexture(texture);
    sprite.setTextureRect(sourceSprite);
}

Animation::Animation(std::string fileName, float left, float top, int row, int column)
    : fileName(fileName), left(left)
{
    if (!texture.loadFromFile(fileName))
        exit(1);
    width = texture.getSize().x / column;
    height = texture.getSize().y / row;
    sprite.setTexture(texture);
    setTextureRect(left, top, width, height);
}

void Animation::setTextureRect(float left, float top, float width, float height)
{
    sourceSprite.left = left;
    sourceSprite.top = top;
    sourceSprite.width = width;
    sourceSprite.height = height;
    sprite.setTextureRect(sourceSprite);
}

void Animation::setTime(float time)
{
    this->time = time;
}

void Animation::setPosition(float x, float y)
{
    sprite.setPosition(x, y);
}

void Animation::animate()
{
    if (clock.getElapsedTime().asMilliseconds() > time)
    {
        if (sourceSprite.left >= (texture.getSize().x - sourceSprite.width))
            sourceSprite.left = left;
        else
            sourceSprite.left += sourceSprite.width;

        sprite.setTextureRect(sourceSprite);
        clock.restart();
    }
}

void Animation::scale(float factorX, float factorY)
{
    sf::Vector2f scale = sprite.getScale();
    sprite.setScale(factorX, factorY);
}

void Animation::setRotation(float angle) 
{
    sprite.setRotation(angle);
}

void Animation::rotate(float rotateBy, float targetAngle) // Function WILL infinite loop if if targetAngle % rotateBy != 0
{
    if (sprite.getRotation() != targetAngle)
        sprite.rotate(rotateBy);
}

void Animation::rotateSwing(float rotateBy, float targetAngle)
{
    if (sprite.getRotation() < targetAngle)
        sprite.rotate(rotateBy);
    /*
    if (clock.getElapsedTime().asSeconds() > .25f)
    {
        if (sprite.getRotation() < targetAngle)
            sprite.rotate(5);

        clock.restart();
    }
     */

}

void Animation::move(sf::Vector2f offset, sf::Vector2f targetPosition)
{
    if (sprite.getPosition().x < targetPosition.x && sprite.getPosition().y < targetPosition.y)
            sprite.move(offset);
}

void Animation::moveByGravity(sf::Vector2f offset, sf::Vector2f targetPosition)
{
    if (sprite.getPosition().x < targetPosition.x && sprite.getPosition().y < targetPosition.y)
        //sprite.move(offset);
        //sf::Vector2f spritePos = sprite.getPosition();
        sprite.setPosition(sprite.getPosition().x + .1, (sprite.getPosition().x + .1) / 1920.0 * (sprite.getPosition().x + .1) / 1920.0 * 1080.0);
}

void Animation::moveVertically(sf::Vector2f offset, sf::Vector2f targetPosition)
{
    if (sprite.getPosition().x < targetPosition.x && sprite.getPosition().y < targetPosition.y)
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

void Animation::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(sprite);
}
