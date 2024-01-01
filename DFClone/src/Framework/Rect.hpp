//
// Created by rusla on 01.01.2024.
//

#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL_rect.h>

#include "Point.hpp"

namespace Framework
{
    template<typename T>
    struct Rect
    {
        T x;
        T y;
        T w;
        T h;

        Rect(T x, T y, T w, T h);
        Rect(const Point<T>& pos, const Point<T>& size);

        /// Using static_cast<int>.
        [[nodiscard]] SDL_Rect ToSDL() const;
    };

    template<typename T>
    Rect<T>::Rect(T x, T y, T w, T h)
        : x(x), y(y), w(w), h(h)
    {

    }

    template<typename T>
    Rect<T>::Rect(const Point<T>& pos, const Point<T>& size)
        : x(pos.x), y(pos.y), w(size.x), h(size.y)
    {

    }

    template<typename T>
    [[nodiscard]] SDL_Rect Rect<T>::ToSDL() const
    {
        return {static_cast<int>(x), static_cast<int>(y), static_cast<int>(w), static_cast<int>(h)};
    }
}

#endif //RECT_HPP
