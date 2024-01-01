//
// Created by rusla on 31.12.2023.
//

#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include "TileSet.hpp"

namespace DF
{
    class ResourceManager
    {
    public:
        static ResourceManager CreateFirstDebug();

        [[nodiscard]] const TileSet& GetTileSet() const;

    private:
        explicit ResourceManager(TileSet&& tileSet);

        TileSet tileSet;
    };
} // DF

#endif //RESOURCEMANAGER_HPP
