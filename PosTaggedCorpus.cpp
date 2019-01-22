//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "PosTaggedCorpus.h"
#include "PosTaggedWord.h"

PosTaggedCorpus::PosTaggedCorpus() {
}

PosTaggedCorpus PosTaggedCorpus::emptyCopy() {
    return PosTaggedCorpus();
}

PosTaggedCorpus::PosTaggedCorpus(string fileName) {
    string line, name, tag;
    Sentence* newSentence = new Sentence();
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->fileName = move(fileName);
    while (inputStream.good()){
        getline(inputStream, line);
        size_t current, previous = 0;
        vector<string> tokens;
        current = line.find_first_of(" \t");
        while (current != string::npos) {
            tokens.push_back(line.substr(previous, current - previous));
            previous = current + 1;
            current = line.find_first_of(" \t", previous);
        }
        tokens.push_back(line.substr(previous, current - previous));
        for (const string& word : tokens){
            if (!word.empty()){
                if (word.find_first_of('/') != -1){
                    name = word.substr(0, word.find_last_of('/'));
                    tag = word.substr(word.find_last_of('/') + 1);
                    tagList.put(tag);
                    newSentence->addWord(new PosTaggedWord(name, tag));
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
    for (auto item = tagList.begin(); item != tagList.end(); item++) {
        result.emplace(item->first);
    }
    return result;
}
