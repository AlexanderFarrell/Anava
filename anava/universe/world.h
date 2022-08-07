//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_WORLD_H
#define ANAVA_T_THREE_WORLD_H

#include <string>
#include "progression.h"

class World {
private:
    Noun* headNoun;
public:
    bool active;
    int id;
    bool toEnd;
    World();
    explicit World(const std::string& filename);

    ~World();

    void Update();
    void Save(const std::string& filename);

    Noun * create_noun();
};


#endif //ANAVA_T_THREE_WORLD_H
