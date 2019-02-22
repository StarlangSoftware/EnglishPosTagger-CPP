//
// Created by olcay on 22/01/2019.
//

#include "HmmPosTagger.h"
#include "PosTaggedWord.h"
#include "Hmm1.h"

void HmmPosTagger::train(PosTaggedCorpus& corpus) {
    int sentenceCount = corpus.sentenceCount();
    auto * emittedSymbols = new vector<string>[sentenceCount];
    for (int i = 0; i < sentenceCount; i++){
        for (int j = 0; j < corpus.getSentence(i)->wordCount(); j++){
            auto * word = (PosTaggedWord*) (corpus.getSentence(i)->getWord(j));
            emittedSymbols[i].push_back(word->getTag());
        }
    }
    vector<Word>* allWords = corpus.getAllWordsAsArray();
    hmm = Hmm1<string, Word>(corpus.getTagList(), sentenceCount, emittedSymbols, allWords);
}

Sentence HmmPosTagger::posTag(Sentence& sentence) {
    Sentence result;
    vector<string> tagList = hmm.viterbi(sentence.getWordList());
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), tagList.at(i)));
    }
    return result;
}
