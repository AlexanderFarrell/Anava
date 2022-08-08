//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_WINDOW_H
#define ANAVA_T_THREE_WINDOW_H

#include "SDL2/SDL.h"
#include <string>

#define WINDOW_WIDTH_DEFAULT 1280
#define WINDOW_HEIGHT_DEFAULT 720

enum FullscreenState {
    Fullscreen,
    Windowed
};


class Window {
private:
    int width;
    int height;
    FullscreenState fullscreen_state;

public:
    Window(const std::string& name);
    ~Window();

    int getWidth() const;

    int getHeight() const;

    FullscreenState getFullscreenState() const;
    void set_fullscreen_state(FullscreenState state);

    void on_resize(SDL_WindowEvent* event);

    SDL_Window* sdl_window;
};


#endif //ANAVA_T_THREE_WINDOW_H
