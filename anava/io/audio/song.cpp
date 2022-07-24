//
// Created by Alexander Farrell on 7/8/22.
//

#include "song.h"

#include <utility>

Song::Song(std::string filename) {
    this->name = std::move(filename);
    std::string path_folder("../../content/audio/music/");
    std::string path = path_folder + this->name;
    const char* c_str = path.c_str();
    this->track = Mix_LoadMUS(c_str);
}

Song::~Song() {
    Mix_FreeMusic(this->track);
}

void Song::play(int loop) {
    Mix_PlayMusic(this->track, (loop) ? -1 : 0);
}

void Song::stop() {
    Mix_HaltMusic();
}

void Song::pause() {
    Mix_PauseMusic();
}

const std::string &Song::getName() const {
    return name;
}
