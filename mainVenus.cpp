#include <iostream>
#include <SFML/Graphics.hpp>
#include "WordGraphic.h"
#include "Animation.h"
#include "WordsFile.h"
#include "BackgroundMusic.h"
#include "Button.h"

int main()
{
    sf::VideoMode video(1920, 1200, 32);
    sf::RenderWindow window(video, "Game");


    BackgroundMusic music;
    music.play();

    WordsFile file("words.txt");
    WordGraphic word;
    word.setPosition(350, 475);
    word.setSize(125);
    word.setWord(file.getNextWord());

    Animation water("wave.png", 0, 0, 1, 2);
    water.setScale({7.5, 5.3});
    water.setTime(1000.f);




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

        water.animate();
        word.addEvent(window, event);



        window.clear();
        window.draw(water);
        window.draw(word);
        window.display();
    }


    return 0;
}
