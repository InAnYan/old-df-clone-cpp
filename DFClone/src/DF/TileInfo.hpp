//
// Created by rusla on 30.12.2023.
//

#ifndef TILEINFO_HPP
#define TILEINFO_HPP

#include "../Framework/Point.hpp"

namespace DF
{
    struct TileInfo
    {
        Framework::Point coords;
        bool             movable;
    };
} // DF

#endif //TILEINFO_HPP
