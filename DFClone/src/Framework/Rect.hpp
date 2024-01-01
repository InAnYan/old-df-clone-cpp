//
// Created by rusla on 01.01.2024.
//

#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL_rect.h>

namespace Framework
{
    struct Point;

    struct Rect
    {
        float x;
        float y;
        float w;
        float h;

        Rect(float x, float y, float w, float h);
        Rect(const Point& pos, const Point& size);

        /// Using static_cast<int>.
        [[nodiscard]] SDL_Rect ToSDL() const;
    };
}

#endif //RECT_HPP
