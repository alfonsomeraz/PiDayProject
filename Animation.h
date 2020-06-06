//
// Created by Venus Nguyen on 5/31/20.
//

#ifndef FINALPROJECT_ANIMATION_H
#define FINALPROJECT_ANIMATION_H
#include <SFML/Graphics.hpp>
#include <string>


class Animation : public sf::Drawable {
public:
    Animation();
    Animation(std::string fileName);
    Animation(std::string fileName, float left, float top, int row, int column);
    void setTextureRect(float left, float top, float width, float height);
    void setScale(sf::Vector2f size);
    void setTime(float time);
    void setPosition(float x, float y);
    void animate();
    void rotate(float angle);
    void move(sf::Vector2f offset);
    void goToRow(int row);
    void setColumn(int column);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    float _time = 1000.f;
    float _left;
    float _width, _height;
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect sourceSprite;
    sf::Sprite sprite;
    std::string _fileName;
};


#endif //FINALPROJECT_ANIMATION_H
