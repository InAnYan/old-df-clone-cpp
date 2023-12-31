cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(DFClone src/main.cpp
        src/DF/Tile.cpp
        src/DF/Tile.hpp
        src/DF/World.cpp
        src/DF/World.hpp
        src/DF/TileInfo.cpp
        src/DF/TileInfo.hpp
        src/DF/Game.cpp
        src/DF/Game.hpp
        src/Framework/Window.cpp
        src/Framework/Window.hpp
        src/Framework/Texture.cpp
        src/Framework/Texture.hpp
        src/DF/Map.cpp
        src/DF/Map.hpp
        src/Framework/Event.hpp
        src/DF/Entity.cpp
        src/DF/Entity.hpp
        src/DF/Object.cpp
        src/DF/Object.hpp
        src/Framework/Screen.hpp
        src/Framework/WindowConfiguration.hpp
        src/Framework/Error.cpp
        src/Framework/Error.hpp
        src/Framework/Global.cpp
        src/Framework/Global.hpp
        src/DF/Camera.cpp
        src/DF/Camera.hpp
        src/DF/ResourceManager.cpp
        src/DF/ResourceManager.hpp)
target_link_libraries(DFClone ${SDL2_LIBRARIES})
