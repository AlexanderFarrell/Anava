//
// Created by Alexander Farrell on 6/25/22.
//

#ifndef ANAVA_T_THREE_GEOMETRYCREATION_H
#define ANAVA_T_THREE_GEOMETRYCREATION_H


#include "../../output/visual/mesh.h"
#include "../../output/visual/font.h"

class GeometryCreation {
public:
    static Mesh * CreateSquare();
    static Mesh * CreateSquare(float size);
    static Mesh * CreateRectangle(float width, float height);
    static Mesh * CreateText(Font* font, const std::string& text);
    static void UpdateText(Mesh* mesh, Font* font, std::string text);
};


#endif //ANAVA_T_THREE_GEOMETRYCREATION_H
