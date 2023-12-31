//
// Created by rusla on 31.12.2023.
//

#include "ResourceManager.hpp"

#include <cassert>

namespace DF
{
    const TileInfo& ResourceManager::GetTileInfo(unsigned id) const
    {
        assert(id < tiles.size());
        return tiles[id];
    }
} // DF
