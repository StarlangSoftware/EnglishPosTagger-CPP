//
// Created by olcay on 22/01/2019.
//

#ifndef POSTAGGER_NAIVEPOSTAGGER_H
#define POSTAGGER_NAIVEPOSTAGGER_H

#include <map>
#include "PosTaggedCorpus.h"
#include "PosTagger.h"

using namespace std;

class NaivePosTagger : public PosTagger {
private:
    map<string, string> maxMap;
public:
    NaivePosTagger() = default;
    explicit NaivePosTagger(ifstream& inputFile);
    void train(const PosTaggedCorpus& corpus) override;
    Sentence posTag(Sentence& sentence) override;
};


#endif //POSTAGGER_NAIVEPOSTAGGER_H
