//
// Created by rusla on 31.12.2023.
//

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "../Framework/Window.hpp"

#include "ResourceManager.hpp"
#include "Camera.hpp"

namespace DF
{
    class Object
    {
    public:
        void Draw(Framework::Window& window, const Camera& camera, const ResourceManager& resourceManager);
    };
} // DF

#endif //OBJECT_HPP
