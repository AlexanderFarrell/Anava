//
// Created by Alexander Farrell on 6/18/22.
//

#include "mouse.h"

int Mouse::subscribe(int mouse_button, func_call on) {
    int new_id;
    switch (mouse_button) {
        case 0:
            new_id = this->sequence_one++;
            this->mouse_button_one_listeners[new_id] = on;
            break;
        case 1:
            new_id = this->sequence_two++;
            this->mouse_button_two_listeners[new_id] = on;
            break;
        default:
            throw std::invalid_argument("Invalid mouse button");
    }
    return new_id;
}

void Mouse::unsubscribe(int mouse_button, int id) {
    switch (mouse_button) {
        case 0:
            this->mouse_button_one_listeners.erase(id);
            break;
        case 1:
            this->mouse_button_two_listeners.erase(id);
            break;
        default:
            throw std::invalid_argument("Invalid mouse button");
    }
}

Mouse::Mouse() {
    this->sequence_one = 0;
    this->sequence_two = 0;
}

void Mouse::update() {

}

bool Mouse::IsButtonUp(int button) {
    return (!this->button_state[button] && this->last_update_by_mouse[button] == this->step - 1);
}

bool Mouse::IsButtonDown(int button) {
    return (this->button_state[button] && this->last_update_by_mouse[button] == this->step - 1);
}
