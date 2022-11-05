//
// Created by olcay on 22/01/2019.
//

#ifndef POSTAGGER_HMMPOSTAGGER_H
#define POSTAGGER_HMMPOSTAGGER_H
#include "Dictionary/Word.h"
#include "Hmm1.h"
#include "PosTaggedCorpus.h"
#include "PosTagger.h"

class HmmPosTagger : public PosTagger {
private:
    Hmm1<string, Word> hmm;
public:
    HmmPosTagger() = default;
    void train(const PosTaggedCorpus& corpus) override;
    Sentence posTag(Sentence& sentence) override;
};


#endif //POSTAGGER_HMMPOSTAGGER_H
