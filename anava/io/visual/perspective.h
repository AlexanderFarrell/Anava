//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_PERSPECTIVE_H
#define ANAVA_T_THREE_PERSPECTIVE_H

#include "camera.h"

class Perspective: public Camera {
    float AspectRatio;
    float FieldOfView;
    float NearPlane;

private:
    float FarPlane;
protected:
    void UpdateProjection() override;

public:
    explicit Perspective(float aspectRatio);
    ~Perspective();
};

#endif //ANAVA_T_THREE_PERSPECTIVE_H
