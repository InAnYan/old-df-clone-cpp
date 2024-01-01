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
    class Game final : public Framework::Screen
    {
    public:
        void ProcessEvent(const Framework::Event& event) override;
        void Update() override;
        void Draw(Framework::Window& window) const override;

        static std::unique_ptr<Game> CreateFirstDebug();

    private:
        Game(Settings&& settings, ResourceManager&& resourceManager, World&& world, int z);

        Settings        settings;
        ResourceManager resourceManager;
        World           world;
        Camera          camera;

        int z;
    };
} // DF

#endif //GAME_HPP
