//
// Created by rusla on 30.12.2023.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "ResourceManager.hpp"
#include "World.hpp"
#include "Camera.hpp"

#include "../Framework/Screen.hpp"

namespace DF
{
    class Game : public Framework::Screen
    {
    public:
        Game(ResourceManager&& tileManager, World&& world);

        void ProcessEvent(const Framework::Event& event) override;
        void Update() override;
        void Draw(Framework::Window& window) override;

        static std::unique_ptr<Game> CreateFirtsDebugGame();

    private:
        ResourceManager resourceManager;
        World       world;
        Camera      camera;
    };
} // DF

#endif //GAME_HPP
