//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_DRAWABLE_H
#define ANAVA_T_THREE_DRAWABLE_H

#include "camera.h"
#include "material.h"
#include "mesh.h"
#include "../../universe/noun.h"

class Drawable: public Noun::State {
public:
    Drawable* previous;
    Drawable* next;

    Mesh* mesh;
    Material* material;
    Camera* camera;

    GLenum blend;
    GLenum src;

    bool isVisible;

private:
    UniformMat4* locUniform;
    Location* location;
public:
    Drawable();
    Drawable(Mesh *mesh, Material *material, Camera *camera);

    void Begin() override;
    void End() override;

    ~Drawable();
    void draw();
    void remove();
};


#endif //ANAVA_T_THREE_DRAWABLE_H
