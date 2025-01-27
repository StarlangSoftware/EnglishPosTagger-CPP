//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "PosTaggedCorpus.h"
#include "PosTaggedWord.h"
#include "StringUtils.h"

/**
 * A constructor of PosTaggedCorpus which initializes the sentences of the corpus, the word list of
 * the corpus, and all possible tags.
 */
PosTaggedCorpus::PosTaggedCorpus() {
}

/**
 * A clone method for the PosTaggedCorpus class.
 *
 * @return A copy of the current PosTaggedCorpus class.
 */
PosTaggedCorpus PosTaggedCorpus::emptyCopy() {
    return PosTaggedCorpus();
}

/**
 * Another constructor of PosTaggedCorpus which takes a fileName of the corpus as an input, reads the
 * corpus from that file.
 *
 * @param fileName Name of the corpus file.
 */
PosTaggedCorpus::PosTaggedCorpus(const string& fileName) {
    string line, name, tag, shortTag;
    auto* newSentence = new Sentence();
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->fileName = fileName;
    while (inputStream.good()){
        getline(inputStream, line);
        vector<string> tokens = StringUtils::split(line, " \t");
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
                    auto* newWord = new PosTaggedWord(name, shortTag);
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

/**
 * getTagList returns all possible tags as a set.
 *
 * @return Set of all possible tags.
 */
unordered_set<string> PosTaggedCorpus::getTagList() const{
    unordered_set<string> result;
    for (auto &item : tagList) {
        result.emplace(item.first);
    }
    return result;
}
