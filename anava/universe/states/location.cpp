//
// Created by Alexander Farrell on 6/18/22.
//

#include "location.h"

Location::Location() {
    this->position = glm::vec3(0.0f,
                               0.0f,
                               0.0);
    this->scale = glm::vec3(1.0f, 1.0f, 1.0f);
    this->rotation = glm::quat(0.0f, 0.0f, 0.0f, 1.0f);
    //SetXYZ(&this->position[0], 0.0f, 0.0f, 0.0f);
//    glm::quat::ro
//    auto a = quat(1.0f, 0.0f, 0.00f, 0.0f);
//    glm_quat_identity(this->rotation);
//    SetXYZ(this->scale, 1.0f, 1.0f, 1.0f);
    this->refresh();
}

Location::~Location() {

}

void Location::refresh() {
//    this->matrix = glm::mat4(1.0f);
    this->matrix = glm::scale(glm::mat4(1.0f), this->scale);
    this->matrix = glm::translate(this->matrix, this->position);
//    glm_mat4_identity(this->matrix);
//    for (int i = 0; i < 16; i++) {
//        ((float *)this->matrix)[i] = 1.0f;
//    }
//    glm_scale(this->matrix, scale);
//    glm_quat_rotate(this->matrix, this->rotation, this->matrix);
//    glm_translate(this->matrix, this->position);
//    glm_translate_make(this->transMat, this->position);
//    glm_mat4_mul(this->transMat, this->identity, this->matrix);
//    glm_translate((vec4 *) &this->transMat, this->position);
//    glm_mat4_mul(this->transMat, this->identity, this->matrix);
//    glm_quat_rotate(this->matrix, this->rotation, this->matrix);
}
