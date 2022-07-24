//
// Created by Alexander Farrell on 6/22/22.
//

#include "anava.h"
#include "app/app.h"

void run_game(Game * game)  {
    App::engine_app = new Engine(game->name);
    App::switch_game_state(game->start_state);

    long last_update = current_timestamp();
    App::engine_app->player->is_running = true;
    while (App::engine_app->player->is_running) {
        App::engine_app->update(&last_update);
    }

    delete App::game_state_app;
    delete App::engine_app;
}