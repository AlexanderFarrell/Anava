//
// Created by Alexander Farrell on 7/4/22.
//

#ifndef ANAVA_T_THREE_UICREATION_H
#define ANAVA_T_THREE_UICREATION_H

#include "../../app/app.h"
#include "GeometryCreation.h"
#include "../../output/visual/orthographic.h"
#include "../../output/visual/perspective.h"

typedef void (*func_void)();

class UICreation {
public:
    static Orthographic * CreateCameraOrtho();
    static Perspective * CreateCameraPerspective();
    static Noun * CreateImage(Texture* texture,
                       float size);
    static Noun * CreateImage(Texture* texture,
                       float width,
                       float height);
    static Noun* CreateText(Font* font,
                            const std::string& text);
    static Noun* CreateButton(Font* font,
                              const std::string& text,
                              func_void on);
};


#endif //ANAVA_T_THREE_UICREATION_H
