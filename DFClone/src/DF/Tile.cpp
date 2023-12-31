//
// Created by rusla on 30.12.2023.
//

#include "Tile.hpp"

namespace DF
{
    Tile::Tile(uint8_t id)
        : id(id)
    {
    }

    uint8_t Tile::GetId() const
    {
        return id;
    }
} // DF
