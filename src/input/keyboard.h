//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_KEYBOARD_H
#define ANAVA_T_THREE_KEYBOARD_H

//Numbers from https://www.freepascal-meets-sdl.net/sdl-2-0-scancode-lookup-table/
#define MAX_KEYBOARD_KEYS 283

class Keyboard {
public:
    void update();
    bool IsKeyDown(int scancode);
    bool IsKeyUp(int scancode);
    int key_state[MAX_KEYBOARD_KEYS];
    int last_update_by_key[MAX_KEYBOARD_KEYS];
    int step;
};


#endif //ANAVA_T_THREE_KEYBOARD_H
