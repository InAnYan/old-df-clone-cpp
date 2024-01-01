//
// Created by rusla on 31.12.2023.
//

#include "Camera.hpp"

namespace DF
{
    void Camera::ProcessEvent(const Framework::Event& event, const Settings& settings)
    {
        // TODO: Clamp move and zoom of camera.
        // TODO: Mouse sensitivity.

        if (event.type == SDL_MOUSEMOTION && rightButtonPressed)
        {
            float dx = static_cast<float>(event.motion.xrel) * settings.GetMouseSensitivity();
            float dy = static_cast<float>(event.motion.yrel) * settings.GetMouseSensitivity();
            position += {static_cast<int>(dx), static_cast<int>(dy)};
        }
        else if (event.type == SDL_MOUSEWHEEL)
        {
            zoom += static_cast<float>(event.wheel.y) * settings.GetZoomFactor();
            zoom = settings.ClampCameraZoom(zoom);
        }
        else if (event.type == SDL_MOUSEBUTTONUP)
        {
            if (event.button.button == SDL_BUTTON_RIGHT)
            {
                rightButtonPressed = false;
            }
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_RIGHT)
            {
                rightButtonPressed = true;
            }
        }
    }

    const Framework::Point& Camera::GetPosition() const
    {
        return position;
    }

    int Camera::GetZoom() const
    {
        return zoom;
    }
} // DF
