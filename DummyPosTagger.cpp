//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#include <fstream>
#include "DummyPosTagger.h"
#include "PosTaggedWord.h"

void DummyPosTagger::train(PosTaggedCorpus corpus) {
    for (int i = 0; i < corpus.sentenceCount(); i++){
        Sentence* s = corpus.getSentence(i);
        for (int j = 0; j < s->wordCount(); j++){
            PosTaggedWord* word = dynamic_cast<PosTaggedWord*> (corpus.getSentence(i)->getWord(j));
            tagList.emplace_back(word->getTag());
        }
    }
}

Sentence DummyPosTagger::posTag(Sentence sentence) {
    srand(0);
    Sentence result = Sentence();
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), tagList[random() % tagList.size()]));
    }
    return result;
}
