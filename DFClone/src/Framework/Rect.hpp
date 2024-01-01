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
        int x;
        int y;
        int w;
        int h;

        Rect(int x, int y, int w, int h);
        Rect(const Point& pos, const Point& size);

        [[nodiscard]] SDL_Rect ToSDL() const;
    };
}

#endif //RECT_HPP
