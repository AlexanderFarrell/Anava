//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_UNIVERSE_H
#define ANAVA_T_THREE_UNIVERSE_H

#include <set>
#include "world.h"


class Universe {
private:
    std::set<World*> worlds;
public:
    World* focused;
    Universe();
    ~Universe();

    void update();
    void add_world(World* world);
    void remove_world(World* world);
};


#endif //ANAVA_T_THREE_UNIVERSE_H
