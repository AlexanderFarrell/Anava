//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_GAME_STATE_H
#define ANAVA_T_THREE_GAME_STATE_H

#include <string>
#include "../engine.h"

/// A part of the game, such as menus, load screen, gameplay, editor, etc.
class GameState {
public:
    /// Gets the name of the GameState.
    /// \return A string representing the name.
    virtual std::string get_name();

    /// Override to perform logic when starting the game state.
    virtual void on_start(Engine * engine);

    /// Override to perform logic when ending the game state.
    virtual void on_end(Engine * engine);

    /// Creates a new game state.
    GameState();

    /// Destroys a game state.
    ~GameState();

protected:
    World* world;
};

#endif //ANAVA_T_THREE_GAME_STATE_H
