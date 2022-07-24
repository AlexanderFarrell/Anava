//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_LOCATION_H
#define ANAVA_T_THREE_LOCATION_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include "../noun.h"

class Location: public Noun::State {
public:
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;
    glm::mat4 matrix;

    glm::mat4 identity;
    glm::mat4 transMat;
    glm::mat4 rotMat;

    Location();
    ~Location();

    void refresh();
};


#endif //ANAVA_T_THREE_LOCATION_H
