//
// Created by rusla on 31.12.2023.
//

#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <vector>

#include "TileInfo.hpp"

namespace DF {
    class ResourceManager {
public:
        explicit ResourceManager(std::vector<TileInfo>&& tiles);
        [[nodiscard]] const TileInfo& GetTileInfo(unsigned id) const;

    private:
        std::vector<TileInfo> tiles;
};

} // DF

#endif //RESOURCEMANAGER_HPP
