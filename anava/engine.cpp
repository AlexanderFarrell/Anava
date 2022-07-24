//
// Created by Alexander Farrell on 6/18/22.
//

#include "engine.h"

Engine::Engine(const std::string& app_name) {
    this->player = new Player(app_name);
    this->universe = new Universe();
//    this->input = new Input();
//    this->output = new Output(this->player);
    this->io = new IO(this->player->window);
}

Engine::~Engine() {
//    delete this->output;
//    delete this->input;
    delete this->io;
    delete this->universe;
    delete this->player;
}

void Engine::update(long * last) {
    this->player->update(this->io->input);
//    this->input->update();
    this->universe->update();
//    this->output->update(this->player);

    //Delay Time
    long current = current_timestamp();
    long since = 17 - (current - *last);

    if (since > 0) {
        SDL_Delay(since);
    }

    *last = current_timestamp();
}