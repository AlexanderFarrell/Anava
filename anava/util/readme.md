# Overview

Util contains helpers, such as physics, data, time, creation, etc. They are smaller appendages to the engine.

## Navigation

| Item                   | Description                                                |
|------------------------|------------------------------------------------------------|
| [assets](./assets)     | Manages assets such as images, sounds, models, etc.        |
| [creation](./creation) | Creates game content                                       |
| [data](./data)         | Data structures, such as pools, date times and type maps   |
| [econ](./econ)         | Economic gameplay mechanics                                |
| [math](./math)         | Extended math library outside glm                          |
| [sci](./sci)           | Scientific gameplay mechanics and helpers, such as physics |
| [defs.h](./defs.h)     | Generic type definitions and macros                        |

## Requirements

- [x] Utilities will not be a component of the game engine.
- [x] Ancillary gameplay mechanics and systems will be placed in utilities. 

## Purpose

Games are highly complex. Utilities provide extensions for the myriad of smaller things, such as providing support for dates, physics, asset management, procedural generation, etc. 

## Specific Details

None