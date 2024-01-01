//
// Created by rusla on 30.12.2023.
//

#ifndef TILEINFO_HPP
#define TILEINFO_HPP

#include <string_view>

namespace DF
{
    struct TileInfo
    {
        std::string_view name;
        bool             constructible;
        bool             movable;
    };
} // DF

#endif //TILEINFO_HPP
