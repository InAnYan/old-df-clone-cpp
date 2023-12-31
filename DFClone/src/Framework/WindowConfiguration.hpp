//
// Created by rusla on 31.12.2023.
//

#ifndef WINDOWCONFIGURATION_HPP
#define WINDOWCONFIGURATION_HPP

#include <string>

namespace Framework
{
    struct WindowConfiguration
    {
        int width;
        int height;
        std::string title; // The string should be null-terminated.
    };
}

#endif //WINDOWCONFIGURATION_HPP
