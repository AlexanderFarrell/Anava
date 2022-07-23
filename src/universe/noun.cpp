//
// Created by Alexander Farrell on 6/22/22.
//

#include "noun.h"

Noun::Noun() {
    this->previous = nullptr;
    this->next = nullptr;
}

Noun::~Noun() {
    for (auto i = this->states.begin(); i != this->states.end(); ++i) {
        ((State*)i->second)->End();
        delete (State*)i->second;
    }
    this->states.clear();

    if (this->previous != nullptr) {
        this->previous->next = this->next;
    }

    if (this->next != nullptr) {
        this->next->previous = this->previous;
    }

    this->next = nullptr;
    this->previous = nullptr;
//    this->states.erase();
}

void Noun::State::Begin() {

}

void Noun::State::End() {

}

Noun::State::State() {
    this->noun = nullptr;
}

Noun::State::~State() {

}
