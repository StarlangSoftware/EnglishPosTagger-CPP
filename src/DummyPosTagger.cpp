//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#include <fstream>
#include "DummyPosTagger.h"
#include "PosTaggedWord.h"

/**
 * Train method for the Dummy pos tagger. The algorithm gets all possible tag list.
 *
 * @param corpus Traning data for the tagger.
 */
void DummyPosTagger::train(const PosTaggedCorpus& corpus) {
    unordered_set<string> corpusTagList = corpus.getTagList();
    for (const auto& tag : corpusTagList){
        tagList.emplace_back(tag);
    }
}

/**
 * Test method for the Dummy pos tagger. For each word, the method chooses randomly a tag from all possible
 * tag list.
 *
 * @param sentence Sentence to be tagged.
 * @return Annotated (tagged) sentence.
 */
Sentence DummyPosTagger::posTag(Sentence& sentence) {
    srand(0);
    Sentence result = Sentence();
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), tagList[random() % tagList.size()]));
    }
    return result;
}

DummyPosTagger::DummyPosTagger(ifstream &inputFile) {
    int size;
    string tag;
    inputFile >> size;
    tagList.reserve(size);
    for (int i = 0; i < size; i++){
        inputFile >> tag;
        tagList.emplace_back(tag);
    }
}
