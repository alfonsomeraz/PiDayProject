//
// Created by Venus Nguyen on 6/6/20.
//

#include "GameFunction.h"

GameFunction::GameFunction()
{}

GameFunction::GameFunction(std::string fileName) : wordsFile(fileName),
                                                   button(810, 525, 250, 100, "Play Again"),
                                                   littleGirl("swingGirl.png", 0,0, 1, 10),
                                                   water("wave.png", 0, 0, 1, 2),
                                                   balloon1("Balloons2.png"),
                                                   balloon2("Balloons2.png"),
                                                   balloon3("Balloons2.png"),
                                                   balloon4("Balloons2.png"),
                                                   balloon5("Balloons2.png"),
                                                   magicCarpet("Magic Carpet.png",0,0,1,5)
{
    water.setScale({7.5, 5.3});
    water.setTime(1000.f);

    wordGraphic.setWord(wordsFile.getNextWord());
    wordGraphic.setPosition(350, 475);
    wordGraphic.setSize(125);

    button.setButtonColor(sf::Color::White);
    button.setTextColor(sf::Color::Black);
    button.setTextSize(48);

    balloon1.setTextureRect(0, 0, 1, 11);
    balloon1.setPosition(1100, 150);
    balloon1.setColumn(5);

    balloon2.setTextureRect(0, 0, 1, 11);
    balloon2.setPosition(1150, 150);
    balloon2.setColumn(5);

    balloon3.setTextureRect(0, 0, 1, 11);
    balloon3.setPosition(1125, 150);
    balloon3.setColumn(5);

    balloon4.setTextureRect(0, 0, 1, 11);
    balloon4.setPosition(1100, 125);
    balloon4.setColumn(5);

    balloon5.setTextureRect(0, 0, 1, 11);
    balloon5.setPosition(1100, 170);
    balloon5.setColumn(5);

    initBalloons();

    littleGirl.setTime(250.f);
    littleGirl.setPosition(littleGirlInitPos.x, littleGirlInitPos.y);

    magicCarpet.setScale({4,4});
    magicCarpet.setTime(250.f);
    magicCarpet.setPosition(0, littleGirl.getPosition().y + littleGirl.getTextureSize().y);
}

void GameFunction::initBalloons()
{
    balloons.clear();
    balloons.push_back(balloon1);
    balloons.push_back(balloon2);
    balloons.push_back(balloon3);
    balloons.push_back(balloon4);
    balloons.push_back(balloon5);

}
void GameFunction::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(water);
    window.draw(wordGraphic);
    window.draw(button);
//    window.draw(balloon1);
//    window.draw(balloon2);
//    window.draw(balloon3);
//    window.draw(balloon4);
//    window.draw(balloon5);
    for(int i=0; i<balloons.size(); i++)
        window.draw(balloons[i]);
    window.draw(littleGirl);
    if (wordGraphic.isReveal())
        window.draw(magicCarpet);
//    if (wordGraphic.isReveal())
//        button.draw(window, state);
}

void GameFunction::addEvent(sf::RenderWindow &window, sf::Event event)
{
//    if(balloon.getState() == Balloons::HIDE && wordGraphic.getState() == WordGraphic::BAD_LETTER)
//        wordGraphic.changeState(WordGraphic::GOOD_LETTER);

    water.animate();
    button.addEvent(window, event);
    wordGraphic.addEvent(window, event);
    littleGirl.animate();
    magicCarpet.animate();

//        littleGirl.moveByGravitation({1,1}, {1090, 1080});
    if(wordGraphic.getState() == WordGraphic::BAD_LETTER)
    {
        littleGirl.moveVertically({0,.1}, {littleGirl.getPosition().x, littleGirl.getPosition().y + 10});
//        if (vectorIndex < balloons.size())
//        {
//            balloons[vectorIndex].changeState(Balloons::POP);
//            balloons[vectorIndex++].animate();
//            balloons[vectorIndex].changeState(Balloons::POP);
//            balloons[vectorIndex].animate();
                balloons.back().changeState(Balloons::POP);
                balloons.back().animate();
//            std::vector<Balloons>::iterator start = balloons.begin();
//            std::vector<Balloons>::iterator end = balloons.end();
            //balloons.erase(start, end);

//        }
    }
    for(int i=0; i<balloons.size(); i++)
    {
        if(balloons[i].getState() == Balloons::HIDE)
        {
            //std::vector<Balloons>::iterator start = balloons.begin();
            //std::vector<Balloons>::iterator end = balloons.end();
            balloons.pop_back();
            wordGraphic.changeState(WordGraphic::GOOD_LETTER);
        }
    }
    if (wordGraphic.isReveal())
    {
        winSequence();
    }
    if (wordGraphic.isReveal() && button.getState() != Button::buttonPressed)
        button.changeState(Button::showButton);
    if (button.isButtonPressed())
    {
        initBalloons();
        wordGraphic.setWord(wordsFile.getNextWord());
        button.changeState(Button::hideButton);
        //set position of little girl to original position
    }
}

void GameFunction::winSequence()
{
//    magicCarpet.setPosition(0, littleGirl.getPosition().y + littleGirl.getTextureSize().y);
    if (magicCarpet.getPosition().x < littleGirl.getPosition().x)
    {
        magicCarpet.move({1,0});
    }
    if (magicCarpet.getPosition().x == littleGirl.getPosition().x)
    {
        magicCarpet.move({1,0});
        littleGirl.move({1,0});
    }
}
//    balloon.addEvents(window, event);
