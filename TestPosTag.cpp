//
// Created by olcay on 22/01/2019.
//

#include <iostream>
#include "PosTagger.h"
#include "PosTaggedWord.h"
#include "DummyPosTagger.h"
#include "NaivePosTagger.h"
#include "HmmPosTagger.h"

int main(){
    NaivePosTagger posTagger = NaivePosTagger();
    PosTaggedCorpus posTaggedCorpus = PosTaggedCorpus("brown.txt");
    posTagger.train(posTaggedCorpus);
    int correct = 0, incorrect = 0;
    for (int i = 0; i < posTaggedCorpus.sentenceCount(); i++){
        Sentence* currentSentence = posTaggedCorpus.getSentence(i);
        Sentence taggedSentence = posTagger.posTag(*currentSentence);
        for (int j = 0; j < taggedSentence.wordCount(); j++){
            if (((PosTaggedWord*) posTaggedCorpus.getSentence(i)->getWord(j))->getTag() == ((PosTaggedWord*)taggedSentence.getWord(j))->getTag()){
                correct++;
            } else {
                incorrect++;
            }
        }
        if (i % 100 == 0){
            cout << "Tested " << i << " sentences\n";
        }
    }
    cout << "Accuracy: ";
    cout << 100 * correct / (correct + incorrect + 0.0);
}