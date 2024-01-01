//
// Created by rusla on 31.12.2023.
//

#include "Global.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Error.hpp"

namespace Framework {
    void GlobalInit()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            throw Error("could not init SDL", SDL_GetError());
        }

        constexpr int imgFlags = IMG_INIT_PNG;
        if(!(IMG_Init(imgFlags) & imgFlags))
        {
            throw Error("could not init SDL_Image", SDL_GetError());
        }
    }

    void GlobalDeInit()
    {
        IMG_Quit();
        SDL_Quit();
    }
} // Framework