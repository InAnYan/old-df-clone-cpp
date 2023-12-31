//
// Created by rusla on 31.12.2023.
//

#include "Window.hpp"

#include <cassert>

#include "Error.hpp"

namespace Framework
{
    Window::Window(const WindowConfiguration& conf)
        : conf(conf)
    {
        sdlWindow = SDL_CreateWindow(conf.title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, conf.width,
                                     conf.height, SDL_WINDOW_SHOWN);
        if (sdlWindow == nullptr)
        {
            throw Error("could not create the window", SDL_GetError());
        }

        sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
        if (sdlRenderer == nullptr)
        {
            throw Error("could not create the renderer", SDL_GetError());
        }
    }

    Window::~Window()
    {
        if (sdlWindow)
        {
            SDL_DestroyWindow(sdlWindow);
        }

        if (sdlRenderer)
        {
            SDL_DestroyRenderer(sdlRenderer);
        }
    }

    void Window::SetScreen(std::unique_ptr<Screen> newScreen)
    {
        currentScreen.swap(newScreen);
    }

    void Window::MainLoop()
    {
        assert(currentScreen != nullptr);

        bool running = true;
        while (running)
        {
            SDL_Event e;
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                {
                    running = false;
                }
                else
                {
                    currentScreen->ProcessEvent(e);
                }
            }

            currentScreen->Update();
            currentScreen->Draw(*this);
        }
    }
} // Framework
