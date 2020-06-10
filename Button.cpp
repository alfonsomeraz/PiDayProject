//
// Created by Venus Nguyen on 6/3/20.
//

#include "Button.h"

Button::Button()
{}

Button::Button(float x, float y, float width, float height, std::string text)
{
    setButtonPosition(x,y);
    setButtonSize(width, height);
    button.setFillColor(sf::Color::White);

    if (!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(1);
    _text.setFont(font);
    _text.setFillColor(sf::Color::Blue);
    _text.setString(text);
    setTextSize(characterSize);
}

void Button::setButtonPosition(float x, float y)
{
    pos.x = x;
    pos.y = y;
    button.setPosition(pos);
}

void Button::setButtonSize(float width, float height)
{
    buttonSize.x = width;
    buttonSize.y = height;
    button.setSize(buttonSize);
}

void Button::setButtonColor(sf::Color color)
{
    button.setFillColor(color);
}

void Button::setTextColor(sf::Color color)
{
    _text.setFillColor(color);
}

void Button::setTextSize(int size)
{
    characterSize = size;
    _text.setCharacterSize(characterSize);
    centerText();
}

void Button::centerText()
{
    sf::Vector2f position;
    position.x = button.getPosition().x + button.getGlobalBounds().width / 2.f - _text.getGlobalBounds().width / 2.f;
    position.y = button.getPosition().y + button.getGlobalBounds().height / 2.f - _text.getGlobalBounds().height / 2.f;
    _text.setPosition(position);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    if (this -> state == showButton)
    {
        window.draw(button);
        window.draw(_text);
    }
}

void Button::addEvent(sf::RenderWindow &window, sf::Event event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
        sf::FloatRect bPos = button.getGlobalBounds();

        if (bPos.contains(mPos) && state != hideButton)
        {
            changeState(buttonPressed);
        }
    }
}

bool Button::isButtonPressed() const
{
    return state == buttonPressed;
}

bool Button::isButtonHidden() const
{
    return state == hideButton;
}

void Button::changeState(states state)
{
    this->state = state;
}

Button::states Button::getState()
{
    return state;
}
