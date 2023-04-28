cmake_minimum_required(VERSION 3.16)
project(RayLibShowcase)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckCXXSymbolExists)
check_cxx_symbol_exists(CLOCK_MONOTONIC time.h HAVE_CLOCK_MONOTONIC)
check_cxx_symbol_exists(QueryPerformanceCounter windows.h HAVE_QPC)
set(CMAKE_REQUIRED_DEFINITIONS)
add_definitions("-pthread")

file(GLOB SOURCES src/*.cpp)

add_executable(RayLibShowcase ${SOURCES} src/coin.cpp src/coin.h src/bullet.cpp src/bullet.h src/boxBullet.cpp src/boxBullet.h src/chest.cpp src/chest.h src/SceneManager.cpp src/SceneManager.h src/Scene.cpp src/Scene.h src/mainMenu.cpp src/mainMenu.h src/button.cpp src/button.h src/levelSelection.cpp src/levelSelection.h src/EndScene.cpp src/EndScene.h src/EndDoor.cpp src/EndDoor.h src/spawnPoint.cpp src/spawnPoint.h src/Saveer.cpp src/Saveer.h src/shopMenu.cpp src/shopMenu.h)
# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib-4.1 ./libs/raylib)
target_link_libraries(RayLibShowcase PUBLIC raylib)

## Building chipmunk
set(BUILD_DEMOS OFF CACHE BOOL "Chipmunk Demos" FORCE)
set(BUILD_SHARED OFF CACHE BOOL "Build and install the shared library" FORCE)
add_subdirectory(libs/chipmunkpp)
#
target_include_directories(RayLibShowcase PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/chipmunkpp/chipmunk/include/chipmunk
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_include_directories(RayLibShowcase PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/chipmunkpp/src
        ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(RayLibShowcase PUBLIC chipmunkpp)


