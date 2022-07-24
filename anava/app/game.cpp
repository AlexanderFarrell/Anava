//
// Created by Alexander Farrell on 6/18/22.
//

#include "game.h"

#include <utility>

Game::Game(std::string name, GameState *start_state) : name(std::move(name)), start_state(start_state) {}
Game::~Game() {
    delete this->start_state;
}

