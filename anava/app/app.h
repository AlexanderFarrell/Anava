//
// Created by Alexander Farrell on 6/22/22.
//

#ifndef ANAVA_T_THREE_APP_H
#define ANAVA_T_THREE_APP_H


#include "game_state.h"
#include "../io/input/input.h"

// Holds main parts of the application statically.
class App {
public:
    static Engine* engine_app;
    static GameState* game_state_app;

    static Player* get_player();
    static Universe* get_universe();
    static Input* get_input();
    static Audio* get_audio();
    static Visual* get_visual();
    static FS* get_file_system();
    static Network* get_network();
    static UI* get_ui();
    static World* get_world();

    static void switch_game_state(GameState * game_state);
};


#endif //ANAVA_T_THREE_APP_H
