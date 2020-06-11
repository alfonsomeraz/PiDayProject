//
// Created by Venus Nguyen on 6/6/20.
//

#ifndef FINALPROJECT_GAMEFUNCTION_H
#define FINALPROJECT_GAMEFUNCTION_H
#include "Animation.h"
#include "Balloons.h"
#include "Button.h"
#include "WordGraphic.h"
#include "WordsFile.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


class GameFunction : public sf::Drawable
{
public:
    GameFunction();
    GameFunction(std::string fileName);
    void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void addEvent(sf::RenderWindow &window, sf::Event event);


private:
    WordsFile wordsFile;
    WordGraphic wordGraphic;
    Button button;
    Balloons balloon1, balloon2, balloon3, balloon4, balloon5;
    Animation littleGirl;
    Animation water;
    Animation magicCarpet;
    std::vector<Balloons> balloons;
    int vectorIndex = 4;
    void initBalloons();
    void winSequence();
    sf::Vector2f littleGirlInitPos = {1070, 300}; //should be private member of its own class, but don't have enough time to make change rn
};


#endif //FINALPROJECT_GAMEFUNCTION_H
