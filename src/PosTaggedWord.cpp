//
// Created by Olcay Taner Yıldız on 21.01.2019.
//

#include "PosTaggedWord.h"

/**
 * A constructor of PosTaggedWord which takes name and tag as input and sets the corresponding attributes
 * @param name Name of the word
 * @param tag Tag of the word
 */
PosTaggedWord::PosTaggedWord(const string& name, const string& tag) : Word(name){
    this->tag = tag;
}

/**
 * Accessor method for tag attribute.
 *
 * @return Tag of the word.
 */
string PosTaggedWord::getTag() const{
    return tag;
}
