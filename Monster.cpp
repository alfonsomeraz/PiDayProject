//
// Created by Quinn Conn on 6/1/20.
//

#include <iostream>
#include "Monster.h"
#include <SFML/Graphics.hpp>

Monster::Monster() : movingRight(0, 170, 125, 50){
    monster.loadFromFile("monsterSheet.png");
    monsterSprite.setTexture(monster);
    monsterSprite.setScale(3, 3);
    monsterSprite.setPosition({100, -150}); //where monster will appear in screen
}

Monster::Monster(int top) : Monster(){
    movingRight.top = top;
}

void Monster::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(monsterSprite);
}

void Monster::monsterAnimate(sf::RenderWindow& window, char direction){

    monsterSprite.setTextureRect(movingRight);

    if(direction == 'R') {
        if (clock.getElapsedTime().asMilliseconds() > 500.0f) {
            if (movingRight.left == (monster.getSize().x / 3) * 2) {
                movingRight.left = 0;
            } else {
                movingRight.left += (monster.getSize().x / 3);
            }
            monsterSprite.setTextureRect(movingRight);
            clock.restart();
        }
        sf::Vector2u winSize = window.getSize();
        sf::Vector2f ms = monsterSprite.getPosition();
        sf::FloatRect what = monsterSprite.getGlobalBounds();
        if (ms.x + what.width < (winSize.x + 375.f)) {
            monsterSprite.setPosition(ms.x + .25, 800);
            if(monsterSprite.getPosition().x >= (winSize.x)){
                monsterSprite.setPosition(-500, 700);
            }
        }
    }

    if(direction == 'L'){
        if (clock.getElapsedTime().asMilliseconds() > 500.0f) {
            if (movingRight.left == (monster.getSize().x / 3) * 2) {
                movingRight.left = 0;
            } else {
                movingRight.left += (monster.getSize().x / 3);
            }
            monsterSprite.setTextureRect(movingRight);
            clock.restart();
        }
        sf::Vector2u winSize = window.getSize();
        sf::Vector2f ms = monsterSprite.getPosition();
        sf::FloatRect what = monsterSprite.getGlobalBounds();
        if (ms.x + what.width >= -375.f){
            monsterSprite.setPosition(ms.x + -.25, 800);
            if(monsterSprite.getPosition().x < (-400)){
                monsterSprite.setPosition(1920, 700);
            }
        }
    }
}

void Monster::monsterMove(sf::Vector2f position){
    monsterSprite.move(position);
}

sf::FloatRect Monster::getGlobalBounds(){
    return monsterSprite.getGlobalBounds();
}

sf::Vector2f Monster::getPosition(){
    return monsterSprite.getPosition();
}

void Monster::setPosition(float x, float y){
    monsterSprite.setPosition(x, y);
}
