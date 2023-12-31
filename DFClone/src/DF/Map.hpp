//
// Created by rusla on 31.12.2023.
//

#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include "Tile.hpp"

namespace DF
{
    class Map
    {
    public:
        using Impl = std::vector<std::vector<std::vector<Tile>>>;

        explicit Map(Impl&& tiles);

    private:
        Impl tiles;
    };
} // DF

#endif //MAP_HPP
