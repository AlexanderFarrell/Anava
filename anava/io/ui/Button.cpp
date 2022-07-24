//
// Created by Alexander Farrell on 7/11/22.
//

#include "Button.h"

void check_click(Noun::State* state, Noun* noun) {
    Button* b = ((Button*)state);
    Location* l = b->location;

    if (App::engine_app->io->input->mouse.IsButtonUp(0)) {
        int mouse_x = App::engine_app->io->input->mouse.x;
        int mouse_y = App::engine_app->io->input->mouse.y;
        int x =     (float)l->position[0];
        int y =     (float)l->position[1];
        int x_max = (float)l->position[0] + b->xSize;
        int y_max = (float)l->position[1] + b->ySize;

        if (x <= mouse_x && y <= mouse_y && x_max > mouse_x && y_max > mouse_y) {
            b->on();
        }
    }
}

Button::Button() {
    this->on = nullptr;
    this->xSize = 0;
    this->ySize = 0;
    this->p = nullptr;
    this->location = nullptr;
}

Button::~Button() {
    this->on = nullptr;
}

Button::Button(func_call on) {
    this->on = on;
    this->xSize = 0;
    this->ySize = 0;
    this->p = nullptr;
    this->location = nullptr;
}

void Button::Begin() {
    State::Begin();
    this->location = noun->get_state<Location>();
    this->p = App::engine_app->universe->focused->create_progression(this, check_click);
}

void Button::End() {
    State::End();
    this->location = nullptr;
//    delete this->p;
//    App::engine_app->universe->focused.
}
