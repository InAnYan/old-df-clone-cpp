//
// Created by rusla on 31.12.2023.
//

#include "Map.hpp"

#include <cassert>

namespace DF
{
    Map::Map(Impl&& tiles)
        : tiles(std::move(tiles))
    {
    }

    void Map::Draw(Framework::Window& window, const Camera& camera, const ResourceManager& resourceManager,
                   int                z) const
    {
        const TileSet&          tileSet      = resourceManager.GetTileSet();
        const Framework::Point<int>  tileSize     = tileSet.GetTileSize() * camera.GetZoom();
        const Framework::Point<int>& visibleTiles = window.GetSize() / tileSize;
        const Framework::Point<int>  startPoint   = camera.GetPosition() / tileSize;

        for (int y = 0; y < visibleTiles.y + 1; ++y)
        {
            for (int x = 0; x < visibleTiles.x + 1; ++x)
            {
                const Framework::Point worldPoint = Framework::Point(x, y) + startPoint;

                if (!IsPointInWorld(worldPoint, z))
                {
                    continue;
                }

                Framework::Rect srcRect(Framework::Point(x, y) * tileSize, tileSize);
                tileSet.DrawTile(window, GetTile(worldPoint, z).GetId(), srcRect);
            }
        }
    }

    Map Map::CreateFirstDebug()
    {
        Impl array(boost::extents[1][3][3]);
        array[0][0][0] = Tile(2);
        array[0][0][1] = Tile(2);
        array[0][0][2] = Tile(2);
        array[0][1][0] = Tile(2);
        array[0][1][1] = Tile(1);
        array[0][1][2] = Tile(2);
        array[0][2][0] = Tile(2);
        array[0][2][1] = Tile(2);
        array[0][2][2] = Tile(2);
        return Map(std::move(array));
    }

    bool Map::IsPointInWorld(const Framework::Point<int>& point, int z) const
    {
        if (z >= tiles.size() || z < 0)
        {
            return false;
        }

        const auto& level = tiles[z];

        if (point.y >= level.size() || point.y < 0)
        {
            return false;
        }

        const auto& row = level[point.y];

        return point.x < row.size() && point.x >= 0;
    }

    const Tile& Map::GetTile(const Framework::Point<int>& point, int z) const
    {
        assert(z >= 0 && z < tiles.size());
        assert(point.y >= 0 && point.y < tiles[z].size());
        assert(point.x >= 0 && point.x < tiles[z][point.y].size());
        return tiles[z][point.y][point.x];
    }
} // DF
