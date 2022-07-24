//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_PLAYER_H
#define ANAVA_T_THREE_PLAYER_H


#include "window.h"
#include "../io/input/input.h"

class Player {
public:
    bool is_running;
    Window* window;

    explicit Player(const std::string& name);
    ~Player();

    void update(Input * input);
};


#endif //ANAVA_T_THREE_PLAYER_H
