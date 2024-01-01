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

        void DrawTile(Framework::Window& window, uint8_t id, const Framework::Rect& dstRect) const;

        [[nodiscard]] const Framework::Point& GetTileSize() const;

    private:
        TileSet(std::unique_ptr<Framework::Texture>&& tilesTexture, Framework::Point tilesCount,
                std::vector<TileInfo>&&               tiles);

        std::unique_ptr<Framework::Texture> tilesTexture;
        const Framework::Point              tilesCount;
        Framework::Point                    tileSize;
        std::vector<TileInfo>               tiles;
    };
} // DF

#endif //TILESET_HPP
