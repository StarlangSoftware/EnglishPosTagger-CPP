//
// Created by olcay on 22/01/2019.
//

#include <iostream>
#include <fstream>
#include "PosTagger.h"
#include "PosTaggedWord.h"
#include "DummyPosTagger.h"
#include "NaivePosTagger.h"
#include "HmmPosTagger.h"

void checkTagger(PosTaggedCorpus& posTaggedCorpus, PosTagger* posTagger){
    int correct, incorrect;
    correct = 0;
    incorrect = 0;
    for (int i = 0; i < posTaggedCorpus.sentenceCount(); i++){
        Sentence* currentSentence = posTaggedCorpus.getSentence(i);
        Sentence taggedSentence = posTagger->posTag(*currentSentence);
        for (int j = 0; j < taggedSentence.wordCount(); j++){
            if (((PosTaggedWord*) posTaggedCorpus.getSentence(i)->getWord(j))->getTag() == ((PosTaggedWord*)taggedSentence.getWord(j))->getTag()){
                correct++;
            } else {
                incorrect++;
            }
        }
    }
    cout << "Accuracy: ";
    cout << 100 * correct / (correct + incorrect + 0.0) << "\n";
}

int main(){
    PosTaggedCorpus posTaggedCorpus = PosTaggedCorpus("brown.txt");
    NaivePosTagger posTagger = NaivePosTagger();
    posTagger.train(posTaggedCorpus);
    checkTagger(posTaggedCorpus, &posTagger);
    posTagger.saveModel();
    ifstream inputFile;
    inputFile.open("naivePosTagger.bin");
    NaivePosTagger posTagger2 = NaivePosTagger(inputFile);
    inputFile.close();
    checkTagger(posTaggedCorpus, &posTagger2);
}