//
// Created by olcay on 22/01/2019.
//

#include "HmmPosTagger.h"
#include "PosTaggedWord.h"
#include "Hmm1.h"

/**
 * Train method for the Hmm pos tagger. The algorithm trains an Hmm from the corpus, where corpus constitutes
 * as an observation array.
 *
 * @param corpus Traning data for the tagger.
 */
void HmmPosTagger::train(const PosTaggedCorpus& corpus) {
    int sentenceCount = corpus.sentenceCount();
    auto* emittedSymbols = new vector<string>[sentenceCount];
    auto* allWords = new vector<Word>[sentenceCount];
    for (int i = 0; i < sentenceCount; i++){
        for (int j = 0; j < corpus.getSentence(i)->wordCount(); j++){
            auto * word = (PosTaggedWord*) (corpus.getSentence(i)->getWord(j));
            allWords[i].emplace_back(Word(word->getName()));
            emittedSymbols[i].emplace_back(word->getTag());
        }
    }
    hmm = Hmm1<string, Word>(corpus.getTagList(), sentenceCount, emittedSymbols, allWords);
}

/**
 * Test method for the Hmm pos tagger. For each sentence, the method uses the viterbi algorithm to produce the
 * most possible state sequence for the given sentence.
 *
 * @param sentence Sentence to be tagged.
 * @return Annotated (tagged) sentence.
 */
Sentence HmmPosTagger::posTag(Sentence& sentence) {
    Sentence result;
    vector<string> tagList = hmm.viterbi(sentence.getWordList());
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), tagList.at(i)));
    }
    return result;
}
