cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

find_package(Boost 1.74 COMPONENTS  REQUIRED)

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
        src/DF/ResourceManager.hpp
        src/Framework/Point.hpp
        src/DF/TileSet.cpp
        src/DF/TileSet.hpp
        src/Framework/PictureType.hpp
        src/Framework/File.cpp
        src/Framework/Rect.hpp
        src/Framework/Rect.cpp
        src/Framework/Point.cpp
        src/DF/Settings.cpp
        src/DF/Settings.hpp)
target_include_directories(DFClone PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})
target_link_libraries(DFClone PRIVATE ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${Boost_LIBRARIES})
