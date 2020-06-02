//
// Created by Venus Nguyen on 5/31/20.
//

#include "WordsFile.h"

WordsFile::WordsFile()
{}

WordsFile::WordsFile(std::string fileName)
{
    _fileName = fileName;
    in.open(_fileName);
    if (in.fail())
        exit(1);
}

void WordsFile::setFile(std::string fileName)
{
    _fileName = fileName;
    in.open(_fileName);
    if (in.fail())
        exit(1);
}

std::string WordsFile::getNextWord()
{
    in >> word;
    return word;
}