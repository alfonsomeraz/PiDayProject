//
// Created by Quinn Conn on 6/1/20.
//

#ifndef SFML_MONSTER_H
#define SFML_MONSTER_H
#include <SFML/Graphics.hpp>

class Monster : public sf::Drawable{
public:
    Monster();
    //default constructor will set texture and sprite to monsterSheet

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //this is so we can treat Monster objects as drawable

    void monsterAnimate(sf::RenderWindow& window, char direction);
    //animation for monster on screen using this will set it in motion

    void monsterMove(sf::Vector2f position);

    sf::FloatRect getGlobalBounds();

    sf::Vector2f getPosition();

    void setPosition(float x, float y);

    sf::IntRect movingRight;

    Monster(int top);

private:
    sf::Texture monster;
    sf::Sprite monsterSprite;
    sf::Clock clock;
};


#endif //SFML_MONSTER_H
