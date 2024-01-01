//
// Created by rusla on 30.12.2023.
//

#ifndef WORLD_HPP
#define WORLD_HPP

#include <memory>

#include "Camera.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include "Object.hpp"
#include "ResourceManager.hpp"

#include "../Framework/Window.hpp"

namespace DF
{
    class World
    {
    public:
        void Draw(Framework::Window& window, const Camera& camera, const ResourceManager& resourceManager,
                  int           z) const;

        static World CreateFirstDebug();

    private:
        World(Map&&                                  map, std::vector<std::unique_ptr<Object>>&& objects,
              std::vector<std::unique_ptr<Entity>>&& entities);

        Map                                  map;
        std::vector<std::unique_ptr<Object>> objects;
        std::vector<std::unique_ptr<Entity>> entities;
    };
} // DF

#endif //WORLD_HPP
