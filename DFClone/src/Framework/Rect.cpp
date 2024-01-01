#include "Rect.hpp"

#include "Point.hpp"

namespace Framework
{
    Rect::Rect(float x, float y, float w, float h)
        : x(x), y(y), w(w), h(h)
    {
    }

    Rect::Rect(const Point& pos, const Point& size)
        : x(pos.x), y(pos.y), w(size.x), h(size.y)
    {
    }

    SDL_Rect Rect::ToSDL() const
    {
        return {static_cast<int>(x), static_cast<int>(y), static_cast<int>(w), static_cast<int>(h)};
    }
}
