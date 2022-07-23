//
// Created by Alexander Farrell on 7/18/22.
//

#ifndef ANAVA_T_THREE_PROGRESSION_H
#define ANAVA_T_THREE_PROGRESSION_H

#include "noun.h"

class Progression {
public:
    Progression* previous;
    Progression* next;

    Noun::State* subject;
    Noun* valence;
    void (*on_call)(Noun::State*, Noun*);

    explicit Progression(void (*on_call)(Noun::State*, Noun*));
    Progression(Noun::State* subject, void (*on_call)(Noun::State*, Noun*));
    Progression(Noun::State* subject, void (*on_call)(Noun::State*, Noun*), Noun* valence);
//    Progression(Noun *valence, void (*on_call)(Noun *));

    ~Progression();
};

#include <string>
#include "noun.h"

#endif //ANAVA_T_THREE_PROGRESSION_H
