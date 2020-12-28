//
// Created by Olcay Taner YILDIZ on 28.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../PosTagger.h"
#include "../DummyPosTagger.h"
#include "../PosTaggedWord.h"

TEST_CASE("DummyPosTaggerTest-testPosTag") {
    DummyPosTagger posTagger = DummyPosTagger();
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
    REQUIRE_THAT(0.96, Catch::Matchers::WithinAbs(100 * correct / (correct + incorrect + 0.0), 0.01));
}