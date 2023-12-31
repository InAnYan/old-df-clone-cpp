//
// Created by rusla on 30.12.2023.
//

#include "World.hpp"

namespace DF
{
    World::World(Map&&                                  map, std::vector<std::unique_ptr<Object>>&& objects,
                 std::vector<std::unique_ptr<Entity>>&& entities)
        : map(std::move(map)), objects(std::move(objects)), entities(std::move(entities))
    {
    }

    void World::Draw(Framework::Window& window, const Camera& camera, const ResourceManager& resourceManager)
    {
        map.Draw(window, camera, resourceManager);

        for (auto entity : entities)
        {
            entity->Draw(window, camera, resourceManager);
        }

        for (auto object : objects)
        {
            object->Draw(window, camera, resourceManager);
        }
    }
} // DF
