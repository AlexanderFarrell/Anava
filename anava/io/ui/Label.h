//
// Created by Alexander Farrell on 7/11/22.
//

#ifndef ANAVA_T_THREE_LABEL_H
#define ANAVA_T_THREE_LABEL_H


#include "../../universe/noun.h"

class Label: public Noun::State {
public:
    Label();
    ~Label();
    void Begin() override;
    void End() override;

//    void SetText(std::string text);
};


#endif //ANAVA_T_THREE_LABEL_H
