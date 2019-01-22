//
// Created by olcay on 22/01/2019.
//

#ifndef POSTAGGER_HMMPOSTAGGER_H
#define POSTAGGER_HMMPOSTAGGER_H
#include <Word.h>
#include "Hmm1.h"
#include "PosTaggedCorpus.h"

class HmmPosTagger {
private:
    Hmm1<string, Word> hmm;
public:
    void train(PosTaggedCorpus corpus);
    Sentence posTag(Sentence sentence);
};


#endif //POSTAGGER_HMMPOSTAGGER_H
