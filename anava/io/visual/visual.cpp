//
// Created by Alexander Farrell on 6/18/22.
//

#include "visual.h"
#include "../../util/data/random/random.h"
#include <iostream>

//#define DEBUG_VISUAL 1
#define GL_MAJOR_VERSION_DEFAULT 3
#define GL_MINOR_VERSION_DEFAULT 3

Visual::Visual(Window* window) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,
                        GL_MAJOR_VERSION_DEFAULT);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,
                        GL_MINOR_VERSION_DEFAULT);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    this->context = SDL_GL_CreateContext(window->sdl_window);
    this->ClearColor.r = rand_float(0.0f, 0.5f);
    this->ClearColor.g = rand_float(0.0f, 0.5f);
    this->ClearColor.b = rand_float(0.0f, 0.5f);
    this->ClearColor.a = rand_float(0.0f, 0.5f);

    if (!this->context) {
        printf("ERROR: Failed to initialize visual output.\n");
        exit(1);
    }

//    this->shader_texture_unlit = Shader::from_files("texture_unlit");
//    this->shader_text = Shader::from_files("text");

    this->head = new Drawable();
    this->tail = this->head;
}

Visual::~Visual() {
    SDL_GL_DeleteContext(this->context);
}

void Visual::update(Window* window) {
    glViewport(0, 0, window->getWidth(), window->getHeight());
    glClearColor(this->ClearColor.r,
                 this->ClearColor.g,
                 this->ClearColor.b,
                 this->ClearColor.a);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);

#ifdef DEBUG_VISUAL
    int drawable_count = 0;
#endif
    if (this->head->next != nullptr) {
        for (Drawable* d = this->head->next; d != nullptr; d = d->next) {
#ifdef DEBUG_VISUAL
            drawable_count++;
#endif
            d->draw();
        }
    }
#ifdef DEBUG_VISUAL
    std::cout << "Drawable Count: " << drawable_count << "\n";
#endif

    glFlush();
    SDL_GL_SwapWindow(window->sdl_window);
}

void Visual::add_drawable(Drawable *drawable) {
    if (this->tail == nullptr) {
        this->head = drawable;
        this->tail = drawable;
    } else {
        this->tail->next = drawable;
        drawable->previous = this->tail;
        drawable->next = nullptr; //Extra safety in case it isn't already null.
        this->tail = drawable;
    }
}

void Visual::remove_drawable(Drawable *drawable) {
    drawable->remove();
}
