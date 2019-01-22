//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#ifndef POSTAGGER_POSTAGGER_H
#define POSTAGGER_POSTAGGER_H
#include <Sentence.h>
#include "PosTaggedCorpus.h"

class PosTagger{
    virtual void train(PosTaggedCorpus corpus) = 0;
    virtual Sentence posTag(Sentence sentence) = 0;
};
#endif //POSTAGGER_POSTAGGER_H
