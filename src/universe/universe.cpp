//
// Created by Alexander Farrell on 6/18/22.
//

#include "universe.h"
#include "../util/data/random/random.h"

Universe::Universe() {
    seed(time(nullptr));
    this->focused = nullptr;
}

Universe::~Universe() {
    for (auto a: this->worlds) {
        delete a;
    }
    this->focused = nullptr;
}

void Universe::update() {
    this->focused->Update();
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
