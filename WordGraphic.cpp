//
// Created by Venus Nguyen on 5/28/20.
//

#include "WordGraphic.h"
#include "Word.h"


WordGraphic::WordGraphic()
{
    if (!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(1);
    text.setFillColor(sf::Color::Black);
    text.setLetterSpacing(5);
    text.setFont(font);
}

WordGraphic::WordGraphic(std::string word, float x, float y, int size) : _word(word)
{
    if (!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(1);
    setSize(size);
    text.setFillColor(sf::Color::Black);
    text.setLetterSpacing(5);
    setPosition(x, y);
    text.setFont(font);
    text.setString(_word.getWord());
}

void WordGraphic::setSize(int size)
{
    _size = size;
    text.setCharacterSize(_size);
}

void WordGraphic::setPosition(sf::Vector2f pos)
{
    _pos = pos;
    text.setPosition(_pos);
}

void WordGraphic::setPosition(float x, float y)
{
    _pos.x = x;
    _pos.y = y;
    text.setPosition(_pos);
}

void WordGraphic::setWord(std::string word)
{
    _word = word;
    if (!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(1);
    text.setFillColor(sf::Color::Black);
    text.setLetterSpacing(5);
    text.setFont(font);
    text.setString(_word.getWord());
}

bool WordGraphic::isReveal()
{
    return _word.isReveal();
}

void WordGraphic::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(text);
}

void WordGraphic::revealLetter(char letter)
{
    _word.revealLetter(letter);
    text.setString(_word.getWord());
}

void WordGraphic::addEvent(sf::RenderWindow &window, sf::Event event)
{
    if (event.KeyPressed == sf::Event::KeyPressed)
    {
        if (isalpha(event.key.code))
        {
            char c = event.key.code;
            revealLetter(c);
        }
    }
}

