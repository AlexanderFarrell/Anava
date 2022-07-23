//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_ORTHOGRAPHIC_H
#define ANAVA_T_THREE_ORTHOGRAPHIC_H

#include "camera.h"

class Orthographic: public Camera {
    float left;
    float right;
    float top;
    float bottom;
protected:
    void UpdateProjection() override;

private:
    float near_plane;
    float far_plane;

public:
    Orthographic(float width, float height);
    ~Orthographic();
};

#endif //ANAVA_T_THREE_ORTHOGRAPHIC_H
