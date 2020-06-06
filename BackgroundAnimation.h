// Edited by Alyssa Ng on 6/2/20.
// Created by Venus Nguyen on 5/31/20.
//
#ifndef FINALPROJECT_ANIMATE_H
#define FINALPROJECT_ANIMATE_H
#include <SFML/Graphics.hpp>

class Animate : public sf::Drawable {
public:
    Animate();
    Animate(std::string spriteName, float left, float top, int width, int height); // width and height should be rows + columns; see 6/2/20 Office Hours Recording
    void setTextureRect(float left, float top, int width, int height); 
    void setScale(sf::Vector2f factor);
    void animation();
    void setTime(float time);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void rotate(float angle);
    void move(float offsetLeft, float offsetTop);

private:
    float time;
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect textureRect;
    sf::Sprite sprite;
    std::string spriteName
};

#endif //ANIMATE_H
