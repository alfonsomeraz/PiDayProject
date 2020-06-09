//
// Created by Dave Smith on 6/4/20.
//

#ifndef SFML_CLICKABLE_BALLOON_H
#define SFML_CLICKABLE_BALLOON_H
#include <SFML/Graphics.hpp>

class Balloon : public sf::Drawable {


public:
    void animate();
    Balloon();
    void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    enum states{
        SHOWING,
        POPPED,
        HIDDEN
    };
    states getState() const;
    void changeState(states state);

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect textureRect;

    sf::Sprite spriteStill;
    sf::Texture textureStill;
    sf::IntRect textureRectStill;

    sf::Clock clock;
    states state = SHOWING;
};


#endif //SFML_CLICKABLE_BALLOON_H
