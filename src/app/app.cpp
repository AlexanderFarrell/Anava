//
// Created by Alexander Farrell on 6/22/22.
//

#include "app.h"

Engine* App::engine_app = nullptr;
GameState* App::game_state_app = nullptr;

void App::switch_game_state(GameState *gs) {
    if (App::game_state_app != nullptr) {
        App::game_state_app->on_end(App::engine_app);
        delete App::game_state_app;
    }

    App::game_state_app = gs;

    if (App::game_state_app != nullptr) {
        App::game_state_app->on_start(App::engine_app);
    }
}

Player *App::get_player() {
    return App::engine_app->player;
}

Universe *App::get_universe() {
    return App::engine_app->universe;
}

Input *App::get_input() {
    return App::engine_app->input;
}

Output *App::get_output() {
    return App::engine_app->output;
}

World *App::get_world() {
    return App::engine_app->universe->focused;
}