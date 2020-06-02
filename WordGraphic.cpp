//
// Created by Venus Nguyen on 5/28/20.
//

#include "WordGraphic.h"
#include "Word.h"


WordGraphic::WordGraphic()
{
    if (!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(1);
    text.setCharacterSize(_size);
    text.setFillColor(sf::Color::Black);
    text.setLetterSpacing(5);
    text.setPosition(_pos);
    text.setFont(font);
}

WordGraphic::WordGraphic(std::string _word) : word(_word)
{
    if (!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(1);
    text.setCharacterSize(_size);
    text.setFillColor(sf::Color::Black);
    text.setLetterSpacing(5);
    text.setPosition(_pos);
    text.setFont(font);
    text.setString(word.getWord());
}

void WordGraphic::setSize(int size)
{
    _size = size;
}
void WordGraphic::setPosition(sf::Vector2f pos)
{
    _pos = pos;
}

void WordGraphic::setPosition(float x, float y)
{
    _pos.x = x;
    _pos.y = y;
}

void WordGraphic::setWord(std::string _word)
{
    word = _word;
    if (!font.loadFromFile("OpenSans-Regular.ttf"))
        exit(1);
    text.setCharacterSize(_size);
    text.setFillColor(sf::Color::Black);
    text.setLetterSpacing(5);
    text.setPosition(_pos);
    text.setFont(font);
    text.setString(word.getWord());
}

void WordGraphic::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(text);
}

void WordGraphic::revealLetter(char letter)
{
    word.revealLetter(letter);
    text.setString(word.getWord());
}

void WordGraphic::addEvent(sf::RenderWindow &window, sf::Event event)
{
    if (isalpha(event.key.code))
    {
        char c = event.key.code;
        revealLetter(c);
    }
}

