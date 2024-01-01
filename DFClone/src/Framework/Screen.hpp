//
// Created by rusla on 31.12.2023.
//

#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "Event.hpp"

namespace Framework
{
    class Window;

    class Screen
    {
    public:
        virtual ~Screen() = default;

        virtual void ProcessEvent(const Event& event) = 0;
        virtual void Update() = 0;
        virtual void Draw(Window& window) const = 0;
    };
} // Framework

#endif //SCREEN_HPP
