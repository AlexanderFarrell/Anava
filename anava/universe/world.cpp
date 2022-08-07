//
// Created by Alexander Farrell on 6/18/22.
//

#include "world.h"
#include <iostream>

World::World() {
    Noun* secret_noun = new Noun();
    this->headNoun = secret_noun;
    this->active = true;
    this->toEnd = false;
}

World::World(const std::string& filename) {

}

World::~World() {
    this->active = false;

    auto j = this->headNoun;
    while (j != nullptr) {
        auto noun = j;
//        std::cout << noun << "\n";
        j = j->next;

        delete noun;
    }
    this->headNoun = nullptr;
}

void World::Update() {
    int a = 0;
    if (this->active) {
    }

    if (this->toEnd) {
        delete this;
    }
}

void World::Save(const std::string& filename) {

}

Noun *World::create_noun() {
    Noun* noun = new Noun();
    Noun* next = this->headNoun->next;
    this->headNoun->next = noun;

    if (next != nullptr) {
        next->previous = noun;
    }

    noun->previous = this->headNoun;
    noun->next = next;
    return noun;
}