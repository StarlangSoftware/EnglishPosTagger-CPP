//
// Created by Olcay Taner YILDIZ on 28.12.2020.
//

#include "catch.hpp"
#include "../src/NaivePosTagger.h"
#include "../src/PosTaggedWord.h"

TEST_CASE("NaivePosTaggerTest-testPosTag") {
    NaivePosTagger posTagger = NaivePosTagger();
    PosTaggedCorpus posTaggedCorpus = PosTaggedCorpus("brown.txt");
    posTagger.train(posTaggedCorpus);
    int correct = 0, incorrect = 0;
    for (int i = 0; i < posTaggedCorpus.sentenceCount(); i++){
        Sentence taggedSentence = posTagger.posTag(*(posTaggedCorpus.getSentence(i)));
        for (int j = 0; j < taggedSentence.wordCount(); j++){
            if (((PosTaggedWord*) posTaggedCorpus.getSentence(i)->getWord(j))->getTag() == (((PosTaggedWord*)taggedSentence.getWord(j))->getTag())){
                correct++;
            } else {
                incorrect++;
            }
        }
    }
    REQUIRE_THAT(93.69, Catch::Matchers::WithinAbs(100 * correct / (correct + incorrect + 0.0), 0.01));
}