//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_AUDIO_H
#define ANAVA_T_THREE_AUDIO_H

#include <SDL2_mixer/SDL_mixer.h>
#include "../../player/player.h"
#include "song.h"
#include "sound.h"

class Audio {
private:
    Song * song;
public:
    Audio();
    ~Audio();
    void update(Player* player);
    void play_song(Song * s, bool loop);
    void play_sound(Sound * s);
    void stop_song();
};


#endif //ANAVA_T_THREE_AUDIO_H
