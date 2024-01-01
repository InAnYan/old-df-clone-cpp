//
// Created by rusla on 30.12.2023.
//

#include "Game.hpp"

namespace DF {
    Game::Game(Settings&& settings, ResourceManager&& resourceManager, World&& world, int z)
        : settings(std::move(settings)), resourceManager(std::move(resourceManager)), world(std::move(world)), z(z)
    {

    }

    void Game::ProcessEvent(const Framework::Event& event)
    {
        camera.ProcessEvent(event, settings);
    }

    void Game::Update()
    {

    }

    void Game::Draw(Framework::Window& window) const
    {
        world.Draw(window, camera, resourceManager, z);
    }

    std::unique_ptr<Game> Game::CreateFirstDebug()
    {
        ResourceManager resourceManager = ResourceManager::CreateFirstDebug();
        World world = World::CreateFirstDebug();
        Game* game = new Game(Settings(1, 1), std::move(resourceManager), std::move(world), 0);
        return std::unique_ptr<Game>(game);
    }
} // DF