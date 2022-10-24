//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#ifndef POSTAGGER_POSTAGGEDWORD_H
#define POSTAGGER_POSTAGGEDWORD_H
#include "Dictionary/Word.h"

class PosTaggedWord : public Word {
private:
    string tag;
public:
    PosTaggedWord(const string& name, const string& tag);
    string getTag() const;
};


#endif //POSTAGGER_POSTAGGEDWORD_H
