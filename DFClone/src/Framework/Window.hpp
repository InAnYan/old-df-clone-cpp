//
// Created by rusla on 31.12.2023.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>

#include "Screen.hpp"
#include "WindowConfiguration.hpp"

namespace Framework
{
    class Window
    {
    public:
        explicit Window(const WindowConfiguration& conf);
        ~Window();

        void SetScreen(std::unique_ptr<Screen> newScreen);

        void MainLoop();

    private:
        const WindowConfiguration conf;
        std::unique_ptr<Screen>   currentScreen = nullptr;

        SDL_Window* sdlWindow;
        SDL_Renderer* sdlRenderer;
    };
} // Framework

#endif //WINDOW_HPP
