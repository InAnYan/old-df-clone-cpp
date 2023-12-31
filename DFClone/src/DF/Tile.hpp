//
// Created by rusla on 30.12.2023.
//

#ifndef TILE_HPP
#define TILE_HPP

#include <cstdint>

namespace DF
{
    class Tile
    {
    public:
        explicit Tile(uint8_t id);

        [[nodiscard]] uint8_t GetId() const;

    private:
        uint8_t id;
    };
} // DF

#endif //TILE_HPP
