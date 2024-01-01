//
// Created by rusla on 31.12.2023.
//

#include "TileSet.hpp"

namespace DF
{
    TileSet::TileSet(std::unique_ptr<Framework::Texture>&& tilesTexture, Framework::Point tilesCount,
                     std::vector<TileInfo>&&               tiles)
        : tilesTexture(std::move(tilesTexture)), tilesCount(tilesCount), tileSize(this->tilesTexture->GetSize() / tilesCount), tiles(std::move(tiles))
    {
    }

    TileSet TileSet::CreateFirstDebug()
    {
        std::unique_ptr<Framework::Texture> tilesTexture = Framework::Texture::FromFile("res/debug_tileset.png");
        Framework::Point tilesCount(20, 9);
        std::vector<TileInfo>      tiles      = {{{5, 0}, false},  {{0, 2}, true}, {{1, 2}, false}};

        return {std::move(tilesTexture), tilesCount, std::move(tiles)};
    }

    void TileSet::DrawTile(Framework::Window& window, uint8_t id, const Framework::Rect& dstRect) const
    {
        window.DrawTexture(*tilesTexture, tiles[id].coords.ToTileRect(tileSize), dstRect);
    }

    const Framework::Point& TileSet::GetTileSize() const
    {
        return tileSize;
    }
} // DF
