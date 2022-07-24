//
// Created by Alexander Farrell on 6/18/22.
//

#include "camera.h"
#include "error.h"

Camera::Camera() {

}

Camera::~Camera() {

}

void Camera::Update() {
    this->UpdateView();
    this->UpdateProjection();
    this->matrix = this->projection_matrix * this->view_matrix;
//    this->matrix = this->projection_matrix * this->view_matrix;
//    glm_mat4_mul(
//            this->projection_matrix,
//            this->view_matrix,
//                 this->matrix);
}

void Camera::UpdateView() {
    glm::vec4 dirUnit = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
//    dirUnit[0] = 0.0f;
//    dirUnit[1] = 0.0f;
//    dirUnit[2] = 1.0f;
    glm::mat4 rot = glm::toMat4(this->location.rotation);
//    glm_quat_mat4(this->location.rotation, rot);
    glm::vec3 dir = glm::vec3(dirUnit * rot) + this->location.position;

//    SetXYZ((float *)&dir[0], 0.0f, 0.0f, 1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
//    SetXYZ((float *)&up[0], 0.0f, 1.0f, 0.0f);
//    glm_mat4_mulv3(rot, dirUnit, 1.0f, dirUnit);
//    glm_vec3_add(dirUnit, this->location.position, dirUnit);
//    glm_vec3_add(up, this->location.position, up);

//    glm_lookat(
//            this->location.position,
//               dir,
//               up,
//               this->view_matrix);
//    glm_lookat(
//            this->location.position,
//             dirUnit,
//             up,
//             this->view_matrix);
    this->view_matrix = glm::lookAtRH(this->location.position,
                                      dir,
                                      up);
//    glm_look_rh(this->location.position,
//             dirUnit,
//             up,
//             this->view_matrix);

//    std::cout << "Dir:\n";
//    display_arr(dirUnit, 3);
//    std::cout << "Position: \n";
//    display_arr(this->location.position, 3);
//    std::cout << "View Matrix:\n";
//    display_matrix4(reinterpret_cast<float *>(this->view_matrix));
//    std::cout << "Projection Matrix:\n";
//    display_matrix4(reinterpret_cast<float *>(this->projection_matrix));
//    std::cout << "Camera Matrix:\n";
//    display_matrix4(reinterpret_cast<float *>(this->matrix));
}

void Camera::UpdateProjection() {

}

