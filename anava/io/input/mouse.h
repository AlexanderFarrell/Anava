//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_MOUSE_H
#define ANAVA_T_THREE_MOUSE_H

#define MAX_MOUSE_BUTTONS 5
#include <unordered_map>
#include "../../util/defs.h"

class Mouse {
public:
    int x;
    int y;
    int button_state[MAX_MOUSE_BUTTONS];
    int subscribe(int mouse_button, func_call on);
    void unsubscribe(int mouse_button, int id);

    int step;
    int last_update_by_mouse[MAX_MOUSE_BUTTONS];
private:
    std::unordered_map<int, func_call> mouse_button_one_listeners;
public:
    Mouse();
    void update();
    bool IsButtonUp(int button);
    bool IsButtonDown(int button);
private:
    std::unordered_map<int, func_call> mouse_button_two_listeners;
    int sequence_one;
    int sequence_two;
};


#endif //ANAVA_T_THREE_MOUSE_H
