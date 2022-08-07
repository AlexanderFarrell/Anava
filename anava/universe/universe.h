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
    Progression* headProgression;
public:
    World* focused;
    Universe();
    ~Universe();

    void update();
    void add_world(World* world);
    void remove_world(World* world);

    Progression * create_progression(void (*on_call)(Noun::State*, Noun*));
    Progression * create_progression(Noun::State* subject, void (*on_call)(Noun::State*, Noun*));
    Progression * create_progression(Noun::State* subject, void (*on_call)(Noun::State*, Noun*), Noun* valence);
};


#endif //ANAVA_T_THREE_UNIVERSE_H
