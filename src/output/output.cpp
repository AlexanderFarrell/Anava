//
// Created by Alexander Farrell on 6/18/22.
//

#include "output.h"

Output::Output(Player *player) {
    this->visual = new Visual(player->window);
    this->audio = new Audio();
}

Output::~Output() {
    delete this->visual;
    delete this->audio;
}

void Output::update(Player *player) {
    this->visual->update(player->window);
    this->audio->update(player);
}
