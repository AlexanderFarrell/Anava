//
// Created by Alexander Farrell on 7/8/22.
//

#ifndef ANAVA_T_THREE_SOUND_H
#define ANAVA_T_THREE_SOUND_H

#include <string>
#include <SDL2_mixer/SDL_mixer.h>

class Sound {
private:
    std::string name;
    Mix_Chunk* sound;
public:
    explicit Sound(std::string filename);
    ~Sound();
    void play(int channel);
    void stop();
    void resume();
    void pause();

};


#endif //ANAVA_T_THREE_SOUND_H
