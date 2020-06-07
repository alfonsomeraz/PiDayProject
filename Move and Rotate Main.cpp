#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dave Station");
    sf::Texture backGround;
    sf::Sprite backGround2;
    backGround.loadFromFile("wave.png");
    backGround2.setTexture(backGround);
    backGround2.setScale(5,4.75);
    Animation magicCarpet("magic carpet.png", 0, 0, 1, 5);
    magicCarpet.scale(4,4);
    magicCarpet.setPosition(100, 25);
    magicCarpet.setTime(250);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(backGround2);

        magicCarpet.animate();
        window.draw(magicCarpet);
        sf::Vector2f moveCarpet({.1,.1});
        sf::Vector2f carpetTarget({1000, 1000});
        magicCarpet.move(moveCarpet, carpetTarget);
        magicCarpet.rotate(.1, 90);
        window.display();
    }
    return 0;
}
