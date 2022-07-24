//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_GAME_H
#define ANAVA_T_THREE_GAME_H

#include <string>
#include "game_state.h"

// Represents a game which can be played.
class Game {
public:
    std::string name;
    GameState* start_state;

public:
    Game(std::string name, GameState *start_state);

private:
    ~Game();
};


#endif //ANAVA_T_THREE_GAME_H
