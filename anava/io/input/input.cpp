//
// Created by Alexander Farrell on 6/18/22.
//

#include "input.h"
#include <iostream>

Input::Input() {
    this->mouse.x = 0;
    this->mouse.y = 0;
    this->step = 1;
    this->mouse.step = 1;
    this->keyboard.step = 1;
    memset(this->mouse.last_update_by_mouse, 0, sizeof(int) * MAX_MOUSE_BUTTONS);
    memset(this->keyboard.last_update_by_key, 0, sizeof(int) * MAX_KEYBOARD_KEYS);
    memset(this->mouse.button_state, 0, sizeof(int) * MAX_MOUSE_BUTTONS);
    memset(this->keyboard.key_state, 0, sizeof(int) * MAX_KEYBOARD_KEYS);
}

Input::~Input() {

}

void Input::update() {
    this->step++;
    this->mouse.step = this->step;
    this->keyboard.step = this->step;
}

void Input::on_key_down(SDL_KeyboardEvent *event) {
//    printf("Key down: %s\n", SDL_GetScancodeName(event->keysym.scancode));
    this->keyboard.key_state[event->keysym.scancode] = 1;
    this->keyboard.last_update_by_key[event->keysym.scancode] = this->step;
}

void Input::on_key_up(SDL_KeyboardEvent *event) {
//    printf("Key up: %s\n", SDL_GetScancodeName(event->keysym.scancode));
    this->keyboard.key_state[event->keysym.scancode] = 0;
    this->keyboard.last_update_by_key[event->keysym.scancode] = this->step;
}

void Input::on_mouse_move(SDL_MouseMotionEvent *event) {
    this->mouse.x = event->x;
    this->mouse.y = event->y;
}

void Input::on_mouse_down(SDL_MouseButtonEvent *event) {
    this->mouse.button_state[event->which] = 1;
    this->mouse.last_update_by_mouse[event->which] = this->step;
//    std::cout << "Mouse Down ID: " << event->which << "\n";
}

void Input::on_mouse_up(SDL_MouseButtonEvent *event) {
    this->mouse.button_state[event->which] = 0;
    this->mouse.last_update_by_mouse[event->which] = this->step;
//    std::cout << "Mouse Up ID: " << event->which << "\n";
}

void Input::on_mouse_wheel(SDL_MouseWheelEvent *event) {
    // Not implemented;
}
