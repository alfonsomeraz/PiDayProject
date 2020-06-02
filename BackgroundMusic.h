//
// Created by Venus Nguyen on 5/31/20.
//

#ifndef FINALPROJECT_BACKGROUNDMUSIC_H
#define FINALPROJECT_BACKGROUNDMUSIC_H
#include <SFML/Audio.hpp>
#include <string>


class BackgroundMusic : sf::Music{
public:
    BackgroundMusic();
    void play();
    enum states
    {
        BACKGROUND,
        WIN,
        LOSE,
        LASTTRIES,
        POP
    };
    states state = BACKGROUND;

private:
    std::string _fileMusic;
    sf::Music music;
};


#endif //FINALPROJECT_BACKGROUNDMUSIC_H
