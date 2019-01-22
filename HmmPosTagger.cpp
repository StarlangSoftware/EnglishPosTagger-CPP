//
// Created by olcay on 22/01/2019.
//

#include "HmmPosTagger.h"
#include "PosTaggedWord.h"
#include "Hmm1.h"

void HmmPosTagger::train(PosTaggedCorpus corpus) {
    vector<string>* emittedSymbols = new vector<string>[corpus.sentenceCount()];
    for (int i = 0; i < corpus.sentenceCount(); i++){
        for (int j = 0; j < corpus.getSentence(i)->wordCount(); j++){
            PosTaggedWord* word = dynamic_cast<PosTaggedWord*> (corpus.getSentence(i)->getWord(j));
            emittedSymbols[i].push_back(word->getTag());
        }
    }
    hmm = Hmm1<string, Word>(corpus.getTagList(), corpus.sentenceCount(), emittedSymbols, corpus.getAllWordsAsArray());
}

Sentence HmmPosTagger::posTag(Sentence sentence) {
    Sentence result;
    vector<string> tagList = hmm.viterbi(sentence.getWordList());
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), tagList.at(i)));
    }
    return result;
}
