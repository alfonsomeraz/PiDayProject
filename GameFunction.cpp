//
// Created by Venus Nguyen on 6/6/20.
//

#include "GameFunction.h"

GameFunction::GameFunction()
{}

GameFunction::GameFunction(std::string fileName) : wordsFile(fileName),
                                                   button(810, 525, 250, 100, "Try Again"),
                                                   balloon("Balloons2.png")
{
    wordGraphic.setWord(wordsFile.getNextWord());
    wordGraphic.setPosition(350, 475);
    wordGraphic.setSize(125);

    button.setButtonColor(sf::Color::White);
    button.setTextColor(sf::Color::Black);
    button.setTextSize(48);

    balloon.setTextureRect(0, 0, 1, 11);
    balloon.setPosition(1100, 150);
    balloon.setColumn(5);
}

void GameFunction::setButtonPosition(float x, float y)
{
    button.setButtonPosition(x, y);
}

void GameFunction::setButtonSize(float width, float height)
{
    button.setButtonSize(width, height);
}

void GameFunction::setButtonColor(sf::Color color)
{
    button.setButtonColor(color);
}

void GameFunction::setTextColor(sf::Color color)
{
    button.setTextColor(color);
}

void GameFunction::setTextSize(int size)
{
    button.setTextSize(size);
}

void GameFunction::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(wordGraphic);
    window.draw(button);
    window.draw(balloon);
//    if (wordGraphic.isReveal())
//        button.draw(window, state);
}

void GameFunction::addEvent(sf::RenderWindow &window, sf::Event event)
{
//    if(balloon.getState() == Balloons::HIDE && wordGraphic.getState() == WordGraphic::BAD_LETTER)
//        wordGraphic.changeState(WordGraphic::GOOD_LETTER);

    button.addEvent(window, event);
    wordGraphic.addEvent(window, event);
//    balloon.addEvents(window, event);
    if(wordGraphic.getState() == WordGraphic::BAD_LETTER)
    {
        balloon.changeState(Balloons::POP);
//        balloon.animate();
    }


    if (wordGraphic.isReveal() && button.getState() != Button::buttonPressed)
        button.changeState(Button::showButton);
    if (button.isButtonPressed())
    {
        wordGraphic.setWord(wordsFile.getNextWord());
        button.changeState(Button::hideButton);
    }
}