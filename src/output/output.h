//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_OUTPUT_H
#define ANAVA_T_THREE_OUTPUT_H

#include "audio/audio.h"
#include "visual/visual.h"
#include "../player/player.h"

class Output {

public:
    Visual* visual;
    Audio* audio;
    explicit Output(Player *player);
    ~Output();

    void update(Player* player);
};


#endif //ANAVA_T_THREE_OUTPUT_H
