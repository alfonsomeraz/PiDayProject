//
// Created by Venus Nguyen on 6/6/20.
//

#include "ButtonFunction.h"

ButtonFunction::ButtonFunction()
{}

ButtonFunction::ButtonFunction(std::string fileName) : wordsFile(fileName),
                                                       button(810, 525, 250, 100, "Try Again")
{
    wordGraphic.setWord(wordsFile.getNextWord());
    wordGraphic.setPosition(350, 475);
    wordGraphic.setSize(125);

    button.setButtonColor(sf::Color::White);
    button.setTextColor(sf::Color::Black);
    button.setTextSize(48);
}

void ButtonFunction::setButtonPosition(float x, float y)
{
    button.setButtonPosition(x, y);
}

void ButtonFunction::setButtonSize(float width, float height)
{
    button.setButtonSize(width, height);
}

void ButtonFunction::setButtonColor(sf::Color color)
{
    button.setButtonColor(color);
}

void ButtonFunction::setTextColor(sf::Color color)
{
    button.setTextColor(color);
}

void ButtonFunction::setTextSize(int size)
{
    button.setTextSize(size);
}

void ButtonFunction::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(wordGraphic);
    if (wordGraphic.isReveal())
        button.draw(window, state);
}

void ButtonFunction::addEvent(sf::RenderWindow &window, sf::Event event)
{
    button.addEvent(window, event);
    wordGraphic.addEvent(window, event);
    if (button.isButtonPressed())
    {
        wordGraphic.setWord(wordsFile.getNextWord());
        button.changeState(Button::hideButton);
    }
}