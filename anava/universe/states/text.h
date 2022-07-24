//
// Created by Alexander Farrell on 7/4/22.
//

#ifndef ANAVA_T_THREE_TEXT_H
#define ANAVA_T_THREE_TEXT_H

#include "../noun.h"

class Text: public Noun::State {
public:
    void Begin() override;
};


#endif //ANAVA_T_THREE_TEXT_H
