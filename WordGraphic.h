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
    WordGraphic(std::string word, float x, float y, int size);
    void setWord(std::string word);
    bool revealLetter(char letter);
    void setSize(int size);
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    bool isReveal() const;
    bool checkLetter(char letter) const;
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void addEvent(sf::RenderWindow &window, sf::Event event);
    enum states { BAD_LETTER, GOOD_LETTER};
    void changeState(states state);
    states getState();
private:

    Word _word;
    sf::Text text;
    sf::Font font;
    int _size = 30;
    sf::Vector2f _pos;
    states state = GOOD_LETTER;
};


#endif //FINALPROJECT_WORDGRAPHIC_H
