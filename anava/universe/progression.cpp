//
// Created by Alexander Farrell on 7/18/22.
//

#include "progression.h"

Progression::~Progression() {
//    std::cout << "Deleting Progression: \n";
//    std::cout << "\tNext: " << this->next << "\n";
//    std::cout << "\tPrev: " << this->previous << "\n";
//    std::cout << "\tThis: " << this << "\n";

    if (this->previous != nullptr) {
        this->previous->next = this->next;
    }

    if (this->next != nullptr) {
        this->next->previous = this->previous;
    }

    this->next = nullptr;
    this->previous = nullptr;
}

Progression::Progression(Noun::State *subject, void (*on_call)(Noun::State *, Noun *)) {
    this->previous = nullptr;
    this->next = nullptr;
    this->valence = nullptr;
    this->on_call = on_call;
    this->subject = subject;
}

Progression::Progression(Noun::State *subject, void (*on_call)(Noun::State *, Noun *), Noun *valence) {
    this->previous = nullptr;
    this->next = nullptr;
    this->valence = valence;
    this->on_call = on_call;
    this->subject = subject;
}

Progression::Progression(void (*on_call)(Noun::State *, Noun *)) {
    this->previous = nullptr;
    this->next = nullptr;
    this->valence = nullptr;
    this->on_call = on_call;
    this->subject = nullptr;
}