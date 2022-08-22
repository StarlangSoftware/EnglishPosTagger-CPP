//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#ifndef POSTAGGER_DUMMYPOSTAGGER_H
#define POSTAGGER_DUMMYPOSTAGGER_H

#include "PosTagger.h"
#include "PosTaggedCorpus.h"

class DummyPosTagger : public PosTagger {
private:
    vector<string> tagList;
public:
    DummyPosTagger() = default;
    explicit DummyPosTagger(ifstream& inputFile);
    void train(PosTaggedCorpus& corpus) override;
    Sentence posTag(Sentence& sentence) override;
    void serialize(ostream& outputFile) override;
    void saveModel() override;
};


#endif //POSTAGGER_DUMMYPOSTAGGER_H
