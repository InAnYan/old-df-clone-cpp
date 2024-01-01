//
// Created by rusla on 31.12.2023.
//

#include "ResourceManager.hpp"

#include <cassert>

namespace DF
{
    ResourceManager::ResourceManager(TileSet&& tileSet)
        : tileSet(std::move(tileSet))
    {
    }

    ResourceManager ResourceManager::CreateFirstDebug()
    {
        return ResourceManager(TileSet::CreateFirstDebug());
    }

    const TileSet& ResourceManager::GetTileSet() const
    {
        return tileSet;
    }
} // DF
