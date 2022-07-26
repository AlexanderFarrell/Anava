# Overview

Main source folder for Anava. Contains the source for App, Engine and the CMakeLists.txt file. 

To get started with Anava, include the "anava.h" header, create a Game instance, and call run_game()!

## Navigation

| Item                               | Description                                                           |
|------------------------------------|-----------------------------------------------------------------------|
| [app](./app)                       | Runs a game using an engine.                                          |
| [io](./io)                         | Bridge between the player and universe.                               |
| [player](./player)                 | The player and their device.                                          |
| [universe](./universe)             | The game environment.                                                 |
| [util](./util)                     | Helpers, such as physics, data, time, creation, etc.                  |
| [anava.h](./anava.h)               | The main entry header for anava. Include for convenient use of anava. |
| [engine.h](./engine.h)             | Contains the engine components.                                       |
| [CMakeLists.txt](./CMakeLists.txt) | Reference in CMake to compile the engine with a project.              |

## Requirements

- [x] Contain CMakeLists.txt for compiling with other projects.
- [ ] Dependencies properly accessible for distribution.
- [x] Contain an App, which runs a game and creates an engine to run the game.
- [x] Engine components Player, IO and Universe available.
- [x] Engine brought together in engine class.
- [x] Easy include header named "anava.h"
- [x] Easy function for running a game.

## Purpose

This folder provides the core structure for Anava.

## Specific Details

None