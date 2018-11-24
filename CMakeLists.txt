cmake_minimum_required(VERSION 3.12)
project(projections C)

set(CMAKE_C_STANDARD 11)

add_executable(projections src/main.c src/projections.c src/projections.h src/draw.c src/draw.h src/debug.h src/rendering.c src/rendering.h src/events.c src/events.h src/processing.c src/processing.h)

include_directories(/usr/local/lib)
include_directories(/usr/local/include)
include_directories(/usr/local/Cellar)
include_directories(/Library/Frameworks)

find_package(OPENGL REQUIRED)
if (OPENGL_FOUND)
    target_include_directories(projections PRIVATE ${OPENGL_INCLUDE_DIRS})
    target_link_libraries(projections PRIVATE ${OPENGL_LIBRARIES})
endif ()

find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    target_include_directories(projections PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(projections PRIVATE ${SDL2_LIBRARIES})
endif ()