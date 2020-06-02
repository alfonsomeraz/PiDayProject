//
// Created by Venus Nguyen on 5/31/20.
//

#ifndef FINALPROJECT_BACKGROUNDANIMATION_H
#define FINALPROJECT_BACKGROUNDANIMATION_H
#include <SFML/Graphics.hpp>


class BackgroundAnimation : public sf::Drawable {
public:
    BackgroundAnimation();
    BackgroundAnimation(sf::Texture _texture);
    void setSprite(int left, int top, int width, int height);
    void setScale(sf::Vector2f size);
    void animation();
    void setTime(float time);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

private:
    float _time;
    sf::Texture texture;
    sf::Clock clock;
    sf::IntRect sourceSprite;
    sf::Sprite sprite;
};


#endif //FINALPROJECT_BACKGROUNDANIMATION_H
