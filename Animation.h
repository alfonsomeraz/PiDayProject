//
// Edited by Yu-Chung Chang on 6/8/20
//
// Edited by Alyssa Ng on 6/7/20.
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
    void scale(float factorX, float factorY);
    void setTime(float time);
    void setPosition(float x, float y);
    void setOrigin(float x, float y);
    void animate();
    void setRotation(float angle);
    void rotate(float rotateBy, float targetAngle);
    void rotateSwing(float rotateBy, float targetAngle);
    void move(sf::Vector2f offset, sf::Vector2f targetPosition);
    void moveByGravitation(sf::Vector2f offset, sf::Vector2f targetPosition);
    void moveVertically(sf::Vector2f offset, sf::Vector2f targetPosition);
    void moveHoriz(sf::Vector2f offset, sf::Vector2f targetPosition);
    void goToRow(int row);
    void setColumn(int column);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    float time = 1000.f;
    float left;
    float width, height;
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect sourceSprite;
    sf::Sprite sprite;
    std::string fileName;


};

#endif //FINALPROJECT_ANIMATION_H
