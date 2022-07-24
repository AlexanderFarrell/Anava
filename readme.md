# Anava

Anava is a game engine for rich, dynamic game worlds. It attempts to make game characters more intelligent, increase player agency, and make games faster to create.

Anava is currently in development.

**Version**: 0.1.0

## Navigation

| Item             | Description   |
|------------------|---------------|
| [docs](./docs)   | Documentation |
 | [anava](./anava) | Source code   |
## Overview

Using Anava, one can build game worlds with 'Nouns' and 'Verbs'. A character begins and ends actions, such as running, talking, or jumping. A character can be tired, then no longer tired. 

Allowing for 'nouns' in a game to change overtime with gameplay, instead of using a more rigid 'component' approach, allows for worlds to become more dynamic and volatile. Gameplay can become more based on events rather than systems.

Anava also builds procedural generation and layers of abstraction into the engine. This allows for faster workflows, as well as more dynamic content.

### Goals

(Todo)

### Concept

Anava seeks to simplify and optimize game logic by instancing 'verbs', which begin and end as the game runs. This is different than an ECS system, which runs pieces of an update loop on all components of a particular type.

Anava is more circumstantial, rather than systematic. A character in the game may begin walking, and then stop walking. A vehicle in a game world may be powered on, and then powered off.

### Prototyping

- Anava's concept of verb based gameplay has been demonstrated in my other game, [Ordered Energy](https://img.itch.zone/aW1hZ2UvODA1NTA2LzQ1ODI1NDEucG5n/original/nvwnb8.png), in which up to 63 AI soldiers can compete against one another in a web browser game at a time.
![Ordered Energy Screenshot](https://static.itch.io/images/loader.gif)
- Anava is a successor of the engine constructed of a prototype engine for my other project, Buried Peace. The source code can be viewed publicly [here](https://github.com/AlexanderFarrell/buried-peace-concept).
![Buried Peace Screenshot](https://github.com/AlexanderFarrell/buried-peace-concept/blob/master/Screenshots/IMG_4324.PNG?raw=true)

### Cross-platform

The following targeted platforms have run successfully in tests. More platforms may be added in the future. Platforms on this list may run.

#### By OS

- [x] MacOS x86
- [ ] MacOS ARM
- [ ] Windows x86
- [ ] Windows ARM
- [ ] Linux (Ubuntu) x86
- [ ] Linux (Ubuntu) ARM
- [ ] Linux (Debian) x86
- [ ] Linux (Debian) ARM

#### By Graphics API

- [x] OpenGL (3.3)
- [ ] Metal  (2)
- [ ] Vulkan

#### By Supported Input Device

- [x] Keyboard 
- [x] Mouse
- [ ] Game Controller
- [ ] Touch

### Simplicity

Anava seeks to be simpler in its approach to game design. Instead of a VehicleSystem checking vehicles in a scene whether they are being driven, a game developed with Anava might instance a 'Drive' verb, of which only active vehicles are being driven. This has two advantages:

- Code base naming and development is simpler
- Push based programming rather than pull is more directly encouraged. 

Instead of constantly checking on a VehicleSystem, or having a Vehicle component constantly be updated, a player can begin 'driving' a car, and then when they're done, stop 'driving' a car.  

### Optimization

The update loop in Anava is kept smaller. It updates only what needs to be updated, or what is currently active in a scene. 

In later versions, we intend to pool verbs, thus lowering any overhead of allocation and deallocation of such. This is especially useful for verbs which start and stop constantly. O(1) is intended on starting and stopping verbs.

Progressions allow for verbs to be executed at certain intervals. In future versions, progressions can be of variable rates. Some 'verbs' should not, or don't need to be updated at 60 times a second. Some maybe every second, or some maybe every 15 seconds. Some should spread out the scheduling of verbs so that the CPU stays busy, and doesn't have a massive workload on any one frame, unless the count of verbs is unnecessarily enormous.