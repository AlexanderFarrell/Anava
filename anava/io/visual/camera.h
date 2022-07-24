//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_CAMERA_H
#define ANAVA_T_THREE_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../universe/states/location.h"
#include "../../universe/noun.h"

class Camera: public Noun::State {
public:
    Location location;
    glm::mat4 matrix;
    glm::mat4 view_matrix;
    glm::mat4 projection_matrix;

public:
    Camera();
    ~Camera();
    void Update();
private:
    void UpdateView();
protected:
    virtual void UpdateProjection();
};

#endif //ANAVA_T_THREE_CAMERA_H
