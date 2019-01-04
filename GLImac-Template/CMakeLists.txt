cmake_minimum_required(VERSION 2.8)

project(ProjetOGL)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules)

find_package(SDL REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/include projet/include)

set(ALL_LIBRARIES projet glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${SDL_TTF_LIBRARY})

add_subdirectory(glimac)
add_subdirectory(projet)
add_subdirectory(main)