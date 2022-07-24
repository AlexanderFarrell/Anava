//
// Created by Alexander Farrell on 6/18/22.
//

#include "engine.h"

Engine::Engine(const std::string& app_name) {
    this->player = new Player(app_name);
    this->universe = new Universe();
    this->io = new IO(this->player->window);
}

Engine::~Engine() {
    delete this->io;
    delete this->universe;
    delete this->player;
}

void Engine::update(long * last) {
    this->player->update(this->io->input);
    this->io->update(this->player->window);
    this->universe->update();

    //Delay Time
    long current = current_timestamp();
    long since = 17 - (current - *last);

    if (since > 0) {
        SDL_Delay(since);
    }

    *last = current_timestamp();
}