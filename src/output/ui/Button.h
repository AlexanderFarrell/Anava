//
// Created by Alexander Farrell on 7/11/22.
//

#ifndef ANAVA_T_THREE_BUTTON_H
#define ANAVA_T_THREE_BUTTON_H

#include "../../universe/noun.h"
#include "../../util/defs.h"
#include "../../app/app.h"

// Calls a given function when clicked.
class Button: public Noun::State {
private:
    Progression* p;
public:
    float xSize, ySize;
    func_call on;
    Location* location;

    Button();
    explicit Button(func_call on);
    ~Button();

    void Begin() override;
    void End() override;
};


#endif //ANAVA_T_THREE_BUTTON_H
