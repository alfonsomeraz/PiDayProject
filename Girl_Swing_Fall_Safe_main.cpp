//
// Written by Yu-Chung Chang, 6/3/2020
//
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <iostream>

int main()
{

    sf::VideoMode video(1920, 1080, 32);
    sf::RenderWindow window(video, "Girl is Dropping Down");

    sf::Texture backGround;
    sf::Sprite backGround2;

    backGround.loadFromFile("wave.png");
    backGround2.setTexture(backGround);
    backGround2.setScale(5,4.75);

    Animation magicCarpet("MagicCarpetSprite.png", 0, 0, 1, 5);

    //Animation littleGirl("pixil-frame-0.png", 0, 0, 1, 1);
    //Animation littleGirlLose("pixil-frame-0.png", 0, 0, 1, 1);
    //Animation littleGirlWin("pixil-frame-0.png", 0, 0, 1, 1);

    Animation littleGirl("swingGirl.png", 0, 0, 1, 10);
    Animation littleGirlLose("swingGirl.png", 0, 0, 1, 10);
    Animation littleGirlWin("swingGirl.png", 0, 0, 1, 10);

    magicCarpet.scale(4,4);
    magicCarpet.setPosition(100, 25);
    magicCarpet.setTime(250);

    littleGirl.scale(.5,.5);
    littleGirl.setPosition(100, 25);
    littleGirl.setTime(250);

    littleGirlLose.scale(.5,.5);
    //littleGirlLose.setPosition(1000, 600);
    littleGirlLose.setTime(250);

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
        sf::Vector2f carpetTarget({1000, 400});
        magicCarpet.move(moveCarpet, carpetTarget);
        magicCarpet.rotate(.1, 0);

        littleGirl.animate();
        window.draw(littleGirl);
        sf::Vector2f moveGirl({.1,.1});
        sf::Vector2f girlTarget({1000, 600});
        littleGirl.moveByGravity(moveGirl, girlTarget);
        littleGirl.rotateSwing(.0, 0);

        littleGirlLose.animate();
        //window.draw(littleGirl2);
        sf::Vector2f moveGirlLose({0,.1});
        sf::Vector2f girlTargetLose({1090, 1080});
        littleGirl.moveVertically(moveGirlLose, girlTargetLose);
        //littleGirl.move(moveGirlLose, girlTargetLose);
        littleGirl.rotateSwing(.0, 0);

/*
        littleGirlWin.animate();
        //window.draw(littleGirl2);
        sf::Vector2f moveGirlWin({.1,0});
        sf::Vector2f girlTargetWin({1090, 1080});
        littleGirl.moveHoriz(moveGirlWin, girlTargetWin);
        littleGirl.rotateSwing(.1, 0);
*/
        window.display();
    }
    return 0;
}


