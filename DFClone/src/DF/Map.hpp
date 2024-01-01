//
// Created by rusla on 31.12.2023.
//

#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include <boost/multi_array.hpp>

#include "../Framework/Window.hpp"

#include "Tile.hpp"
#include "ResourceManager.hpp"
#include "Camera.hpp"

namespace DF
{
    class Map
    {
    public:
        using Impl = boost::multi_array<Tile, 3>;

        void Draw(Framework::Window& window, const Camera& camera, const ResourceManager& resourceManager,
                  int           z) const;

        static Map CreateFirstDebug();

        [[nodiscard]] bool IsPointInWorld(const Framework::Point<int>& point, int z) const;

        [[nodiscard]] const Tile& GetTile(const Framework::Point<int>& point, int z) const;

    private:
        explicit Map(Impl&& tiles);

        Impl tiles;
    };
} // DF

#endif //MAP_HPP
