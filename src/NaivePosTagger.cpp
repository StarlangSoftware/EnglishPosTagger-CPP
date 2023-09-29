//
// Created by olcay on 22/01/2019.
//

#include <fstream>
#include <iostream>
#include "NaivePosTagger.h"
#include "PosTaggedWord.h"

/**
 * Train method for the Naive pos tagger. The algorithm gets all possible tag list. Then counts all
 * possible tags (with its counts) for each possible word.
 *
 * @param corpus Training data for the tagger.
 */
void NaivePosTagger::train(const PosTaggedCorpus& corpus) {
    map<string, CounterHashMap<string>> map;
    for (int i = 0; i < corpus.sentenceCount(); i++){
        Sentence* s = corpus.getSentence(i);
        for (int j = 0; j < s->wordCount(); j++){
            auto word = (PosTaggedWord*) (s->getWord(j));
            if (map.contains(word->getName())){
                map.find(word->getName())->second.put(word->getTag());
            } else {
                CounterHashMap<string> counterMap;
                counterMap.put(word->getTag());
                map.emplace(word->getName(), counterMap);
            }
        }
    }
    for (auto &item : map) {
        maxMap.emplace(item.first, item.second.max());
    }
}

/**
 * Test method for the Naive pos tagger. For each word, the method chooses the maximum a posterior tag from all
 * possible tag list for that word.
 *
 * @param sentence Sentence to be tagged.
 * @return Annotated (tagged) sentence.
 */
Sentence NaivePosTagger::posTag(Sentence& sentence) {
    Sentence result;
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), maxMap.find(sentence.getWord(i)->getName())->second));
    }
    return result;
}

NaivePosTagger::NaivePosTagger(ifstream &inputFile) {
    int size;
    string name, tag;
    inputFile >> size;
    for (int i = 0; i < size; i++){
        inputFile >> name;
        inputFile >> tag;
        maxMap.insert_or_assign(name, tag);
    }
}
