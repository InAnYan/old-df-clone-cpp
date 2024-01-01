#include "Rect.hpp"

#include "Point.hpp"

namespace Framework
{
    Rect::Rect(int x, int y, int w, int h)
        : x(x), y(y), w(w), h(h)
    {
    }

    Rect::Rect(const Point& pos, const Point& size)
        : x(pos.x), y(pos.y), w(size.x), h(size.y)
    {
    }

    SDL_Rect Rect::ToSDL() const
    {
        return { x, y, w, h };
    }

}