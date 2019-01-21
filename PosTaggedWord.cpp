//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#include "PosTaggedWord.h"

PosTaggedWord::PosTaggedWord(string name, string tag) : Word(name){
    this->tag = tag;
}

string PosTaggedWord::getTag() {
    return tag;
}
