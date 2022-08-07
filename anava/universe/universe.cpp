//
// Created by Alexander Farrell on 6/18/22.
//

#include "universe.h"
#include "../util/data/random/random.h"

void a(Noun::State* state, Noun* valence) {
    //std::cout << valence << std::endl;
}

Universe::Universe() {
    seed(time(nullptr));
    this->focused = nullptr;
    auto* secret_progression = new Progression(nullptr, a);
    this->headProgression = secret_progression;
}

Universe::~Universe() {
    for (auto a: this->worlds) {
        delete a;
    }

    auto i = this->headProgression->next;
    while (i != nullptr) {
        auto progression = i;
        i = i->next;

        delete progression;
    }
    delete this->headProgression;
    this->headProgression = nullptr;

    this->headProgression = nullptr;
    this->focused = nullptr;
}

void Universe::update() {
    this->focused->Update();

    auto i = this->headProgression;
    while (i != nullptr) {
        auto curr = i;
        i = i->next;
        curr->on_call(curr->subject, curr->valence);
    }
}

void Universe::add_world(World *world) {
    this->worlds.insert(world);
}

void Universe::remove_world(World* world) {
    if (this->focused == world) {
        this->focused = nullptr;
    }
    this->worlds.erase(this->worlds.find(world));
}

Progression *Universe::create_progression(Noun::State *subject, void (*on_call)(Noun::State *, Noun *)) {
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

Progression *Universe::create_progression(Noun::State *subject, void (*on_call)(Noun::State *, Noun *), Noun *valence) {
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

Progression *Universe::create_progression(void (*on_call)(Noun::State *, Noun *)) {
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