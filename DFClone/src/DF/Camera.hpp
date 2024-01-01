//
// Created by rusla on 31.12.2023.
//

#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "Settings.hpp"
#include "../Framework/Event.hpp"
#include "../Framework/Point.hpp"

namespace DF
{
    class Camera
    {
    public:
        Camera() = default;

        void ProcessEvent(const Framework::Event& event, const Settings& settings);

        [[nodiscard]] const Framework::Point& GetPosition() const;
        [[nodiscard]] float GetZoom() const;

    private:
        Framework::Point position = Framework::Point(0, 0);
        float            zoom = 1;

        // TODO: Possible source of bugs.
        bool rightButtonPressed = false;
    };
} // DF

#endif //CAMERA_HPP
