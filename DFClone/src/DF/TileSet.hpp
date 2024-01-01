//
// Created by rusla on 31.12.2023.
//

#ifndef TILESET_HPP
#define TILESET_HPP

#include <memory>
#include <vector>

#include "../Framework/Texture.hpp"
#include "../Framework/Rect.hpp"
#include "../Framework/Window.hpp"

#include "TileInfo.hpp"

namespace DF
{
    class TileSet
    {
    public:
        static TileSet CreateFirstDebug();

        [[nodiscard]] Framework::Point<int> IdToCoord(uint8_t id) const;

        void DrawTile(Framework::Window& window, uint8_t id, const Framework::Rect<int>& dstRect) const;

        [[nodiscard]] const Framework::Point<int>& GetTileSize() const;

    private:
        TileSet(std::unique_ptr<Framework::Texture>&& tilesTexture, Framework::Point<int> tilesCount,
                std::vector<TileInfo>&&               tilesInfo);

        std::unique_ptr<Framework::Texture> tilesTexture;
        const Framework::Point<int>         tilesCount;
        const Framework::Point<int>         tileSize;
        std::vector<TileInfo>               tilesInfo;
    };
} // DF

#endif //TILESET_HPP
