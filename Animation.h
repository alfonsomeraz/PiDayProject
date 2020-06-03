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
    Animation(std::string fileName, int left, int top, int width, int height);
    void setTextureRect(int left, int top, int width, int height);
    void setScale(sf::Vector2f size);
    void setTime(float time);
    void animation();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    float _time = 1000.f;
    int _left{};
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect sourceSprite;
    sf::Sprite sprite;
    std::string _fileName;
};


#endif //FINALPROJECT_ANIMATION_H
