//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_GAME_H
#define ANAVA_T_THREE_GAME_H

#include <string>
#include "game_state.h"

// A game which can be played.
class Game {
public:
    /// The name of the game.
    std::string name;

    /// The GameState to run on start.
    GameState* start_state;

    /// Creates a new Game to play.
    /// @param name [in] The name of the game.
    /// @param start_state [in] The GameState to run on start.
    Game(std::string name, GameState *start_state);

    /// Destroys the game.
    ~Game();
};


#endif //ANAVA_T_THREE_GAME_H
