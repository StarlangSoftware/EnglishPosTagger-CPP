//
// Created by olcay on 22/01/2019.
//

#include "NaivePosTagger.h"
#include "PosTaggedWord.h"

void NaivePosTagger::train(PosTaggedCorpus& corpus) {
    map<string, CounterHashMap<string>> map;
    for (int i = 0; i < corpus.sentenceCount(); i++){
        Sentence* s = corpus.getSentence(i);
        for (int j = 0; j < s->wordCount(); j++){
            auto word = (PosTaggedWord*) (corpus.getSentence(i)->getWord(j));
            if (map.find(word->getName()) != map.end()){
                map.find(word->getName())->second.put(word->getTag());
            } else {
                CounterHashMap<string> counterMap;
                counterMap.put(word->getTag());
                map.emplace(word->getName(), counterMap);
            }
        }
    }
    for (auto item = map.begin(); item != map.end(); item++){
        maxMap.emplace(item->first, item->second.max());
    }
}

Sentence NaivePosTagger::posTag(Sentence& sentence) {
    Sentence result;
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), maxMap.find(sentence.getWord(i)->getName())->second));
    }
    return result;
}
