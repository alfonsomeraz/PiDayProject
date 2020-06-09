//
// Created by Dave Smith on 6/4/20.
//

#include "Balloon.h"

void Balloon::animate()
{
    if(clock.getElapsedTime().asMilliseconds() > 100.f) {
//        if (textureRect.left >= 900)
//            textureRect.left = 0;
//        else {
            textureRect.left += textureRect.width;
            sprite.setTextureRect(textureRect);
            clock.restart();
        //}
    }
    if(textureRect.left > texture.getSize().x - textureRect.width)
        changeState(HIDDEN);


}

Balloon::Balloon()
{

    if(texture.loadFromFile("balloons2.png"))
    {
        sprite.setTexture(texture);
        textureRect.left = 0;
        textureRect.top = 0;
        textureRect.width = texture.getSize().x/11.f;
        textureRect.height = texture.getSize().y/4.f;
        sprite.setTextureRect(textureRect);

    }
    if(textureStill.loadFromFile("balloons2.png"))
    {
        spriteStill.setTexture(texture);
        textureRectStill.left = 0;
        textureRectStill.top = 0;
        textureRectStill.width = textureStill.getSize().x/11.f;
        textureRectStill.height = textureStill.getSize().y/4.f;
        spriteStill.setTextureRect(textureRectStill);


    }
}

void Balloon::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    if(getState() == SHOWING)
        window.draw(spriteStill);
    else if(getState() == POPPED)
        window.draw(sprite);

}

Balloon::states Balloon::getState() const
{
    return state;
}

void Balloon::changeState(states state)
{
    this->state = state;
}
