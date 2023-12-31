//
// Created by rusla on 30.12.2023.
//

#ifndef TILEINFO_HPP
#define TILEINFO_HPP

#include <memory>

#include "../Framework/Texture.hpp"

namespace DF
{
    struct TileInfo
    {
        std::unique_ptr<Framework::Texture> texture;
        bool                                movable;
    };
} // DF

#endif //TILEINFO_HPP
