//
// Created by rusla on 30.12.2023.
//

#include "Game.hpp"

namespace DF {
    Game::Game(ResourceManager&& resourceManager, World&& world)
        : resourceManager(std::move(resourceManager)), world(std::move(world))
    {

    }

    void Game::ProcessEvent(const Framework::Event& event)
    {

    }

    void Game::Update()
    {

    }

    void Game::Draw(Framework::Window& window)
    {
        world.Draw(window, camera, resourceManager);
    }
} // DF