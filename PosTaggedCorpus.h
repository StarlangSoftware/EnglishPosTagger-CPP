//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#ifndef POSTAGGER_POSTAGGEDCORPUS_H
#define POSTAGGER_POSTAGGEDCORPUS_H

#include <CounterHashMap.h>
#include <Corpus.h>

class PosTaggedCorpus : public Corpus {
private:
    CounterHashMap<string> tagList;
public:
    PosTaggedCorpus();
    PosTaggedCorpus emptyCopy();
    explicit PosTaggedCorpus(string fileName);
    unordered_set<string> getTagList();
};


#endif //POSTAGGER_POSTAGGEDCORPUS_H
