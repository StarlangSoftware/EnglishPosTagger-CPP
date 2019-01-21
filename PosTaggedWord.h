//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#ifndef POSTAGGER_POSTAGGEDWORD_H
#define POSTAGGER_POSTAGGEDWORD_H
#include <Word.h>

class PosTaggedWord : public Word {
private:
    string tag;
public:
    PosTaggedWord(string name, string tag);
    string getTag();
};


#endif //POSTAGGER_POSTAGGEDWORD_H
