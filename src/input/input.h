//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_INPUT_H
#define ANAVA_T_THREE_INPUT_H


#include <SDL2/SDL.h>
#include "mouse.h"
#include "keyboard.h"

class Input {
private:
    int step;
public:
    Keyboard keyboard;
    Mouse mouse;

    Input();
    ~Input();

    void update();

    void on_key_down(SDL_KeyboardEvent* event);
    void on_key_up(SDL_KeyboardEvent* event);
    void on_mouse_move(SDL_MouseMotionEvent* event);
    void on_mouse_down(SDL_MouseButtonEvent* event);
    void on_mouse_up(SDL_MouseButtonEvent* event);
    void on_mouse_wheel(SDL_MouseWheelEvent* event);

    friend class Keyboard;
    friend class Mouse;
};


#endif //ANAVA_T_THREE_INPUT_H
