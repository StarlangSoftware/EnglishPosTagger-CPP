//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "PosTaggedCorpus.h"
#include "PosTaggedWord.h"
#include "Word.h"

PosTaggedCorpus::PosTaggedCorpus() {
}

PosTaggedCorpus PosTaggedCorpus::emptyCopy() {
    return PosTaggedCorpus();
}

PosTaggedCorpus::PosTaggedCorpus(string fileName) {
    string line, name, tag, shortTag;
    Sentence* newSentence = new Sentence();
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->fileName = move(fileName);
    while (inputStream.good()){
        getline(inputStream, line);
        vector<string> tokens = Word::split(line, " \t");
        for (const string& word : tokens){
            if (!word.empty()){
                if (word.find_first_of('/') != -1){
                    name = word.substr(0, word.find_last_of('/'));
                    tag = word.substr(word.find_last_of('/') + 1);
                    if (tag.find_first_of("+-") != -1){
                        shortTag = tag.substr(0, tag.find_first_of("+-"));
                    } else {
                        shortTag = tag;
                    }
                    tagList.put(shortTag);
                    PosTaggedWord* newWord = new PosTaggedWord(name, shortTag);
                    newSentence->addWord(newWord);
                    if (tag == "."){
                        addSentence(newSentence);
                        newSentence = new Sentence();
                    }
                } else {
                    cout << "Word " + word + " does not contain /\n";
                }
            }
        }
    }
    if (newSentence->wordCount() > 0){
        addSentence(newSentence);
    }
}

unordered_set<string> PosTaggedCorpus::getTagList() {
    unordered_set<string> result;
    for (auto &item : tagList) {
        result.emplace(item.first);
    }
    return result;
}
