//
// Created by Venus Nguyen on 5/31/20.
//

#ifndef FINALPROJECT_WORDSFILE_H
#define FINALPROJECT_WORDSFILE_H
#include <string>
#include <fstream>


class WordsFile {
public:
    WordsFile();
    WordsFile(std::string fileName);
    void setFile(std::string fileName);
    std::string getNextWord();

private:
    std::string _fileName;
    std::ifstream in;
    std::string word;
};


#endif //FINALPROJECT_WORDSFILE_H
