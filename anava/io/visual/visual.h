//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_VISUAL_H
#define ANAVA_T_THREE_VISUAL_H

#include "SDL2/SDL.h"
#include "OpenGL/gl3.h"
#include "color.h"
#include "drawable.h"
#include "../../util/data/pool.h"
#include "../../player/window.h"

class Visual {
private:
    SDL_GLContext context;
    Drawable* head;
    Drawable* tail;

    //Common Shaders
public:
    Color ClearColor;
    Shader* shader_texture_unlit;
    Shader* shader_text;

    Camera* camera_ui;
    Camera* camera_game_world;

    Visual(Window* window);
    ~Visual();

    void update(Window* window);
    void add_drawable(Drawable* drawable);
    void remove_drawable(Drawable* drawable);
};


#endif //ANAVA_T_THREE_VISUAL_H
