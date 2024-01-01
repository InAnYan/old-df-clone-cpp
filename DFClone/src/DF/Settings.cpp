//
// Created by rusla on 01.01.2024.
//

#include "Settings.hpp"

#include <algorithm>

namespace DF {
    Settings::Settings(float zoomFactor, float mouseSensitivity)
        : zoomFactor(zoomFactor), mouseSensitivity(mouseSensitivity)
    {
    }

    float Settings::GetZoomFactor() const
    {
        return zoomFactor;
    }

    float Settings::GetMouseSensitivity() const
    {
        return mouseSensitivity;
    }

    float Settings::ClampCameraZoom(float zoom) const
    {
        return std::clamp(zoom, MIN_ZOOM, MAX_ZOOM);
    }
} // DF