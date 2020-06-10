//
// Created by Venus Nguyen on 6/3/20.
//

#ifndef FINALPROJECT_BUTTON_H
#define FINALPROJECT_BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>


class Button : public sf::Drawable
{
public:
    Button();
    Button(float x, float y, float width, float height, std::string text);
    void setButtonPosition(float x, float y);
    void setButtonSize(float width, float height);
    void setButtonColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setTextSize(int size);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void addEvent(sf::RenderWindow &window, sf::Event event);

    enum states
    {
        buttonPressed,
        showButton,
        hideButton
    };
    bool isButtonPressed() const;
    bool isButtonHidden() const;
    void changeState(states state);
    states getState();

private:
    int characterSize = 30;
    void centerText();
    sf::Vector2f pos, buttonSize;
    sf::RectangleShape button;
    sf::Font font;
    sf::Text _text;
    states state = hideButton;
};


#endif //FINALPROJECT_BUTTON_H
