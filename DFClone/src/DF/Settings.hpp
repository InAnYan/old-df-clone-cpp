//
// Created by rusla on 01.01.2024.
//

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

namespace DF
{
    class Settings
    {
    public:
        Settings(float zoomFactor, float mouseSensitivity);

        [[nodiscard]] float GetZoomFactor() const;
        [[nodiscard]] float GetMouseSensitivity() const;

        [[nodiscard]] float ClampCameraZoom(float zoom) const;

    private:
        float zoomFactor;
        float mouseSensitivity;

        static constexpr float MIN_ZOOM = 0.5;
        static constexpr float MAX_ZOOM = 100;
    };
} // DF

#endif //SETTINGS_HPP
