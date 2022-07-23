//
// Created by Alexander Farrell on 6/18/22.
//

#include "game_state.h"
#include "../util/creation/UICreation.h"

std::string GameState::get_name() {
    return "unnamed state";
}

void GameState::on_start(Engine *engine) {
    this->world = new World();
    engine->universe->focused = this->world;
    engine->universe->add_world(this->world);

    engine->output->visual->camera_ui = UICreation::CreateCameraOrtho();
    engine->output->visual->camera_game_world = UICreation::CreateCameraPerspective();
}

void GameState::on_end(Engine *engine) {
    engine->universe->remove_world(this->world);
    this->world->toEnd = true;
}

GameState::GameState() {
    this->world = nullptr;
}

GameState::~GameState() {

}
