# Anava

Anava is a 'verb based' game engine. Its goal is to both simplify and optimize game logic.

**Version**: 0.1.0 (In Development)

## Overview

Anava seeks to simplify and optimize game logic by instancing 'verbs', which begin and end as the game runs. This is different than an ECS system, which runs pieces of an update loop on all components of a particular type. 

Anava is more circumstantial, rather than systematic. A character in the game may begin walking, and then stop walking. A vehicle in a game world may be powered on, and then powered off.

### Goals

Anava is a successor of the engine constructed of a prototype engine for my other project, Buried Peace. The link to such can be found here. 

### Simplicity

Anava seeks to be simpler in its approach to game design. Instead of a VehicleSystem checking vehicles in a scene whether they are being driven, a game developed with Anava might instance a 'Drive' verb, of which only active vehicles are being driven. This has two advantages:

- Code base naming and development is simpler
- Push based programming rather than pull is more directly encouraged. 

Instead of constantly checking on a VehicleSystem, or having a Vehicle component constantly be updated, a player can begin 'driving' a car, and then when they're done, stop 'driving' a car.  

### Optimization

The update loop in Anava is kept smaller. It updates only what needs to be updated, or what is currently active in a scene. 

In later versions, we intend to pool verbs, thus lowering any overhead of allocation and deallocation of such. This is especially useful for verbs which start and stop constantly. O(1) is intended on starting and stopping verbs.

Progressions allow for verbs to be executed at certain intervals. In future versions, progressions can be of variable rates. Some 'verbs' should not, or don't need to be updated at 60 times a second. Some maybe every second, or some maybe every 15 seconds. Some should spread out the scheduling of verbs so that the CPU stays busy, and doesn't have a massive workload on any one frame, unless the count of verbs is unnecessarily enormous.