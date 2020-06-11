//
// Created by Venus Nguyen on 5/27/20.
//

#ifndef FINALPROJECT_WORD_H
#define FINALPROJECT_WORD_H
#include <string>
#include <fstream>

class Word {
public:
    Word();
    Word(std::string _word);
    std::string getWord();
    bool checkLetter(char letter) const;
    bool isReveal() const;
    bool revealLetter(char letter);
    void hideWord();

private:
    std::string word;
    std::string ogWord;
};


#endif //FINALPROJECT_WORD_H
