//
// Created by rusla on 31.12.2023.
//

#include "Global.hpp"

#include <SDL.h>

#include "Error.hpp"

namespace Framework {
    void GlobalInit()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            throw Error("could not init SDL", SDL_GetError());
        }
    }

    void GlobalDeInit()
    {
        SDL_Quit();
    }
} // Framework