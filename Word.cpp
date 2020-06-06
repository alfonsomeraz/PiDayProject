//
// Created by Venus Nguyen on 5/27/20.
//

#include "Word.h"
#include <string>
#include <cctype>


Word::Word()
{}

Word::Word(std::string word)
{
    ogWord = word;
    hideWord();
}

//bool Word::checkLetter(char letter)
//{
//    int index = ogWord.find(letter);
//    return index != std::string::npos;
//}

std::string Word::getWord()
{
    return word;
}

bool Word::isReveal()
{
    for (int i = 0; i < ogWord.length(); i++)
    {
        if (word.at(i) == '_')
            return false;
    }
    return true;
}

void Word::revealLetter(char letter)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (ogWord.at(i) == letter)
            word.at(i) = letter;
    }
}

void Word::hideWord()
{
    word = "";
    for (int i = 0; i < ogWord.length(); i++)
    {
        word += '_';
    }
}