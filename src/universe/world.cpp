//
// Created by Alexander Farrell on 6/18/22.
//

#include "world.h"
#include <iostream>

void a(Noun::State* state, Noun* valence) {
    //std::cout << valence << std::endl;
}

World::World() {
    Noun* secret_noun = new Noun();
    auto* secret_progression = new Progression(nullptr, a);
    this->headNoun = secret_noun;
    this->active = true;
    this->toEnd = false;
    this->headProgression = secret_progression;
}

World::World(const std::string& filename) {

}

World::~World() {
    this->active = false;

    auto i = this->headProgression->next;
    while (i != nullptr) {
        auto progression = i;
        i = i->next;

        delete progression;
    }
    delete this->headProgression;
    this->headProgression = nullptr;

    auto j = this->headNoun;
    while (j != nullptr) {
        auto noun = j;
//        std::cout << noun << "\n";
        j = j->next;

        delete noun;
    }

    this->headProgression = nullptr;
    this->headNoun = nullptr;
}

void World::Update() {
    int a = 0;
    if (this->active) {
        auto i = this->headProgression;
        while (i != nullptr) {
            a++;
            auto curr = i;
            i = i->next;
            curr->on_call(curr->subject, curr->valence);
        }
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

Progression *World::create_progression(Noun::State *subject, void (*on_call)(Noun::State *, Noun *)) {
    auto* p = new Progression(subject, on_call);
    if (this->headProgression == nullptr) {
        this->headProgression = p;
    } else {
        Progression* next = this->headProgression->next;
        this->headProgression->next = p;

        if (next != nullptr) {
            next->previous = p;
        }

        p->previous = this->headProgression;
        p->next = next;
    }
    int i = 0;
    for (auto a = this->headProgression; a != nullptr; a = a->next) {
        i++;
    }
    std::cout << "I: " << i << "\n";
    return p;
}

Progression *World::create_progression(Noun::State *subject, void (*on_call)(Noun::State *, Noun *), Noun *valence) {
    auto* p = new Progression(subject, on_call, valence);
    if (this->headProgression == nullptr) {
        this->headProgression = p;
    } else {
        Progression* next = this->headProgression->next;
        this->headProgression->next = p;

        if (next != nullptr) {
            next->previous = p;
            p->next = next;
        } else {
            p->next = nullptr;
        }

        p->previous = this->headProgression;
    }
    int i = 0;
    for (auto a = this->headProgression; a != nullptr; a = a->next) {
        i++;
    }
    std::cout << "I: " << i << "\n";
    return p;
}

Progression *World::create_progression(void (*on_call)(Noun::State *, Noun *)) {
    auto* p = new Progression(on_call);
    if (this->headProgression == nullptr) {
        this->headProgression = p;
    } else {
        Progression* next = this->headProgression->next;
        this->headProgression->next = p;

        if (next != nullptr) {
            next->previous = p;
        }

        p->previous = this->headProgression;
        p->next = next;
    }
    int i = 0;
    for (auto a = this->headProgression; a != nullptr; a = a->next) {
        i++;
    }
    std::cout << "I: " << i << "\n";
    return p;
}