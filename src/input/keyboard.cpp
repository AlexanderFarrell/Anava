//
// Created by Alexander Farrell on 6/18/22.
//

#include "keyboard.h"

void Keyboard::update() {

}

bool Keyboard::IsKeyDown(int scancode) {
    return (!this->key_state[scancode] && this->step - 1 == this->last_update_by_key[scancode]);
}

bool Keyboard::IsKeyUp(int scancode) {
    return (this->key_state[scancode] && this->step - 1 == this->last_update_by_key[scancode]);
}
