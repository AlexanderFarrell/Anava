//
// Created by Alexander Farrell on 7/8/22.
//

#ifndef ANAVA_T_THREE_SONG_H
#define ANAVA_T_THREE_SONG_H

#include <SDL2_mixer/SDL_mixer.h>
#include <string>

class Song {
private:
    std::string name;
    Mix_Music *track;
public:
    explicit Song(std::string filename);
    ~Song();

    [[nodiscard]] const std::string &getName() const;

    void play(int loop);
    void resume();
    void stop();
    void pause();
};


#endif //ANAVA_T_THREE_SONG_H
