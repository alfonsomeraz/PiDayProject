//
// Created by Venus Nguyen on 5/28/20.
//

#ifndef FINALPROJECT_WORDGRAPHIC_H
#define FINALPROJECT_WORDGRAPHIC_H
#include "Word.h"
#include <SFML/Graphics.hpp>


class WordGraphic : public sf::Drawable{
public:
    WordGraphic();
    WordGraphic(std::string _word);
    void setWord(std::string _word);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void revealLetter(char letter);
    void addEvent(sf::RenderWindow &window, sf::Event event);
    void setSize(int size);
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);

private:
    Word word;
    sf::Text text;
    sf::Font font;
    int _size;
    sf::Vector2f _pos;
};


#endif //FINALPROJECT_WORDGRAPHIC_H
