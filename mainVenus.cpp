#include <SFML/Graphics.hpp>
#include "BackgroundMusic.h"
#include "GameFunction.h"

int main()
{
    sf::VideoMode video(1920, 1200, 32);
    sf::RenderWindow window(video, "Game");

    BackgroundMusic music;
    music.play();

    GameFunction button("words.txt");


    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        button.addEvent(window, event);



        window.clear();
        window.draw(button);
        window.display();
    }


    return 0;
}
