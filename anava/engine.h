//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_ENGINE_H
#define ANAVA_T_THREE_ENGINE_H

#include "player/player.h"
#include "universe/universe.h"
#include "util/data/date_time.h"
#include "util/data/random/random.h"
#include "io/io.h"

// Runs a game. Provides a game world, input, output (visuals, audio), and a representation of the player.
class Engine {
public:
    // Represents the player, their window and runtime environment.
    Player * player;

    // Represents the game universe.
    Universe * universe;

    // Bridges the player and universe.
    IO* io;

    // Creates a new game engine instance given an application app_name.
    explicit Engine(const std::string& app_name);

    // Breaks down the engine
    ~Engine();

    // Main game loop update
    void update(long * last);
};

#endif //ANAVA_T_THREE_ENGINE_H
