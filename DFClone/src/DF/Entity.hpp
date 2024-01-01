//
// Created by rusla on 31.12.2023.
//

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Framework/Window.hpp"

#include "ResourceManager.hpp"
#include "Camera.hpp"

namespace DF
{
    class Entity
    {
    public:
        void Draw(Framework::Window& window, const Camera& camera, const ResourceManager& resourceManager);
    };
} // DF

#endif //ENTITY_HPP
