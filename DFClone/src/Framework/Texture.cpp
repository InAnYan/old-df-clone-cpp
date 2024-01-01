//
// Created by rusla on 31.12.2023.
//

#include "Texture.hpp"

#include <cassert>
#include <string>
#include <SDL2/SDL_image.h>

#include "Error.hpp"

namespace Framework
{
    Texture::Texture(SDL_Surface* impl)
        : impl(impl), size{impl->w, impl->h}
    {
        assert(impl != nullptr);
    }

    Texture::~Texture()
    {
        SDL_FreeSurface(impl);
    }

    const Point& Texture::GetSize() const
    {
        return size;
    }

    std::unique_ptr<Texture> Texture::FromFile(const std::string& path)
    {
        SDL_Surface* surface = IMG_Load(path.c_str());
        if (surface == nullptr)
        {
            // TODO: What image. Pass the path.
            throw Error("could not load image", IMG_GetError());
        }

        return std::make_unique<Texture>(surface);
    }

    const SDL_Surface* Texture::GetImpl() const
    {
        return impl;
    }
}
