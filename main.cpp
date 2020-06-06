#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Monster.h"
#include <iostream>



int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dave Station");
    sf::CircleShape shape(125.f);
    sf::Texture backGround;
    sf::Sprite backGround2;
    backGround.loadFromFile("background.png");
    backGround2.setTexture(backGround);
    backGround2.setScale(2,2);

    Monster thing, thing2(85);
    thing2.setPosition(1795, 700);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        thing.monsterAnimate(window, 'R');
        thing2.monsterAnimate(window, 'L');
        window.clear(sf::Color::Black);
        window.draw(backGround2);
        window.draw(thing);
        window.draw(thing2);
        window.display();
    }

    return 0;
}