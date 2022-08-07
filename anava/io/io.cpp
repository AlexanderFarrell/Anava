//
// Created by Alexander Farrell on 7/23/22.
//

#include "io.h"

IO::IO(Window* window) {
    std::cout << "Outputting\n";
    this->fs = new FS();
    this->input = new Input();
    this->visual = new Visual(window);
    this->audio = new Audio();
    this->network = new Network();
    this->ui = new UI();
}
IO::~IO() {
    delete this->ui;
    delete this->visual;
    delete this->audio;
    delete this->network;
    delete this->input;
    delete this->fs;
}

void IO::update(Window* window) {
    this->input->update();
    this->visual->update(window);
    this->audio->update();
    this->ui->update();
}
