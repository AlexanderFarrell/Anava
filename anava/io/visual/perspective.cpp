//
// Created by Alexander Farrell on 6/18/22.
//

#include "perspective.h"

Perspective::Perspective(float aspectRatio) {
    this->AspectRatio = aspectRatio;
    this->FieldOfView = 45.0f;
    this->NearPlane = 0.1f;
    this->FarPlane = 100.0f;
    this->location.position = glm::vec3(0.0f, 0.0f, -2.0f);
//    SetXYZ(this->location.position, 0.0f, 0.0f, -2.0f);
    Update();
}

Perspective::~Perspective() {

}

void Perspective::UpdateProjection() {
    this->projection_matrix = glm::perspective(this->FieldOfView,
                     this->AspectRatio,
                     this->NearPlane,
                     this->FarPlane);
//    glm_perspective(this->FieldOfView,
//                    this->AspectRatio,
//                    this->NearPlane,
//                    this->FarPlane,
//                    this->projection_matrix);
}