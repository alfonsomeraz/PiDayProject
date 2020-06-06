//
// Created by Venus Nguyen on 5/31/20.
//

#include "BackgroundMusic.h"

BackgroundMusic::BackgroundMusic()
{}

void BackgroundMusic::play()
{
    switch (state) {
        case BACKGROUND:
            _fileMusic = "background.wav";
            break;
        case LOSE:
            _fileMusic = "lose.wav";
            break;
        case WIN:
            _fileMusic = "win.wav";
            break;
        case LASTTRIES:
            _fileMusic = "last tries.wav";
            break;
        case POP:
            _fileMusic = "pop.wav";
    }

    if (!music.openFromFile(_fileMusic))
        exit(1);
    music.play();
}
