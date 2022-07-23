cmake_minimum_required(VERSION 3.22)
project(Anava)

Message("")

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

add_library(Anava engine.cpp engine.h app/game.cpp app/game.h input/input.cpp util/data/date_time.h input/input.h output/output.cpp output/output.h player/player.cpp player/player.h universe/universe.cpp universe/universe.h app/game_state.cpp app/game_state.h player/window.cpp player/window.h input/keyboard.cpp input/keyboard.h input/mouse.cpp input/mouse.h output/audio/audio.cpp output/audio/audio.h output/visual/visual.cpp output/visual/visual.h output/visual/color.cpp output/visual/color.h util/data/pool.cpp util/data/pool.h output/visual/drawable.cpp output/visual/drawable.h util/data/random/random.h util/data/random/mersenne_twister.h universe/universe.cpp universe/universe.h universe/world.cpp universe/world.h output/visual/camera.cpp output/visual/camera.h output/visual/material.cpp output/visual/material.h output/visual/mesh.cpp output/visual/mesh.h output/visual/shader.cpp output/visual/shader.h output/visual/uniform.cpp output/visual/uniform.h universe/states/location.cpp universe/states/location.h util/data/swizzle.cpp util/data/swizzle.h output/visual/orthographic.cpp output/visual/orthographic.h output/visual/perspective.cpp output/visual/perspective.h anava.cpp anava.h app/app.cpp app/app.h universe/noun.cpp universe/noun.h util/data/type_map.cpp util/data/type_map.h util/assets.h output/visual/error.h output/visual/texture.cpp output/visual/texture.h util/creation/GeometryCreation.cpp util/creation/GeometryCreation.h util/creation/TextureFilters.cpp util/creation/TextureFilters.h output/visual/font.cpp output/visual/font.h util/creation/UICreation.cpp util/creation/UICreation.h universe/states/text.cpp universe/states/text.h output/audio/song.cpp output/audio/song.h output/audio/sound.cpp output/audio/sound.h output/ui/Label.cpp output/ui/Label.h output/ui/Button.cpp output/ui/Button.h util/defs.h universe/progression.cpp universe/progression.h universe/states/terrain.cpp universe/states/terrain.h)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_image_LIBRARIES} ${SDL2_mixer_LIBRARIES} ${OpenGL_LIBRARY} ${SDL2_LIBRARIES} ${SDL_CXX_FLAGS} freetype glm)
#add_subdirectory(/Users/alexanderfarrell/Developer/Frameworks/cglm-master [binary_dir])
add_subdirectory(/Users/alexanderfarrell/Developer/Frameworks/glm-master [binary_dir])
add_subdirectory(/Users/alexanderfarrell/Developer/Frameworks/freetype-2.12.1 freetype)