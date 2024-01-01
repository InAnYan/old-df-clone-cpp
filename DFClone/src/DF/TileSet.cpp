//
// Created by rusla on 31.12.2023.
//

#include "TileSet.hpp"

namespace DF
{
    TileSet::TileSet(std::unique_ptr<Framework::Texture>&& tilesTexture, Framework::Point<int> tilesCount,
                     std::vector<TileInfo>&&               tilesInfo)
        : tilesTexture(std::move(tilesTexture)), tilesCount(tilesCount), tileSize(this->tilesTexture->GetSize() / tilesCount), tilesInfo(std::move(tilesInfo))
    {
    }

    Framework::Point<int> TileSet::IdToCoord(uint8_t id) const
    {
        return {id % tilesCount.x, id / tilesCount.x};
    }

    TileSet TileSet::CreateFirstDebug()
    {
        std::unique_ptr<Framework::Texture> tilesTexture = Framework::Texture::FromFile("res/debug_tileset_1.png");
        Framework::Point tilesCount(3, 1);
        std::vector<TileInfo>      tiles      = {{"Air", false, false},
            {"Grass", false, true},
            {"Water", false, false}};

        return {std::move(tilesTexture), tilesCount, std::move(tiles)};
    }

    void TileSet::DrawTile(Framework::Window& window, uint8_t id, const Framework::Rect<int>& dstRect) const
    {
        window.DrawTexture(*tilesTexture, Framework::Rect(IdToCoord(id) * tileSize, tileSize), dstRect);
    }

    const Framework::Point<int>& TileSet::GetTileSize() const
    {
        return tileSize;
    }
} // DF
