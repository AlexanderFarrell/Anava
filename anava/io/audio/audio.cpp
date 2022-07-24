//
// Created by Alexander Farrell on 6/18/22.
//

#include "audio.h"

#define AUDIO_QUALITY_DEFAULT 44100
#define MIX_FORMAT_DEFAULT AUDIO_S16LSB
#define AUDIO_CHANNELS_DEFAULT 2
#define MAX_SOUND_CHANNELS_DEFAULT 8
#define AUDIO_CHUNK_SIZE_DEFAULT 1024

void Audio::update() {

}

void Audio::play_song(Song *s, bool loop) {
    this->stop_song();

    this->song = s;
    this->song->play((loop) ? 1 : 0);
}

void Audio::play_sound(Sound *sound) {
    
}

Audio::Audio() {
    if (Mix_OpenAudio(AUDIO_QUALITY_DEFAULT,
                      MIX_FORMAT_DEFAULT,
                      AUDIO_CHANNELS_DEFAULT,
                      AUDIO_CHUNK_SIZE_DEFAULT) == -1) {
        printf("Could not initialize audio, SDL Mixer initialization error\n");
        exit(1);
    }

    Mix_AllocateChannels(MAX_SOUND_CHANNELS_DEFAULT);
    this->song = nullptr;
}

Audio::~Audio() {
    Mix_Quit();
}

void Audio::stop_song() {
    if (this->song != nullptr) {
        this->song->stop();
    }
    this->song = nullptr;
}
