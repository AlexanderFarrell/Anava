//
// Created by Alexander Farrell on 6/18/22.
//

#include "drawable.h"
#include "error.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Drawable::Drawable(Mesh *mesh,
                   Material *material,
                   Camera *camera) :
               mesh(mesh),
               camera(camera) {
    this->previous = nullptr;
    this->next = nullptr;
    this->material = material;
    this->blend = GL_ONE_MINUS_SRC_ALPHA;
    this->src = GL_SRC_ALPHA;
    this->isVisible = true;
//    printf("\n");
//    printf("Camera Obj: %d\n", &this->camera);
//    printf("Loc Obj: %d\n", &this->location);
//    printf("Camera: %d\n", &this->camera->matrix);
//    printf("Loc: %d\n", &this->location->matrix);
//    printf("Dest: %d\n", &this->locUniform->data);
//    printf("Mat: %d\n", &this->material);
    auto u = (Uniform*)new UniformMat4("mvp");
//    printf("Hello\n");
    this->locUniform = (UniformMat4*)material->add_uniform(u);
//    printf("Hello\n");
}

Drawable::Drawable() {
    this->previous = nullptr;
    this->next = nullptr;
    this->location = nullptr;
    this->material = nullptr;
    this->mesh = nullptr;
    this->camera = nullptr;
    this->isVisible = false;
}

Drawable::~Drawable() {
}

void Drawable::draw() {
    this->location->refresh();
    glBlendFunc(GL_SRC_ALPHA, this->blend);
    glm::mat4 pMat4 = this->camera->matrix * this->location->matrix;
//    glm::mat4 pMat4 = this->camera->projection_matrix * this->camera->view_matrix * this->location->matrix;
    const auto *pSource = (const float*)glm::value_ptr(pMat4);
    for (int i = 0; i < 16; ++i) {
        this->locUniform->data[i] = pSource[i];
    }
//    std::cout << "Location Matrix\n";
//    display_matrix(this->location->matrix);
//    std::cout << "Camera Matrix\n";
//    display_matrix(this->camera->matrix);
//    std::cout << "Drawable Matrix\n";
//    display_matrix(pMat4);
//    glm_mat4_mul(
//            this->camera->matrix,
//            this->location->matrix,
//            (vec4*)this->locUniform->data
//            );
//    glm_mat4_mul(
//            this->location->matrix,
//            this->camera->view_matrix,
//            (vec4*)this->locUniform->data
//            );
//    glm_mat4_mul(
//            (vec4*)this->locUniform->data,
//            (vec4*)this->camera->projection_matrix,
//            (vec4*)this->locUniform->data
//            );

    this->material->prepare();
    check_for_errors_gl(400);
    this->mesh->draw();
    check_for_errors_gl(5000);

//    std::cout << "Model Matrix\n";
//    display_matrix4((float*) this->location->matrix);
}

void Drawable::remove() {
    if (this->next != nullptr) {
        this->next->previous = this->previous;
    }
    if (this->previous != nullptr) {
        this->previous->next = this->next;
    }
    this->next = nullptr;
    this->previous = nullptr;
}

void Drawable::Begin() {
    this->location = this->noun->get_state<Location>();
}

void Drawable::End() {
    State::End();
    this->remove();
}
