//
// Created by Alexander Farrell on 6/22/22.
//

#ifndef ANAVA_T_THREE_APP_H
#define ANAVA_T_THREE_APP_H


#include "game_state.h"

// Holds main parts of the application statically.
class App {
public:
    static Engine* engine_app;
    static GameState* game_state_app;

    static Player* get_player();
    static Universe* get_universe();
    static Input* get_input();
    static Output* get_output();
    static World* get_world();

    static void switch_game_state(GameState * game_state);
};


#endif //ANAVA_T_THREE_APP_H
