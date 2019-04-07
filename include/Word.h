//
// Created by Olcay Taner Yıldız on 23.12.2018.
//

#ifndef DICTIONARY_WORD_H
#define DICTIONARY_WORD_H

#include <string>
#include <fstream>
using namespace std;

class Word {
protected:
    string name;
public:
    Word();
    virtual ~Word() = default;
    Word(string name);
    string to_string();
    int charCount();
    Word clone();
    string getName() const;
    void setName(string name);
    static bool isCapital(string surfaceForm);
    static bool isPunctuation(string surfaceForm);
    static bool isHonorific(string surfaceForm);
    static bool isOrganization(string surfaceForm);
    static bool isMoney(string surfaceForm);
    static bool startsWith(string largeString, string smallString);
    static vector<string> split(string line, string separator);
    static vector<string> split(string line);
    bool isPunctuation();
    static bool isTime(string surfaceForm);
    static Word* toWordArray(string* sourceArray, int size);
    vector<Word> toCharacters();
    friend istream& operator>> (istream& is, Word& word){
        is >> word.name;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Word& word){
        os << word.getName();
        return os;
    }
    bool operator==(const Word &anotherWord) const{
        return (name == anotherWord.name);
    }
    bool operator<(const Word &anotherWord) const{
        return (name < anotherWord.name);
    }
};


#endif //DICTIONARY_WORD_H
