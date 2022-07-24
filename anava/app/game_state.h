//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_GAME_STATE_H
#define ANAVA_T_THREE_GAME_STATE_H

#include <string>
#include "../engine.h"

class GameState {
public:
    virtual std::string get_name();
    virtual void on_start(Engine * engine);
    virtual void on_end(Engine * engine);

    GameState();
    ~GameState();

protected:
    World* world;
};

#endif //ANAVA_T_THREE_GAME_STATE_H
