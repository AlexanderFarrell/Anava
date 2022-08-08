cmake_minimum_required(VERSION 3.22)
project(Anava)

Message("Building Anava - Version 0.1.0")

Message(STATUS "FINDING OpenGL")
FIND_PACKAGE(OpenGL REQUIRED)
IF (${OpenGL_FOUND})
    Message(STATUS "OpenGL was found. ")
    #    Message(STATUS "OpenGL_INCLUDE_DIR:" ${OpenGL_INCLUDE_DIR})
    #    Message(STATUS "OpenGL_LIBRARY: " ${OpenGL_LIBRARY})
ELSE ()
    #    Message(STATUS "OpenGL_FOUND: " ${OpenGL_FOUND})
    Message(FATAL_ERROR "OpenGL NOT FOUND")
ENDIF ()

Message("")

Message(STATUS "FINDING SDL2")
FIND_PACKAGE(SDL2 REQUIRED)
IF (${SDL2_FOUND})
    Message(STATUS "SDL2 was found")
    #    Message(STATUS "SDL2_INCLUDE_DIR:" ${SDL2_INCLUDE_DIR})
    #    Message(STATUS "SDL2_LIBRARY: " ${SDL2_LIBRARY})
ELSE ()
    #    Message(STATUS "SDL2 was NOT found. " ${SDL2_FOUND})
    Message(FATAL_ERROR "SDL2 NOT FOUND")
ENDIF ()
Message("")

set(SDL_CXX_FLAGS "-L/usr/local/lib -lSDL2_image -lSDL2_mixer -lSDL2")

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS} ${SDL2_mixer_INCLUDE_DIRS} ${OpenGL_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 23)

add_library(Anava engine.cpp engine.h app/game.cpp app/game.h io/input/input.cpp util/data/date_time.h io/input/input.h util/data/array_sized.cpp util/data/array_sized.h player/player.cpp player/player.h universe/universe.cpp universe/universe.h app/game_state.cpp app/game_state.h player/window.cpp player/window.h io/input/keyboard.cpp io/input/keyboard.h io/input/mouse.cpp io/input/mouse.h io/audio/audio.cpp io/audio/audio.h io/visual/visual.cpp io/visual/visual.h io/visual/color.cpp io/visual/color.h util/data/pool.cpp util/data/pool.h io/visual/drawable.cpp io/visual/drawable.h util/data/random/random.h util/data/random/mersenne_twister.h universe/universe.cpp universe/universe.h universe/world.cpp universe/world.h io/visual/camera.cpp io/visual/camera.h io/visual/material.cpp io/visual/material.h io/visual/mesh.cpp io/visual/mesh.h io/visual/shader.cpp io/visual/shader.h io/visual/uniform.cpp io/visual/uniform.h universe/states/location.cpp universe/states/location.h util/data/swizzle.cpp util/data/swizzle.h io/visual/orthographic.cpp io/visual/orthographic.h io/visual/perspective.cpp io/visual/perspective.h anava.cpp anava.h app/app.cpp app/app.h universe/noun.cpp universe/noun.h util/data/type_map.cpp util/data/type_map.h util/assets.h io/visual/error.h io/visual/texture.cpp io/visual/texture.h util/creation/GeometryCreation.cpp util/creation/GeometryCreation.h util/creation/TextureFilters.cpp util/creation/TextureFilters.h io/visual/font.cpp io/visual/font.h util/creation/UICreation.cpp util/creation/UICreation.h universe/states/text.cpp universe/states/text.h io/audio/song.cpp io/audio/song.h io/audio/sound.cpp io/audio/sound.h io/ui/Label.cpp io/ui/Label.h io/ui/Button.cpp io/ui/Button.h util/defs.h universe/progression.cpp universe/progression.h universe/states/terrain.cpp universe/states/terrain.h io/ui/UI.cpp io/ui/UI.h io/network/network.cpp io/network/network.h io/io.cpp io/io.h  io/fs/fs.cpp io/fs/fs.h util/assets/asset.cpp util/assets/asset.h util/assets/asset_manager.cpp util/assets/asset_manager.h)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_image_LIBRARIES} ${SDL2_mixer_LIBRARIES} ${OpenGL_LIBRARY} ${SDL2_LIBRARIES} ${SDL_CXX_FLAGS} freetype glm)
#add_subdirectory(/Users/alexanderfarrell/Developer/Frameworks/cglm-master [binary_dir])
add_subdirectory(/Users/alexanderfarrell/Developer/Frameworks/glm-master glm)
add_subdirectory(/Users/alexanderfarrell/Developer/Frameworks/freetype-2.12.1 freetype)