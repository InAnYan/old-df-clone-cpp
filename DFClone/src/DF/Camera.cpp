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
            int dx = event.motion.xrel * settings.GetMouseSensitivity();
            int dy = event.motion.yrel * settings.GetMouseSensitivity();
            position += {dx, dy};
        }
        else if (event.type == SDL_MOUSEWHEEL)
        {
            zoom += event.wheel.y * settings.GetZoomFactor();
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

    const Framework::Point<int>& Camera::GetPosition() const
    {
        return position;
    }

    float Camera::GetZoom() const
    {
        return zoom;
    }
} // DF
