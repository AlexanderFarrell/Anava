//
// Created by Alexander Farrell on 6/18/22.
//

#include "orthographic.h"

Orthographic::Orthographic(float width, float height) {
    this->left = 0.0f;
    this->right = -width;
    this->top = 0.0f;
    this->bottom = height;
    this->near_plane = 1.0f;
    this->far_plane = 1000.0f;
    this->location.position = glm::vec3(0.0f, 0.0f, -2.0f);
    Update();
}

Orthographic::~Orthographic() {

}

void Orthographic::UpdateProjection() {
    this->projection_matrix = glm::ortho(this->left,
                                         this->right,
                                         this->bottom,
                                         this->top,
                                         this->near_plane,
                                         this->far_plane);
}