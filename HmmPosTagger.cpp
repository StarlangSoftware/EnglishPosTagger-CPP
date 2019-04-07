//
// Created by olcay on 22/01/2019.
//

#include "HmmPosTagger.h"
#include "PosTaggedWord.h"
#include "Hmm1.h"

void HmmPosTagger::train(PosTaggedCorpus& corpus) {
    int sentenceCount = corpus.sentenceCount();
    auto* emittedSymbols = new vector<string>[sentenceCount];
    auto* allWords = new vector<string>[sentenceCount];
    for (int i = 0; i < sentenceCount; i++){
        for (int j = 0; j < corpus.getSentence(i)->wordCount(); j++){
            auto * word = (PosTaggedWord*) (corpus.getSentence(i)->getWord(j));
            allWords[i].emplace_back(word->getName());
            emittedSymbols[i].emplace_back(word->getTag());
        }
    }
    hmm = Hmm1<string, string>(corpus.getTagList(), sentenceCount, emittedSymbols, allWords);
}

Sentence HmmPosTagger::posTag(Sentence& sentence) {
    Sentence result;
    vector<Word> wordList = sentence.getWordList();
    vector<string> stringList;
    stringList.reserve(wordList.size());
    for (const Word &word : wordList){
        stringList.emplace_back(word.getName());
    }
    vector<string> tagList = hmm.viterbi(stringList);
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), tagList.at(i)));
    }
    return result;
}

void HmmPosTagger::serialize(ostream &outputFile) {
    hmm.serialize(outputFile);
}

HmmPosTagger::HmmPosTagger(ifstream &inputFile) {
    hmm = Hmm1<string, string>(inputFile);
}

void HmmPosTagger::saveModel() {
    ofstream outputFile;
    outputFile.open("hmmPosTagger.bin", ofstream::out);
    serialize(outputFile);
    outputFile.close();
}
