//
// Created by rusla on 31.12.2023.
//

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <memory>
#include <SDL2/SDL.h>

#include "Point.hpp"

namespace Framework
{
    class Texture
    {
    public:
        explicit Texture(SDL_Surface* impl);
        ~Texture();

        [[nodiscard]] const Point& GetSize() const;

        /// The image should be in png.
        static std::unique_ptr<Texture> FromFile(const std::string& path);

        [[nodiscard]] const SDL_Surface* GetImpl() const;

    private:
        SDL_Surface* impl;
        Point size;
    };
}


#endif //TEXTURE_HPP
