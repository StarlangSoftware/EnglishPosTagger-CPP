//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#include <fstream>
#include "DummyPosTagger.h"
#include "PosTaggedWord.h"

void DummyPosTagger::train(PosTaggedCorpus& corpus) {
    unordered_set<string> corpusTagList = corpus.getTagList();
    for (const auto& tag : corpusTagList){
        tagList.emplace_back(tag);
    }
}

Sentence DummyPosTagger::posTag(Sentence& sentence) {
    srand(0);
    Sentence result = Sentence();
    for (int i = 0; i < sentence.wordCount(); i++){
        result.addWord(new PosTaggedWord(sentence.getWord(i)->getName(), tagList[random() % tagList.size()]));
    }
    return result;
}

void DummyPosTagger::serialize(ostream &outputFile) {
    outputFile << tagList.size() << "\n";
    for (const string &tag : tagList){
        outputFile << tag << "\n";
    }
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

void DummyPosTagger::saveModel() {
    ofstream outputFile;
    outputFile.open("dummyPosTagger.bin", ofstream::out);
    serialize(outputFile);
    outputFile.close();
}
