//
// Created by Alexander Farrell on 7/8/22.
//

#include "sound.h"

Sound::Sound(std::string filename) {
    this->name = std::move(filename);
    std::string path_folder("../../content/audio/music/");
    std::string path = path_folder + this->name;
    const char* c_str = path.c_str();
    this->sound = Mix_LoadWAV(c_str);
}

Sound::~Sound() {
    Mix_FreeChunk(this->sound);
}

void Sound::play(int channel) {
    Mix_PlayChannel(channel, this->sound, 0);
}

void Sound::stop() {
    throw std::runtime_error("Not implemented");
}

void Sound::resume() {
    throw std::runtime_error("Not implemented");
}

void Sound::pause() {
    throw std::runtime_error("Not implemented");
}