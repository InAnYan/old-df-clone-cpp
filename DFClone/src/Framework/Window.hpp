//
// Created by rusla on 31.12.2023.
//

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>

#include "Point.hpp"
#include "Screen.hpp"
#include "Texture.hpp"
#include "WindowConfiguration.hpp"
#include "Rect.hpp"

namespace Framework
{
    class Window
    {
    public:
        explicit Window(const WindowConfiguration& conf);
        ~Window();

        void SetScreen(std::unique_ptr<Screen> newScreen);

        void MainLoop();

        void DrawTexture(const Texture& src, const Rect& srcRect, const Rect& dstRect);

        [[nodiscard]] Point GetSize() const;

    private:
        const WindowConfiguration conf;
        std::unique_ptr<Screen>   currentScreen = nullptr;

        SDL_Window* sdlWindow;
        SDL_Renderer* sdlRenderer;
        SDL_Surface* screenSurface;
    };
} // Framework

#endif //WINDOW_HPP
